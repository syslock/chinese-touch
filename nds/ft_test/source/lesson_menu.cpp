#include "lesson_menu.h"
#include "screen.h"
// compiled-in sprite data:
#include "text-x-generic.h"
#include "accessories-dictionary.h"

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
	for( SurfaceCache::iterator s_it=this->text_surface_cache.begin(); 
		s_it!=this->text_surface_cache.end(); s_it++ )
	{
		if( s_it->second )
		{
			delete s_it->second;
			s_it->second=0;
		}
	}
	this->text_surface_cache.clear();
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
		int menu_entry = 1;
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
				if( this->text_surface_cache.count(menu_entry) )
				{
					surface = this->text_surface_cache[menu_entry];
				}
				else
				{
					surface = new RenderScreenBuffer( 200, 32 );
					this->text_surface_cache[menu_entry] = surface;
					RenderStyle render_style;
					RenderRect rect = this->freetype_renderer.render( *surface, book_it->second->title, 
						this->freetype_renderer.han_face, 10, 0, 0, &render_style );
				}
				surface->render_to( this->menu_screen, 50, top );
			}
			menu_entry++;
			top += 32;
			for( Book::iterator lesson_it = book_it->second->begin();
				lesson_it != book_it->second->end() && top < 192; lesson_it++, menu_entry++, top+=32 )
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
					if( this->text_surface_cache.count(menu_entry) )
					{
						surface = this->text_surface_cache[menu_entry];
					}
					else
					{
						surface = new RenderScreenBuffer( 200, 32 );
						this->text_surface_cache[menu_entry] = surface;
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
			if( dragged )
			{
				int y_diff = touch.py - old_touch.py;
				this->y_offset += y_diff;
				this->v_y = y_diff;
				this->render( SCREEN_SUB );
			}
            else if( !dragged && touch.px > (this->menu_screen.res_x-15) && touch.py < 15 )
			{
				return;
			}
            dragged = true;
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
