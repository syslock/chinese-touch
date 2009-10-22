#include <math.h>
#include <sstream>
#include <nds/arm9/image.h>

#include "hanzi-trainer.h"
#include "lesson_menu.h"
#include "screen.h"
#include "error_console.h"
// compiled-in sprite data:
#include "text-x-generic.h"
#include "accessories-dictionary.h"
#include "menu_button.h"
#include "menu_button_colors.h"


int MenuEntry::BASE_HEIGHT = 32;
int MenuEntry::ACTIVE_HEIGHT = 52;
int MenuEntry::FONT_SIZE = 10;
int MenuEntry::TEXT_X_OFFSET = 50;
int MenuEntry::BUTTON_GAP = 6;

void MenuEntry::render_text( FreetypeRenderer& ft, const std::string& text )
{
	RenderStyle render_style;
	//render_style.linebreak = false;
	ft.render( *this->text_surface, text,
		ft.han_face, MenuEntry::FONT_SIZE, 0, 0, &render_style );
}


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

void tile_32x16_8bpp_sprite( u8* source_buffer, u8* dest_buffer )
{
	int dest_offset = 0;
	for( int tlin=0; tlin<2; tlin++ )
		for( int trow=0; trow<4; trow++ )
			for( int plin=0; plin<8; plin++ )
				for( int prow=0; prow<8; prow++, dest_offset++ )
				{
					int source_offset = (32*8*tlin)+(plin*4+trow)*8+prow;
					//int dest_offset = plin*8+prow+64*trow+256*tlin;
					dest_buffer[dest_offset] = source_buffer[source_offset];
				}
}

