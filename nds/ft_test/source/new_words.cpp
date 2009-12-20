#include <iostream>

#include <nds.h>

#include "new_words.h"
#include "config.h"
#include "error_console.h"
#include "sprite_helper.h"
#include "menu_button_colors.h"
#include "top_left_button.h"
#include "top_left_button_active.h"
#include "top_right_button.h"
#include "top_right_button_active.h"
#include "bottom_left_button.h"
#include "bottom_left_button_active.h"
#include "bottom_right_button.h"
#include "bottom_right_button_active.h"


void NewWord::render( FreetypeRenderer& ft, RenderScreen& render_screen )
{
	render_screen.clear();
    
    // render hanzi centered
    RenderStyle render_style;
    render_style.center_x = true;
    int top = 5;
    int size = 32;
    if( this->lesson->render_hanzi )
    {
        RenderInfo rect = ft.render( render_screen, this->hanzi, ft.han_face, size, 0, top, &render_style );
        top += rect.height;
    }
    else
    {
        top += size*1.2;
    }
    top += 10;
    
    // render pinyin centered
    size = 14;
    if( this->lesson->render_pinyin )
    {
        RenderInfo rect = ft.render( render_screen, this->pinyin, ft.han_face, size, 0, top, &render_style );
        top += rect.height;
    }
    else
    {
        top += size*1.2;
    }
    top += 10;
    
	std::string lang = "de";
	
    // render word type
    size = 7;
    if( this->lesson->render_translation && this->lesson->render_word_type 
		&& this->definitions.count(lang) && this->definitions[lang]->word_type.length() )
    {
        RenderInfo rect = ft.render( render_screen, this->definitions[lang]->word_type, ft.latin_face, size, 0, top, &render_style );
        top += rect.height+5;
    }

	unsigned int char_limit = 100;

    // render first n characters of translation
    size = 9;
    if( this->lesson->render_translation && this->definitions.count(lang) 
		&& this->definitions[lang]->translation.length() )
    {
		std::string text = this->definitions[lang]->translation.substr(0,char_limit);
		if( text.length()==char_limit ) text += "...";
        RenderInfo rect = ft.render( render_screen, text, ft.latin_face, size, 0, top, &render_style );
        top += rect.height+10;
    }

	// render first n characters of comment
    size = 8;
    if( this->lesson->render_comment && this->lesson->render_translation 
		&& this->definitions.count(lang) && this->definitions[lang]->comment.length() )
    {
		std::string text = this->definitions[lang]->comment.substr(0,char_limit);
		if( text.length()==char_limit ) text += "...";
        RenderInfo rect = ft.render( render_screen, text, ft.han_face, size, 0, top, &render_style );
        top += rect.height;
    }
}


int NewWordsViewer::BUTTON_ACTIVATION_DRAW_LIMIT = 5;

