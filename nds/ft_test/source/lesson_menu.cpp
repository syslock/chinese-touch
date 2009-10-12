#include "lesson_menu.h"
#include "screen.h"
// compiled-in sprite data:
#include "text-x-generic.h"
#include "accessories-dictionary.h"

LessonMenu::LessonMenu( FreetypeRenderer& _ft, Library& _library )
	: ft(_ft), library(_library), book_sprite_vram(0), lesson_sprite_vram(0)
{
	this->ft.init_screen( SCREEN_MAIN, this->info_screen );
	this->ft.init_screen( SCREEN_SUB, this->menu_screen );

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

void LessonMenu::render()
{
	this->ft.clear_screen( this->info_screen );
	this->ft.clear_screen( this->menu_screen );
	oamClear( &oamSub, 0, 0 );
	RenderStyle render_style;
	this->ft.render( this->info_screen, "你好Main！", this->ft.han_face, 12, 0, 0, &render_style );
	int top = 5;
	int oam_entry = 0;
	for( Library::iterator book_it = this->library.begin(); 
		book_it != this->library.end() && top < 192; book_it++ )
	{
		oamSet( &oamSub, 	// sub display
				oam_entry++,	// oam entry to set
				5, top, 	// position
				0, 			// priority
				0,			// alpha
				SpriteSize_32x32, // size
				SpriteColorFormat_Bmp, // format
				this->book_sprite_vram, // vram address
				0, 			// rotation index
				0,			// double size
				0, 			// hide
				0, 0, 		// vflip, hflip
				0			// apply mosaic
			);
		RenderRect rect = this->ft.render( this->menu_screen, book_it->second->title, this->ft.han_face, 10, 50, top, &render_style );
		top += rect.height<32 ? 32 : rect.height;
		for( Book::iterator lesson_it = book_it->second->begin();
			lesson_it != book_it->second->end() && top < 192; lesson_it++ )
		{
			oamSet( &oamSub, 	// sub display
					oam_entry++,	// oam entry to set
					5, top, 	// position
					0, 			// priority
					0,			// alpha
					SpriteSize_32x32, // size
					SpriteColorFormat_Bmp, // format
					this->lesson_sprite_vram, // vram address
					0, 			// rotation index
					0,			// double size
					0, 			// hide
					0, 0, 		// vflip, hflip
					0			// apply mosaic
				);
			rect = this->ft.render( this->menu_screen, lesson_it->second->title, this->ft.han_face, 10, 50, top, &render_style );
			top += rect.height<32 ? 32 : rect.height;
		}
	}
	swiWaitForVBlank();
	oamUpdate( &oamSub );
}