LessonMenu::LessonMenu( FreetypeRenderer& _freetype_renderer, Library& _library, Config& _config )
	: freetype_renderer(_freetype_renderer), library(_library), config(_config), 
		book_sprite_vram(0), lesson_sprite_vram(0), y_offset(5), v_y(0), active_list_id(0),
		frame_count(0), 
		shengci_text(32,16), yufa_text(32,16), kewen_text(32,16), lianxi_text(32,16), 
		shengci_sprite_vram(0), yufa_sprite_vram(0), kewen_sprite_vram(0), lianxi_sprite_vram(0),
		button_sprite_vram(0)
{
#if DEBUG
	ErrorConsole::init( SCREEN_MAIN );
#else
	this->freetype_renderer.init_screen( SCREEN_MAIN, this->info_screen );
	this->info_screen.clear();
#endif
	this->freetype_renderer.init_screen( SCREEN_SUB, this->menu_screen );
	this->menu_screen.clear();
	// Farbindex 0 der Hintergrundpalette auf hellblau für's Highlight setzen:
	this->menu_screen.palette[0] = 31<<10|28<<5|28;

	// unteren Bildschirm für Spritenutzung initialisieren:
	vramSetBankD( VRAM_D_SUB_SPRITE );
	oamInit( &oamSub, SpriteMapping_Bmp_1D_128, 0 );
	oamAllocReset( &oamSub );
	oamEnable( &oamSub );
	// vorgerenderte Spritegrafiken laden:
	this->book_sprite_vram = oamAllocateGfx( &oamSub, SpriteSize_32x32, SpriteColorFormat_Bmp );
	dmaCopy( accessories_dictionaryBitmap, this->book_sprite_vram, 32*32*2 );
	this->lesson_sprite_vram = oamAllocateGfx( &oamSub, SpriteSize_32x32, SpriteColorFormat_Bmp );
	dmaCopy( text_x_genericBitmap, this->lesson_sprite_vram, 32*32*2 );
	this->button_sprite_vram = oamAllocateGfx( &oamSub, SpriteSize_32x16, SpriteColorFormat_Bmp );
	dmaCopy( menu_buttonBitmap, this->button_sprite_vram, 32*16*2 );
	// Alpha-Bits bei definierten Spritepixeln auf "undurchsichtig" setzen:
	for( int i=0; i<32*32; i++ )
	{
		if( this->book_sprite_vram[i] )
			this->book_sprite_vram[i] |= 1<<15;
		if( this->lesson_sprite_vram[i] )
			this->lesson_sprite_vram[i] |= 1<<15;
		if( this->button_sprite_vram[i] )
			this->button_sprite_vram[i] |= 1<<15;
	}

	// Palette für 8-Bit-Sprites wie Hintergrundpalette initialisieren:
	dmaCopy( menu_button_colorsPal, SPRITE_PALETTE_SUB, 256*2 );

	// VRAM für 8-Bit-Button-Sprites reservieren:
	this->shengci_sprite_vram = oamAllocateGfx( &oamSub, SpriteSize_32x16, SpriteColorFormat_256Color );
	this->yufa_sprite_vram = oamAllocateGfx( &oamSub, SpriteSize_32x16, SpriteColorFormat_256Color );
	this->kewen_sprite_vram = oamAllocateGfx( &oamSub, SpriteSize_32x16, SpriteColorFormat_256Color );
	this->lianxi_sprite_vram = oamAllocateGfx( &oamSub, SpriteSize_32x16, SpriteColorFormat_256Color );

	// Beschriftungen für Ladeknöpfe vorrendern:
	RenderStyle render_style;
	render_style.center_x = true;
	this->freetype_renderer.render( this->shengci_text, "生词",
		this->freetype_renderer.han_face, 9, 0, 1, &render_style );
	this->freetype_renderer.render( this->yufa_text, "语法",
		this->freetype_renderer.han_face, 9, 0, 1, &render_style );
	this->freetype_renderer.render( this->kewen_text, "课文",
		this->freetype_renderer.han_face, 9, 0, 1, &render_style );
	this->freetype_renderer.render( this->lianxi_text, "练习",
		this->freetype_renderer.han_face, 9, 0, 1, &render_style );

	// FIXME: dmaCopy broken? needs VBlank? before? after? *confused*
	// Spritekonvertierung:
	// (Zwischenpufferung aus Bequemlichkeit, weil VRAM nur mit 16-bit-Wörtern beschreibbbar)
	u8 conversion_buffer[32*16];
	tile_32x16_8bpp_sprite( (u8*)(this->shengci_text.base_address), conversion_buffer );
	memcpy( this->shengci_sprite_vram, conversion_buffer, 32*16*1 );
	tile_32x16_8bpp_sprite( (u8*)(this->yufa_text.base_address), conversion_buffer );
	memcpy( this->yufa_sprite_vram, conversion_buffer, 32*16*1 );
	tile_32x16_8bpp_sprite( (u8*)(this->kewen_text.base_address), conversion_buffer );
	memcpy( this->kewen_sprite_vram, conversion_buffer, 32*16*1 );
	tile_32x16_8bpp_sprite( (u8*)(this->lianxi_text.base_address), conversion_buffer );
	memcpy( this->lianxi_sprite_vram, conversion_buffer, 32*16*1 );
	
	// Menü zur gespeicherten Position bewegen:
	std::string config_book_name = this->config.get_current_book_name();
	int config_lesson_number = this->config.get_current_lesson_number();
	if( config_book_name.length() && config_lesson_number )
	{
		bool found = false;
		// tatsächlichen Wert nur verändern, wenn wir auch was finden:
		int _y_offset = 0;
		for( Library::iterator book_it=this->library.begin();
			book_it!=this->library.end(); 
			book_it++, _y_offset-=MenuEntry::BASE_HEIGHT )
		{
			_y_offset -= MenuEntry::BASE_HEIGHT;
			for( Book::iterator lesson_it=book_it->second->begin();
				lesson_it!=book_it->second->end(); 
				lesson_it++, _y_offset-=MenuEntry::BASE_HEIGHT )
			{
				if( book_it->first == config_book_name 
					&& lesson_it->first == config_lesson_number )
				{
					found = true;
					this->active_list_id = static_cast<void*>( lesson_it->second );
					this->y_offset = _y_offset;
					// Stück zurück und leichten Impuls setzen um das Vorspulen zu verdeutlichen:
					this->y_offset+=20;
					this->v_y=-5;
					break;
				}
			}
			if( found )
			{
				/* Menüeintrag für das enthaltende Buch anlegen und ausklappen 
					(den Rest macht die Rendermethode...) */
				MenuEntry* entry = new MenuEntry();
				entry->book = book_it->second;
				entry->exploded = true;
				this->menu_list[ static_cast<void*>(entry->book) ] = entry;
				entry->render_text( this->freetype_renderer, entry->book->title );
				break;
			}
		}
	}
}

LessonMenu::~LessonMenu()
{
	oamFreeGfx( &oamSub, this->book_sprite_vram );
	oamFreeGfx( &oamSub, this->lesson_sprite_vram );
	oamFreeGfx( &oamSub, this->shengci_sprite_vram );
	oamFreeGfx( &oamSub, this->yufa_sprite_vram );
	oamFreeGfx( &oamSub, this->kewen_sprite_vram );
	oamFreeGfx( &oamSub, this->lianxi_sprite_vram );
	oamFreeGfx( &oamSub, this->book_sprite_vram );
}