NewWordsViewer::NewWordsViewer( FreetypeRenderer& _freetype_renderer, Lesson& _lesson, Config& _config )
	: freetype_renderer(_freetype_renderer), drawing_pad(drawing_screen), lesson(_lesson), 
		word_index(0), config(_config), 
		left_button(&oamSub,"<",32,16,0,0), 
		right_button(&oamSub,">",32,16,drawing_screen.res_x-32,0), 
		exit_button(&oamSub,"x",16,16,0,drawing_screen.res_y-16),
		clear_button(&oamSub,"c",16,16,drawing_screen.res_x-16,drawing_screen.res_y-16)
{
	this->freetype_renderer.init_screen( SCREEN_MAIN, this->word_screen );
	this->word_screen.clear();
	this->freetype_renderer.init_screen( SCREEN_SUB, this->drawing_screen );
	this->drawing_screen.clear();

	// unteren Bildschirm für Spritenutzung initialisieren:
	vramSetBankD( VRAM_D_SUB_SPRITE );
	oamInit( &oamSub, SpriteMapping_Bmp_1D_128, 0 );
	oamAllocReset( &oamSub );
	oamEnable( &oamSub );

	// vorgerenderte Spritegrafiken laden:
	this->left_button.bg_vram = oamAllocateGfx( &oamSub, SpriteSize_32x16, SpriteColorFormat_Bmp );
	dmaCopy( top_left_buttonBitmap, this->left_button.bg_vram, this->left_button.width * this->left_button.height *2 );
	this->left_button.bg_active_vram = oamAllocateGfx( &oamSub, SpriteSize_32x16, SpriteColorFormat_Bmp );
	dmaCopy( top_left_button_activeBitmap, this->left_button.bg_active_vram, this->left_button.width * this->left_button.height *2 );
	this->right_button.bg_vram = oamAllocateGfx( &oamSub, SpriteSize_32x16, SpriteColorFormat_Bmp );
	dmaCopy( top_right_buttonBitmap, this->right_button.bg_vram, this->right_button.width * this->right_button.height *2 );
	this->right_button.bg_active_vram = oamAllocateGfx( &oamSub, SpriteSize_32x16, SpriteColorFormat_Bmp );
	dmaCopy( top_right_button_activeBitmap, this->right_button.bg_active_vram, this->right_button.width * this->right_button.height *2 );
	this->exit_button.bg_vram = oamAllocateGfx( &oamSub, SpriteSize_16x16, SpriteColorFormat_Bmp );
	dmaCopy( bottom_left_buttonBitmap, this->exit_button.bg_vram, this->exit_button.width * this->exit_button.height *2 );
	this->exit_button.bg_active_vram = oamAllocateGfx( &oamSub, SpriteSize_16x16, SpriteColorFormat_Bmp );
	dmaCopy( bottom_left_button_activeBitmap, this->exit_button.bg_active_vram, this->exit_button.width * this->exit_button.height *2 );
	this->clear_button.bg_vram = oamAllocateGfx( &oamSub, SpriteSize_16x16, SpriteColorFormat_Bmp );
	dmaCopy( bottom_right_buttonBitmap, this->clear_button.bg_vram, this->clear_button.width * this->clear_button.height *2 );
	this->clear_button.bg_active_vram = oamAllocateGfx( &oamSub, SpriteSize_16x16, SpriteColorFormat_Bmp );
	dmaCopy( bottom_right_button_activeBitmap, this->clear_button.bg_active_vram, this->clear_button.width * this->clear_button.height *2 );

	this->text_buttons.push_back( &this->left_button );
	this->text_buttons.push_back( &this->right_button );
	this->text_buttons.push_back( &this->exit_button );
	this->text_buttons.push_back( &this->clear_button );

	for( TextButtonList::iterator i=this->text_buttons.begin(); i!=this->text_buttons.end(); i++ )
	{
		// Alpha-Bits bei definierten Spritepixeln auf "undurchsichtig" setzen:
		if( (*i)->bg_vram ) set_16bpp_sprite_opague( (*i)->bg_vram, (*i)->width, (*i)->height, 0 );
		if( (*i)->bg_active_vram ) set_16bpp_sprite_opague( (*i)->bg_active_vram, (*i)->width, (*i)->height, 0 );
		if( (*i)->bg_inactive_vram ) set_16bpp_sprite_opague( (*i)->bg_inactive_vram, (*i)->width, (*i)->height, 0 );
		// VRAM für 8-Bit-Buttonbeschriftungs-Sprites reservieren:
		(*i)->text_vram = oamAllocateGfx( &oamSub, SpriteSize_32x16, SpriteColorFormat_256Color );
		RenderScreenBuffer button_text( (*i)->width, (*i)->height );
		RenderStyle render_style;
		render_style.center_x = true;
		this->freetype_renderer.render( button_text, (*i)->text, 
			this->freetype_renderer.latin_face, 10, 0, 1, &render_style );
		// Spritekonvertierung:
		// (Zwischenpufferung aus Bequemlichkeit, weil VRAM nur mit 16-bit-Wörtern beschreibbbar)
		u8 conversion_buffer[(*i)->width * (*i)->height];
		tile_8bpp_sprite( (u8*)(button_text.base_address), conversion_buffer, (*i)->width, (*i)->height );
		memcpy( (*i)->text_vram, conversion_buffer, (*i)->width * (*i)->height * 1 );
	}
	
	// Palette für 8-Bit-Buttonbeschriftungen wie Hintergrundpalette initialisieren:
	dmaCopy( menu_button_colorsPal, SPRITE_PALETTE_SUB, 256*2 );

	// Wortliste initialisieren und auf gespeicherten Index positionieren:
	this->word_index = 0;
	if( this->config.get_current_book_name()==this->lesson.book->name
		&& this->config.get_current_lesson_number()==this->lesson.number )
	{
		this->word_index = this->config.get_current_word_number();
	}
	if( !this->lesson.new_words.size() )
	{
		WARN( "Empty lesson \"" << this->lesson.title << "\". Generating hardcoded test word." );
		NewWord* word = new NewWord( "汉字", "hànzì", &lesson );
		Definition* definition = new Definition();
		definition->lang = "de";
		definition->translation = "Chinesische Schrift";
		definition->word_type = "N";
		word->definitions[ definition->lang ] = definition;
		this->lesson.new_words.push_back( word );
	}
	if( this->lesson.new_words.size() <= this->word_index )
	{
		this->word_index = this->lesson.new_words.size()-1;
	}
	NewWord* word = this->lesson.new_words[ this->word_index ];
	word->render( this->freetype_renderer, this->word_screen );
}

