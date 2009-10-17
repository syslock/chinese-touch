#include "lesson_menu.h"
#include "screen.h"
// compiled-in sprite data:
#include "text-x-generic.h"
#include "accessories-dictionary.h"

LessonMenu::LessonMenu( FreetypeRenderer& _freetype_renderer, Library& _library )
	: freetype_renderer(_freetype_renderer), library(_library), book_sprite_vram(0), 
		lesson_sprite_vram(0), y_offset(5)
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
		this->freetype_renderer.clear_screen( this->info_screen );
		RenderStyle render_style;
		this->freetype_renderer.render( this->info_screen, "你好Main！", 
			this->freetype_renderer.han_face, 12, 0, 0, &render_style );
	}
	else if( screen == SCREEN_SUB )
	{
		this->freetype_renderer.clear_screen( this->menu_screen );
		oamClear( &oamSub, 0, 0 );
		int top = this->y_offset;
		int oam_entry = 0;
		for( Library::iterator book_it = this->library.begin(); 
			book_it != this->library.end() && top < 192; book_it++ )
		{
			if( top < -32 )
			{
				top += 32;
			}
			else
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
				//RenderRect rect = this->freetype_renderer.render( this->menu_screen, 
				//	book_it->second->title, this->freetype_renderer.han_face, 10, 50, top, &render_style );
				RenderRect rect(0,0,0,0);
				top += rect.height<32 ? 32 : rect.height;
			}
			for( Book::iterator lesson_it = book_it->second->begin();
				lesson_it != book_it->second->end() && top < 192; lesson_it++ )
			{
				if( top < -32 )
				{
					top += 32;
				}
				else
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
					//RenderRect rect = this->freetype_renderer.render( this->menu_screen, lesson_it->second->title, 
					//	this->freetype_renderer.han_face, 10, 50, top, &render_style );
					RenderRect rect(0,0,0,0);
					top += rect.height<32 ? 32 : rect.height;
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
				this->y_offset += touch.py - old_touch.py;
				this->render( SCREEN_SUB );
			}
            else if( !dragged && touch.px > (this->freetype_renderer.res_x-15) && touch.py < 15 )
			{
				return;
			}
            dragged = true;
			old_touch = touch;
		}
        if( keysUp() & KEY_TOUCH )
        {
            dragged = false;
        }
		swiWaitForVBlank();
	}
}