void LessonMenu::render( Screen screen )
{
	this->frame_count++;
	if( screen == SCREEN_MAIN )
	{
#if !DEBUG
		this->info_screen.clear();
		RenderStyle render_style;
		this->freetype_renderer.render( this->info_screen, "你好Main！", 
			this->freetype_renderer.han_face, 12, 0, 0, &render_style );
#endif
	}
	else if( screen == SCREEN_SUB )
	{
		oamClear( &oamSub, 0, 0 );
		int top = this->y_offset;
		int oam_entry = 0;
		for( Library::iterator book_it = this->library.begin(); 
			book_it != this->library.end() && top < this->menu_screen.res_y; 
			book_it++ )
		{
			void* book_id = static_cast<void*>( book_it->second );
			if( top > -MenuEntry::ACTIVE_HEIGHT )
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
				MenuEntry* entry;
				if( this->menu_list.count( book_id ) )
				{
					entry = this->menu_list[ book_id ];
				}
				else
				{
					entry = new MenuEntry();
					entry->book = book_it->second;
					this->menu_list[ book_id ] = entry;
					entry->render_text( this->freetype_renderer, book_it->second->title );
				}
				entry->top = top;
				entry->last_frame_rendered = this->frame_count;
			}
			top += MenuEntry::BASE_HEIGHT;
			if( this->menu_list[book_id]->exploded )
			{
				for( Book::iterator lesson_it = book_it->second->begin();
					lesson_it != book_it->second->end() && top < this->menu_screen.res_y; 
					lesson_it++ )
				{
					void* lesson_id = static_cast<void*>( lesson_it->second );
					MenuEntry* entry = 0;
					if( top > -MenuEntry::ACTIVE_HEIGHT )
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
						if( this->menu_list.count( lesson_id ) )
						{
							entry = this->menu_list[ lesson_id ];
						}
						else
						{
							entry = new MenuEntry();
							entry->lesson = lesson_it->second;
							this->menu_list[ lesson_id ] = entry;
							entry->render_text( this->freetype_renderer, lesson_it->second->title );
						}
						entry->top = top;
						entry->last_frame_rendered = this->frame_count;
					}
					if( entry && entry->lesson && (lesson_id == this->active_list_id) )
					{
						if( top > -MenuEntry::ACTIVE_HEIGHT )
						{
							oamSet( &oamSub, oam_entry++,
									MenuEntry::TEXT_X_OFFSET+(32+MenuEntry::BUTTON_GAP)*0, top+MenuEntry::BASE_HEIGHT+2, 	// position
									1, 1, SpriteSize_32x16, SpriteColorFormat_Bmp, this->button_sprite_vram,
									0, 0, 0, 0, 0, 0 );
							oamSet( &oamSub, oam_entry++,
									MenuEntry::TEXT_X_OFFSET+(32+MenuEntry::BUTTON_GAP)*0, top+MenuEntry::BASE_HEIGHT+2, 	// position
									0, 0, SpriteSize_32x16, SpriteColorFormat_256Color, this->shengci_sprite_vram,
									0, 0, 0, 0, 0, 0 );
							oamSet( &oamSub, oam_entry++,
									MenuEntry::TEXT_X_OFFSET+(32+MenuEntry::BUTTON_GAP)*1, top+MenuEntry::BASE_HEIGHT+2, 	// position
									1, 1, SpriteSize_32x16, SpriteColorFormat_Bmp, this->button_sprite_vram,
									0, 0, 0, 0, 0, 0 );
							oamSet( &oamSub, oam_entry++,
									MenuEntry::TEXT_X_OFFSET+(32+MenuEntry::BUTTON_GAP)*1, top+MenuEntry::BASE_HEIGHT+2, 	// position
									0, 0, SpriteSize_32x16, SpriteColorFormat_256Color, this->yufa_sprite_vram,
									0, 0, 0, 0, 0, 0 );
							oamSet( &oamSub, oam_entry++,
									MenuEntry::TEXT_X_OFFSET+(32+MenuEntry::BUTTON_GAP)*2, top+MenuEntry::BASE_HEIGHT+2, 	// position
									1, 1, SpriteSize_32x16, SpriteColorFormat_Bmp, this->button_sprite_vram,
									0, 0, 0, 0, 0, 0 );
							oamSet( &oamSub, oam_entry++,
									MenuEntry::TEXT_X_OFFSET+(32+MenuEntry::BUTTON_GAP)*2, top+MenuEntry::BASE_HEIGHT+2, 	// position
									0, 0, SpriteSize_32x16, SpriteColorFormat_256Color, this->kewen_sprite_vram,
									0, 0, 0, 0, 0, 0 );
							oamSet( &oamSub, oam_entry++,
									MenuEntry::TEXT_X_OFFSET+(32+MenuEntry::BUTTON_GAP)*3, top+MenuEntry::BASE_HEIGHT+2, 	// position
									1, 1, SpriteSize_32x16, SpriteColorFormat_Bmp, this->button_sprite_vram,
									0, 0, 0, 0, 0, 0 );
							oamSet( &oamSub, oam_entry++,
									MenuEntry::TEXT_X_OFFSET+(32+MenuEntry::BUTTON_GAP)*3, top+MenuEntry::BASE_HEIGHT+2, 	// position
									0, 0, SpriteSize_32x16, SpriteColorFormat_256Color, this->lianxi_sprite_vram,
									0, 0, 0, 0, 0, 0 );
						}
						top += MenuEntry::ACTIVE_HEIGHT;
					}
					else top += MenuEntry::BASE_HEIGHT;
				}
			}
		}
		// gepufferte Bilddaten einblenden bzw. in den VRAM kopieren:
		swiWaitForVBlank();
		oamUpdate( &oamSub );
		this->menu_screen.clear( 1 );
		for( MenuList::iterator entry_it = this->menu_list.begin();
			entry_it != this->menu_list.end(); entry_it++ )
		{
			MenuEntry* entry = entry_it->second;
			if( entry->last_frame_rendered == this->frame_count )
			{
				if( entry_it->first == this->active_list_id )
				{
					int highlight_height=1;
					if( entry->book ) highlight_height = MenuEntry::BASE_HEIGHT;
					else if( entry->lesson ) highlight_height = MenuEntry::ACTIVE_HEIGHT;
					memset( this->menu_screen.base_address+this->menu_screen.res_x*(entry->top+1)/2, 
							0, 
							this->menu_screen.res_x*(highlight_height-1) );
					memset( this->menu_screen.base_address+this->menu_screen.res_x*(entry->top)/2, 
							64, 
							this->menu_screen.res_x );
					memset( this->menu_screen.base_address+this->menu_screen.res_x*(entry->top+highlight_height)/2, 
							64, 
							this->menu_screen.res_x );
				}
				entry->text_surface->render_to( this->menu_screen, MenuEntry::TEXT_X_OFFSET, entry->top );
			}
		}
	}
}