void NewWordsViewer::render( Screen screen )
{
	if( screen == SCREEN_MAIN )
	{
		this->word_screen.clear();
		if( this->word_index >= 0 
			&& this->word_index < this->lesson.new_words.size() )
		{
			NewWord* new_word = this->lesson.new_words[this->word_index];
			new_word->render( this->freetype_renderer, this->word_screen );
		}
	}
	else if( screen == SCREEN_SUB )
	{
		oamClear( &oamSub, 0, 0 );
		int oam_entry = 0;
		if( this->lesson.new_words.size() )
		{
			if( this->word_index >= 0 )
			{
				oamSet( this->left_button.oam, oam_entry++,
						0, 0, 	// position
						1, 1, SpriteSize_32x16, SpriteColorFormat_Bmp, 
						/* FIXME: don't guess! somehow compute correct vram offsets: */
						this->left_button.active ? this->left_button.bg_active_vram-64 : this->left_button.bg_vram,
						0, 0, 0, 0, 0, 0 );
				oamSet( this->left_button.oam, oam_entry++,
						0, 0, 	// position
						0, 0, SpriteSize_32x16, SpriteColorFormat_256Color, this->left_button.text_vram,
						0, 0, 0, 0, 0, 0 );
			}
			if( this->word_index < this->lesson.new_words.size() )
			{
				oamSet( this->right_button.oam, oam_entry++,
						this->drawing_screen.res_x-32, 0, 	// position
						1, 1, SpriteSize_32x16, SpriteColorFormat_Bmp, 
						/* FIXME: don't guess! somehow compute correct vram offsets: */
						this->right_button.active ? this->right_button.bg_active_vram-64 : this->right_button.bg_vram,
						0, 0, 0, 0, 0, 0 );
				oamSet( this->right_button.oam, oam_entry++,
						this->drawing_screen.res_x-32, 0, 	// position
						0, 0, SpriteSize_32x16, SpriteColorFormat_256Color, this->right_button.text_vram,
						0, 0, 0, 0, 0, 0 );
			}
		}
		oamSet( this->exit_button.oam, oam_entry++,
				0, this->drawing_screen.res_y-16, 	// position
				1, 1, SpriteSize_16x16, SpriteColorFormat_Bmp, 
				/* FIXME: don't guess! somehow compute correct vram offsets: */
				this->exit_button.active ? this->exit_button.bg_active_vram+32 : this->exit_button.bg_vram,
				0, 0, 0, 0, 0, 0 );
		oamSet( this->exit_button.oam, oam_entry++,
				0, this->drawing_screen.res_y-16, 	// position
				0, 0, SpriteSize_16x16, SpriteColorFormat_256Color, this->exit_button.text_vram,
				0, 0, 0, 0, 0, 0 );
		oamSet( this->clear_button.oam, oam_entry++,
				this->drawing_screen.res_x-16, this->drawing_screen.res_y-16, 	// position
				1, 1, SpriteSize_16x16, SpriteColorFormat_Bmp, 
				/* FIXME: don't guess! somehow compute correct vram offsets: */
				this->clear_button.active ? this->clear_button.bg_active_vram-32 : this->clear_button.bg_vram-64,
				0, 0, 0, 0, 0, 0 );
		oamSet( this->clear_button.oam, oam_entry++,
				this->drawing_screen.res_x-16, this->drawing_screen.res_y-16, 	// position
				0, 0, SpriteSize_16x16, SpriteColorFormat_256Color, this->clear_button.text_vram,
				0, 0, 0, 0, 0, 0 );
		// gepufferte Bilddaten einblenden bzw. in den VRAM kopieren:
		swiWaitForVBlank();
		oamUpdate( &oamSub );
	}
}

