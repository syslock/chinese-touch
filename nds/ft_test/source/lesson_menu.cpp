#include <math.h>
#include <sstream>

#include "hanzi-trainer.h"
#include "lesson_menu.h"
#include "screen.h"
#include "error_console.h"
// compiled-in sprite data:
#include "text-x-generic.h"
#include "accessories-dictionary.h"


int MenuEntry::BASE_HEIGHT = 32;
int MenuEntry::ACTIVE_HEIGHT = 50;
int MenuEntry::FONT_SIZE = 10;
int MenuEntry::TEXT_X_OFFSET = 50;

void MenuEntry::render_text( FreetypeRenderer& ft, const std::string& text )
{
	RenderStyle render_style;
	RenderRect rect = ft.render( *this->text_surface, text,
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


LessonMenu::LessonMenu( FreetypeRenderer& _freetype_renderer, Library& _library, Config& _config )
	: freetype_renderer(_freetype_renderer), library(_library), config(_config), 
		book_sprite_vram(0), lesson_sprite_vram(0), y_offset(5), v_y(0), active_list_id(0),
		frame_count(0)
{
#if DEBUG
	ErrorConsole::init( SCREEN_MAIN );
#else
	this->freetype_renderer.init_screen( SCREEN_MAIN, this->info_screen );
#endif
	this->freetype_renderer.init_screen( SCREEN_SUB, this->menu_screen );

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
		this->menu_screen.clear();
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
				entry->text_surface->render_to( this->menu_screen, MenuEntry::TEXT_X_OFFSET, top );
				entry->top = top;
				entry->last_frame_rendered = this->frame_count;
			}
			if( book_id == this->active_list_id )
				top += MenuEntry::ACTIVE_HEIGHT;
			else
				top += MenuEntry::BASE_HEIGHT;
			if( this->menu_list[book_id]->exploded )
			{
				for( Book::iterator lesson_it = book_it->second->begin();
					lesson_it != book_it->second->end() && top < this->menu_screen.res_y; 
					lesson_it++ )
				{
					void* lesson_id = static_cast<void*>( lesson_it->second );
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
						MenuEntry* entry;
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
						entry->text_surface->render_to( this->menu_screen, MenuEntry::TEXT_X_OFFSET, top );
						entry->top = top;
						entry->last_frame_rendered = this->frame_count;
					}
					if( lesson_id == this->active_list_id )
						top += MenuEntry::ACTIVE_HEIGHT;
					else
						top += MenuEntry::BASE_HEIGHT;
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
			this->y_offset += y_diff;
			this->v_y = y_diff;
			this->render( SCREEN_SUB );
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
				if( entry_id == this->active_list_id )
				{
					if( entry->book )
					{
						entry->exploded = !entry->exploded;
						this->render( SCREEN_SUB );
					}
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
			if( entry_it->first==this->active_list_id )
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