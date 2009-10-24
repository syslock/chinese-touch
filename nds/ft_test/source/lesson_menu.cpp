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
int MenuEntry::BUTTON_Y_OFFSET = MenuEntry::BASE_HEIGHT+2;
int MenuEntry::BUTTON_WIDTH = 32;
int MenuEntry::BUTTON_HEIGHT = 16;
int MenuEntry::SHENGCI_BUTTON_X_OFFSET = 0 * (MenuEntry::BUTTON_WIDTH+BUTTON_GAP) + MenuEntry::TEXT_X_OFFSET;
int MenuEntry::YUFA_BUTTON_X_OFFSET = 1 * (MenuEntry::BUTTON_WIDTH+BUTTON_GAP) + MenuEntry::TEXT_X_OFFSET;
int MenuEntry::KEWEN_BUTTON_X_OFFSET = 2 * (MenuEntry::BUTTON_WIDTH+BUTTON_GAP) + MenuEntry::TEXT_X_OFFSET;
int MenuEntry::LIANXI_BUTTON_X_OFFSET = 3 * (MenuEntry::BUTTON_WIDTH+BUTTON_GAP) + MenuEntry::TEXT_X_OFFSET;

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

/*! \brief returns content type code for clicked lesson contents button */
LessonMenuChoice::ContentType MenuEntry::get_content_type_by_pos( int x, int y )
{
	if( y>=this->top+MenuEntry::BUTTON_Y_OFFSET 
		&& y<this->top+MenuEntry::BUTTON_Y_OFFSET+MenuEntry::BUTTON_HEIGHT )
	{
		if( x>=MenuEntry::SHENGCI_BUTTON_X_OFFSET
			&& x<MenuEntry::SHENGCI_BUTTON_X_OFFSET+MenuEntry::BUTTON_WIDTH )
		{
			return LessonMenuChoice::CONTENT_TYPE_NEW_WORDS;
		}
		if( x>=MenuEntry::YUFA_BUTTON_X_OFFSET
			&& x<MenuEntry::YUFA_BUTTON_X_OFFSET+MenuEntry::BUTTON_WIDTH )
		{
			return LessonMenuChoice::CONTENT_TYPE_GRAMMAR;
		}
		if( x>=MenuEntry::KEWEN_BUTTON_X_OFFSET
			&& x<MenuEntry::KEWEN_BUTTON_X_OFFSET+MenuEntry::BUTTON_WIDTH )
		{
			return LessonMenuChoice::CONTENT_TYPE_TEXT;
		}
		if( x>=MenuEntry::LIANXI_BUTTON_X_OFFSET
			&& x<MenuEntry::LIANXI_BUTTON_X_OFFSET+MenuEntry::BUTTON_WIDTH )
		{
			return LessonMenuChoice::CONTENT_TYPE_EXERCISES;
		}
	}
	return LessonMenuChoice::CONTENT_TYPE_NONE;
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
			// geht davon aus, dass nur das selektierte Buch ausgeklappt ist:
			if( book_it->first == config_book_name )
			{
				for( Book::iterator lesson_it=book_it->second->begin();
					lesson_it!=book_it->second->end(); 
					lesson_it++, _y_offset-=MenuEntry::BASE_HEIGHT )
				{
					if( lesson_it->first == config_lesson_number )
					{
						_y_offset -= MenuEntry::BASE_HEIGHT;
						found = true;
						this->active_list_id = static_cast<void*>( lesson_it->second );
						this->y_offset = _y_offset;
						// Stück zurück und leichten Impuls setzen um das Vorspulen zu verdeutlichen:
						this->y_offset+=20;
						this->v_y=-5;
						break;
					}
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
		std::string author, title, publisher, description, stats_text;
		if( this->menu_list.count(this->active_list_id) )
		{
			MenuEntry* entry = this->menu_list[ this->active_list_id ];
			if( entry->book )
			{
				author = entry->book->author;
				title = entry->book->title;
				publisher = entry->book->publisher;
				description = entry->book->description;
				int word_count = 0;
				for( Book::iterator lesson_it = entry->book->begin();
					lesson_it != entry->book->end(); lesson_it++ )
				{
					Lesson* lesson = lesson_it->second;
					word_count += lesson->size();
				}
				std::stringstream stats_stream;
				stats_stream << "enthält " << entry->book->size() << " Lektionen und " << word_count << " Vokabeln";
				stats_text = stats_stream.str();
			}
			else if( entry->lesson )
			{
				title = entry->lesson->title;
				description = entry->lesson->description;
				std::stringstream stats_stream;
				stats_stream << "enthält " << entry->lesson->size() << " Vokabeln";
				stats_text = stats_stream.str();
			}
		}
		else
		{
			author = "Hànzì-Trainer";
			title = "汉字教练";
			publisher = "ein erweiterbares Sprachlernprogramm von Thomas Frenzel";
			description = "Lektionsauswahl: Tippe ein Buch oder eine Lektion auf dem unteren Bildschirm an!";
			std::stringstream stats_stream;
			int lesson_count = 0;
			for( Library::iterator book_it = this->library.begin();
				book_it != this->library.end(); book_it++ )
			{
				lesson_count += book_it->second->size();
			}
			stats_stream << "Es stehen " << lesson_count << " Lektionen in " << this->library.size() << " Büchern zur Auswahl." ;
			stats_text = stats_stream.str();
		}
		int top = 0;
		RenderRect rect(0,0,0,0);
		top += 3;
		if( author.length() )
		{
			RenderStyle render_style;
			render_style.center_x = true;
			rect = this->freetype_renderer.render( this->info_screen, author, 
				this->freetype_renderer.han_face, 12, 0, top, &render_style );
			top += rect.height+15;
		}
		if( title.length() )
		{
			RenderStyle render_style;
			render_style.center_x = true;
			rect = this->freetype_renderer.render( this->info_screen, title, 
				this->freetype_renderer.han_face, 16, 0, top, &render_style );
			top += rect.height+15;
		} else top += 24+15;
		if( publisher.length() )
		{
			RenderStyle render_style;
			render_style.center_x = true;
			rect = this->freetype_renderer.render( this->info_screen, publisher, 
				this->freetype_renderer.han_face, 8, 0, top, &render_style );
			top += rect.height+15;
		}
		if( description.length() )
		{
			RenderStyle render_style;
			rect = this->freetype_renderer.render( this->info_screen, description, 
				this->freetype_renderer.han_face, 10, 3, top, &render_style );
			top += rect.height+15;
		}
		if( stats_text.length() )
		{
			RenderStyle render_style;
			rect = this->freetype_renderer.render( this->info_screen, stats_text, 
				this->freetype_renderer.han_face, 8, 3, top, &render_style );
			top += rect.height+15;
		}
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
			MenuEntry* book_entry = 0;
			// book_entry holen, wenn bereits verfügbar, was bei initial ausgeklappten Büchern
			// der Fall sein sollte, wenn der Konstruktor sie bereits vorgerendert hat:
			if( this->menu_list.count( book_id ) )
			{
				book_entry = this->menu_list[ book_id ];
			}
			if( top > -MenuEntry::BASE_HEIGHT )
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
				// book_entry anlegen, falls nicht schon früher geschehen,
				// da wir ihn nun wirklich brauchen:
				if( !book_entry )
				{
					book_entry = new MenuEntry();
					book_entry->book = book_it->second;
					this->menu_list[ book_id ] = book_entry;
					book_entry->render_text( this->freetype_renderer, book_it->second->title );
				}
				book_entry->top = top;
				book_entry->last_frame_rendered = this->frame_count;
			}
			top += MenuEntry::BASE_HEIGHT;
			// Inhalte von Büchern, die nicht gerendert wurden, werden ignoriert:
			if( book_entry && book_entry->exploded )
			{
				for( Book::iterator lesson_it = book_it->second->begin();
					lesson_it != book_it->second->end() && top < this->menu_screen.res_y; 
					lesson_it++ )
				{
					void* lesson_id = static_cast<void*>( lesson_it->second );
					MenuEntry* lesson_entry = 0;
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
							lesson_entry = this->menu_list[ lesson_id ];
						}
						else
						{
							lesson_entry = new MenuEntry();
							lesson_entry->lesson = lesson_it->second;
							this->menu_list[ lesson_id ] = lesson_entry;
							lesson_entry->render_text( this->freetype_renderer, lesson_it->second->title );
						}
						lesson_entry->top = top;
						lesson_entry->last_frame_rendered = this->frame_count;
					}
					if( lesson_entry && lesson_entry->lesson && (lesson_id == this->active_list_id) )
					{
						if( top > -MenuEntry::ACTIVE_HEIGHT )
						{
							oamSet( &oamSub, oam_entry++,
									MenuEntry::SHENGCI_BUTTON_X_OFFSET, top+MenuEntry::BUTTON_Y_OFFSET, 	// position
									1, 1, SpriteSize_32x16, SpriteColorFormat_Bmp, this->button_sprite_vram,
									0, 0, 0, 0, 0, 0 );
							oamSet( &oamSub, oam_entry++,
									MenuEntry::SHENGCI_BUTTON_X_OFFSET, top+MenuEntry::BUTTON_Y_OFFSET, 	// position
									0, 0, SpriteSize_32x16, SpriteColorFormat_256Color, this->shengci_sprite_vram,
									0, 0, 0, 0, 0, 0 );
							oamSet( &oamSub, oam_entry++,
									MenuEntry::YUFA_BUTTON_X_OFFSET, top+MenuEntry::BUTTON_Y_OFFSET, 	// position
									1, 1, SpriteSize_32x16, SpriteColorFormat_Bmp, this->button_sprite_vram,
									0, 0, 0, 0, 0, 0 );
							oamSet( &oamSub, oam_entry++,
									MenuEntry::YUFA_BUTTON_X_OFFSET, top+MenuEntry::BUTTON_Y_OFFSET, 	// position
									0, 0, SpriteSize_32x16, SpriteColorFormat_256Color, this->yufa_sprite_vram,
									0, 0, 0, 0, 0, 0 );
							oamSet( &oamSub, oam_entry++,
									MenuEntry::KEWEN_BUTTON_X_OFFSET, top+MenuEntry::BUTTON_Y_OFFSET, 	// position
									1, 1, SpriteSize_32x16, SpriteColorFormat_Bmp, this->button_sprite_vram,
									0, 0, 0, 0, 0, 0 );
							oamSet( &oamSub, oam_entry++,
									MenuEntry::KEWEN_BUTTON_X_OFFSET, top+MenuEntry::BUTTON_Y_OFFSET, 	// position
									0, 0, SpriteSize_32x16, SpriteColorFormat_256Color, this->kewen_sprite_vram,
									0, 0, 0, 0, 0, 0 );
							oamSet( &oamSub, oam_entry++,
									MenuEntry::LIANXI_BUTTON_X_OFFSET, top+MenuEntry::BUTTON_Y_OFFSET, 	// position
									1, 1, SpriteSize_32x16, SpriteColorFormat_Bmp, this->button_sprite_vram,
									0, 0, 0, 0, 0, 0 );
							oamSet( &oamSub, oam_entry++,
									MenuEntry::LIANXI_BUTTON_X_OFFSET, top+MenuEntry::BUTTON_Y_OFFSET, 	// position
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
					int highlight_height=2;
					if( entry->book ) highlight_height = MenuEntry::BASE_HEIGHT;
					else if( entry->lesson ) highlight_height = MenuEntry::ACTIVE_HEIGHT;
					int render_top = entry->top;
					if( render_top<0 )
					{
						highlight_height += render_top;
						render_top = 0;
					}
					if( highlight_height >= 2 )
					{
						memset( this->menu_screen.base_address+this->menu_screen.res_x*(render_top+1)/2, 
								0, 
								this->menu_screen.res_x*(highlight_height-2) );
					}
					if( entry->top == render_top )
					{
						memset( this->menu_screen.base_address+this->menu_screen.res_x*(render_top)/2, 
								64, 
								this->menu_screen.res_x );
					}
					if( highlight_height >= 1 )
					{
						memset( this->menu_screen.base_address+this->menu_screen.res_x*(render_top+highlight_height-1)/2, 
								64, 
								this->menu_screen.res_x );
					}
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
						choice.content_type = entry->get_content_type_by_pos( old_touch.px, old_touch.py );
						if( choice.content_type )
						{
							return;
						}
						else
						{
							this->render( SCREEN_SUB );
							this->render( SCREEN_MAIN );
						}
					}
				}
				else
				{
					this->active_list_id = entry_id;
					this->render( SCREEN_SUB );
					this->render( SCREEN_MAIN );
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