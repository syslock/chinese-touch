#include <math.h>

#include "lesson_menu.h"
#include "screen.h"
// compiled-in sprite data:
#include "text-x-generic.h"
#include "accessories-dictionary.h"


MenuList::~MenuList()
{
	for( MenuList::iterator e_it=this->begin(); 
		e_it!=this->end(); e_it++ )
	{
		if( e_it->second )
		{
			delete e_it->second;
			e_it->second=0;
		}
	}
	this->clear();
}


LessonMenu::LessonMenu( FreetypeRenderer& _freetype_renderer, Library& _library )
	: freetype_renderer(_freetype_renderer), library(_library), book_sprite_vram(0), 
		lesson_sprite_vram(0), y_offset(5), v_y(0)
{
	this->freetype_renderer.init_screen( SCREEN_MAIN, this->info_screen );
	this->freetype_renderer.init_screen( SCREEN_SUB, this->menu_screen );

	//videoSetModeSub( MODE_5_2D );
	vramSetBankD( VRAM_D_SUB_SPRITE );
	oamInit( &oamSub, SpriteMapping_Bmp_1D_128, 0 );
	oamEnable( &oamSub );
	this->book_sprite_vram = oamAllocateGfx( &oamSub, SpriteSize_32x32, SpriteColorFormat_Bmp );
	dmaCopy( accessories_dictionaryBitmap, this->book_sprite_vram, 32*32*2 );
	this->lesson_sprite_vram = oamAllocateGfx( &oamSub, SpriteSize_32x32, SpriteColorFormat_Bmp );
	dmaCopy( text_x_genericBitmap, this->lesson_sprite_vram, 32*32*2 );
	// Alpha-Bits setzen, wo überhaupt was zu sehen ist:
	for( int i=0; i<32*32; i++ )
	{
		if( this->book_sprite_vram[i] )
			this->book_sprite_vram[i] |= 1<<15;
		if( this->lesson_sprite_vram[i] )
			this->lesson_sprite_vram[i] |= 1<<15;
	}
}

LessonMenu::~LessonMenu()
{
	oamFreeGfx( &oamSub, this->book_sprite_vram );
	oamFreeGfx( &oamSub, this->lesson_sprite_vram );
}

void LessonMenu::render( Screen screen )
{
	if( screen == SCREEN_MAIN )
	{
		this->info_screen.clear();
		RenderStyle render_style;
		this->freetype_renderer.render( this->info_screen, "你好Main！", 
			this->freetype_renderer.han_face, 12, 0, 0, &render_style );
	}
	else if( screen == SCREEN_SUB )
	{
		this->menu_screen.clear();
		oamClear( &oamSub, 0, 0 );
		int top = this->y_offset;
		int oam_entry = 0;
		int list_id = 1;
		for( Library::iterator book_it = this->library.begin(); 
			book_it != this->library.end() && top < 192; book_it++ )
		{
			if( top > -32 )
			{
				oamSet( &oamSub, 	// sub display
						oam_entry++,	// oam entry to set
						5, top, 	// position
						0, 			// priority
						15,			// alpha
						SpriteSize_32x32, // size
						SpriteColorFormat_Bmp, // format
						this->book_sprite_vram, // vram address
						0, 			// rotation index
						0,			// double size
						0, 			// hide
						0, 0, 		// vflip, hflip
						0			// apply mosaic
					);
				RenderScreenBuffer *surface;
				if( this->menu_list.count(list_id) )
				{
					surface = this->menu_list[list_id]->text_surface;
				}
				else
				{
					MenuEntry* entry = new MenuEntry();
					entry->book = book_it->second;
					this->menu_list[list_id] = entry;
					surface = entry->text_surface;
					RenderStyle render_style;
					RenderRect rect = this->freetype_renderer.render( *surface, book_it->second->title, 
						this->freetype_renderer.han_face, 10, 0, 0, &render_style );
				}
				surface->render_to( this->menu_screen, 50, top );
			}
			list_id++;
			top += 32;
			for( Book::iterator lesson_it = book_it->second->begin();
				lesson_it != book_it->second->end() && top < 192; lesson_it++, list_id++, top+=32 )
			{
				if( top > -32 )
				{
					oamSet( &oamSub, 	// sub display
							oam_entry++,	// oam entry to set
							5, top, 	// position
							0, 			// priority
							15,			// alpha
							SpriteSize_32x32, // size
							SpriteColorFormat_Bmp, // format
							this->lesson_sprite_vram, // vram address
							0, 			// rotation index
							0,			// double size
							0, 			// hide
							0, 0, 		// vflip, hflip
							0			// apply mosaic
						);
					RenderScreenBuffer *surface;
					if( this->menu_list.count(list_id) )
					{
						surface = this->menu_list[list_id]->text_surface;
					}
					else
					{
						MenuEntry* entry = new MenuEntry();
						entry->lesson = lesson_it->second;
						this->menu_list[list_id] = entry;
						surface = entry->text_surface;
						RenderStyle render_style;
						RenderRect rect = this->freetype_renderer.render( *surface, lesson_it->second->title, 
							this->freetype_renderer.han_face, 10, 0, 0, &render_style );
					}
					surface->render_to( this->menu_screen, 50, top );
				}
			}
		}
		swiWaitForVBlank();
		oamUpdate( &oamSub );
	}
}

void LessonMenu::run_for_user_choice( LessonMenuChoice& choice )
{
	this->render( SCREEN_MAIN );
	this->render( SCREEN_SUB );
	touchPosition old_touch;
    touchRead( &old_touch );
	bool dragged = false;
	while( true )
	{
        scanKeys();
        touchPosition touch;
        touchRead( &touch );
        int area = touch.px * touch.z2 / touch.z1 - touch.px;
        if( keysCurrent() & KEY_TOUCH 
            && (touch.px!=old_touch.px || touch.py!=old_touch.py) )
        {
			int y_diff = touch.py - old_touch.py;
			if( dragged )
			{
				this->y_offset += y_diff;
				this->v_y = y_diff;
				this->render( SCREEN_SUB );
			}
            else if( !dragged && abs(y_diff) < 5 )
			{
				MenuEntry* entry = this->get_entry_by_pos( touch.px, touch.py );
				if( entry )
				{
					if( entry->lesson )
					{
						choice.book = entry->lesson->book;
						choice.lesson = entry->lesson;
						choice.content_type = LessonMenuChoice::CONTENT_TYPE_NEW_WORDS;
						return;
					}
				}
			}
			else if( !dragged && abs(y_diff) >= 5 )
			{
				dragged = true;
				// wird bei keysUp() & KEY_TOUCH wieder auf false gesetzt
			}
			old_touch = touch;
		}
		else if( this->v_y )
		{
			int resistance = this->v_y / 4;
			if( !resistance ) resistance = this->v_y / 2;
			if( !resistance ) resistance = this->v_y;
			this->v_y -= resistance;
			this->y_offset += this->v_y;
			this->render( SCREEN_SUB );
		}
        if( keysUp() & KEY_TOUCH )
        {
            dragged = false;
        }
		swiWaitForVBlank();
	}
}

MenuEntry* LessonMenu::get_entry_by_pos( int x, int y )
{
	int id = (y-this->y_offset)/32+1;
	if( this->menu_list.count(id) ) return this->menu_list[id];
	else return 0;
}