void NewWordsViewer::run_until_exit()
{
	this->config.save_position( &this->lesson );
	this->render( SCREEN_SUB );
	this->render( SCREEN_MAIN );
	touchPosition old_touch;
    touchRead( &old_touch );
	bool touched = false;
	int pixels_drawn = 0;
    while( this->word_index >= 0 
			&& this->word_index < this->lesson.new_words.size() )
    {
        this->config.save_position( this->lesson.new_words[this->word_index], this->word_index );
        scanKeys();
		int pressed = keysDown();
		int released = keysUp();
		int held = keysHeld();
		if( held & KEY_SELECT && pressed & KEY_UP )
		{
			ErrorConsole::init_screen( SCREEN_MAIN );
		}
		if( held & KEY_SELECT && pressed & KEY_DOWN )
		{
			ErrorConsole::init_screen( SCREEN_SUB );
		}
		if( held & KEY_SELECT && pressed & KEY_LEFT )
		{
			ErrorConsole::clear();
		}
		if( held & KEY_SELECT && pressed & KEY_RIGHT )
		{
			ErrorConsole::dump();
		}
		
		touchPosition touch;
        touchRead( &touch );
        int area = touch.px * touch.z2 / touch.z1 - touch.px;
        // (touch.px!=old_touch.px || touch.py!=old_touch.py)
        if( keysCurrent() & KEY_TOUCH )
        {
			if( !touched ) 
			{
				touched = true;
				pixels_drawn = 0;
				old_touch = touch;
			}
            if( this->word_index > 0
				&& this->left_button.is_responsible(touch.px, touch.py)
				&& pixels_drawn < BUTTON_ACTIVATION_DRAW_LIMIT )
			{
				if( !this->left_button.active )
				{
					this->left_button.active = true;
					this->render( SCREEN_SUB );
				}
			}
            else if( this->word_index+1 < this->lesson.new_words.size()
				&& this->right_button.is_responsible(touch.px, touch.py)
				&& pixels_drawn < BUTTON_ACTIVATION_DRAW_LIMIT )
			{
				if( !this->right_button.active )
				{
					this->right_button.active = true;
					this->render( SCREEN_SUB );
				}
			}
            else if( this->clear_button.is_responsible(touch.px, touch.py) 
				&& pixels_drawn < BUTTON_ACTIVATION_DRAW_LIMIT )
			{
				if( !this->clear_button.active )
				{
					this->clear_button.active = true;
					this->render( SCREEN_SUB );
				}
			}
            else if( this->exit_button.is_responsible(touch.px, touch.py) 
				&& pixels_drawn < BUTTON_ACTIVATION_DRAW_LIMIT )
			{
				if( !this->exit_button.active )
				{
					this->exit_button.active = true;
					this->render( SCREEN_SUB );
				}
			}
#if 0
            else if( touch.py < 20 && touch.px > 84 && touch.px < 108 ) // hanzi
            {
                if( !dragged )
                {
                    this->lesson.toggle_hanzi();
					this->render( SCREEN_MAIN );
                }
            }
            else if( touch.py < 20 && touch.px > 114 && touch.px < 138 ) // pinyin
            {
                if( !dragged )
                {
                    this->lesson.toggle_pinyin();
					this->render( SCREEN_MAIN );
                }
            }
            else if( touch.py < 20 && touch.px > 144 && touch.px < 168 ) // translation
            {
                if( !dragged )
                {
                    this->lesson.toggle_translation();
					this->render( SCREEN_MAIN );
                }
            }
#endif
			else
			{
				bool changed = false;
				for( TextButtonList::iterator i=this->text_buttons.begin(); i!=this->text_buttons.end(); i++ )
				{
					changed |= (*i)->active;
					(*i)->active = false;
				}
				int x_diff = touch.px - old_touch.px;
				int y_diff = touch.py - old_touch.py;
				if( y_diff || x_diff )
				{
					pixels_drawn += abs(y_diff) + abs(x_diff);
					changed = true;
					this->drawing_pad.draw_line( touch.px, touch.py, old_touch.px, old_touch.py );
				}
				if( changed ) this->render( SCREEN_SUB );
			}
			old_touch = touch;
		}
		else if( touched && pixels_drawn < BUTTON_ACTIVATION_DRAW_LIMIT )
		{
			touched = false;
            if( this->word_index > 0
				&& this->left_button.is_responsible(old_touch.px, old_touch.py)
				&& this->left_button.active )
            {
				this->left_button.active = false;
				this->word_index--;
				this->render( SCREEN_MAIN );
				this->render( SCREEN_SUB );
            }
            else if( this->word_index+1 < this->lesson.new_words.size()
				&& this->right_button.is_responsible(old_touch.px, old_touch.py)
				&& this->right_button.active )
            {
				this->right_button.active = false;
				this->word_index++;
				this->render( SCREEN_MAIN );
				this->render( SCREEN_SUB );
            }
            else if( this->clear_button.is_responsible(old_touch.px, old_touch.py) 
				&& this->clear_button.active )
            {
				this->clear_button.active = false;
				this->render( SCREEN_SUB );
				this->drawing_pad.clear();
            }
            else if( this->exit_button.is_responsible(old_touch.px, old_touch.py) 
				&& this->exit_button.active )
            {
				this->exit_button.active = false;
				NewWord* word = this->lesson.new_words[ this->word_index ];
				this->config.save_position( word, this->word_index );
				return;
            }
			else
			{
				this->drawing_pad.draw_point( old_touch.px, old_touch.py );
			}
		}
		else
		{
			touched = false;
			pixels_drawn = 0;
			for( TextButtonList::iterator i=this->text_buttons.begin(); 
				i!=this->text_buttons.end(); i++ )
			{
				(*i)->active = false;
			}
		}
        swiWaitForVBlank();
    }
}