void LessonMenu::run_for_user_choice( LessonMenuChoice& choice )
{
	this->render( SCREEN_MAIN );
	this->render( SCREEN_SUB );
	touchPosition old_touch;
    touchRead( &old_touch );
	bool touched = false;
	int old_y_offset = this->y_offset;
	while( true )
	{
        scanKeys();
        touchPosition touch;
        touchRead( &touch );
        int area = touch.px * touch.z2 / touch.z1 - touch.px;
        if( keysCurrent() & KEY_TOUCH )
        {
			if( !touched ) 
			{
				touched = true;
				old_touch = touch;
				old_y_offset = this->y_offset;
			}
			int y_diff = touch.py - old_touch.py;
			if( y_diff )
			{
				this->y_offset += y_diff;
				this->v_y = y_diff;
				this->render( SCREEN_SUB );
			}
			old_touch = touch;
		}
		else if( touched && abs(abs(old_y_offset)-abs(this->y_offset)) < 2 )
		{
			touched = false;
			MenuList::iterator entry_it = this->get_entry_by_pos( old_touch.px, old_touch.py );
			if( entry_it!=this->menu_list.end() )
			{
				void* entry_id = entry_it->first;
				MenuEntry* entry = entry_it->second;
				if( entry->book )
				{
					entry->exploded = !entry->exploded;
					this->render( SCREEN_SUB );
				}
				if( entry_id == this->active_list_id )
				{
					if( entry->lesson )
					{
						choice.book = entry->lesson->book;
						choice.lesson = entry->lesson;
						choice.content_type = LessonMenuChoice::CONTENT_TYPE_NEW_WORDS;
						return;
					}
				}
				else
				{
					this->active_list_id = entry_id;
					this->render( SCREEN_SUB );
				}
			}
		}
		else if( this->v_y )
		{
			touched = false;
			int resistance = this->v_y / 4;
			if( !resistance ) resistance = this->v_y / 2;
			if( !resistance ) resistance = this->v_y;
			this->v_y -= resistance;
			this->y_offset += this->v_y;
			this->render( SCREEN_SUB );
		}
        else
        {
			touched = false;
        }
		swiWaitForVBlank();
	}
}

MenuList::iterator LessonMenu::get_entry_by_pos( int x, int y )
{
#if DEBUG
	std::cout << "get_entry_by_pos(" << x << "," << y << ")" << std::endl;
#endif
	for( MenuList::iterator entry_it = this->menu_list.begin();
		entry_it != this->menu_list.end(); 
		entry_it++ )
	{
		MenuEntry* entry = entry_it->second;
		if( entry->last_frame_rendered==this->frame_count )
		{
			int next_top;
			if( entry->lesson && entry_it->first==this->active_list_id )
				next_top = entry->top + MenuEntry::ACTIVE_HEIGHT;
			else 
				next_top = entry->top + MenuEntry::BASE_HEIGHT;
			if( y >= entry->top && y < next_top )
			{
				return entry_it;
			}
		}
	}
	return this->menu_list.end();
}