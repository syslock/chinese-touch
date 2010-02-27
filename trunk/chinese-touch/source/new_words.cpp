#include <iostream>
#include <cmath>

#include <nds.h>
#include <nds/arm9/sprite.h>
#include <nds/arm9/background.h>
#include <nds/arm9/input.h>
#include <time.h>

#include "new_words.h"
#include "config.h"
#include "error_console.h"
#include "sprite_helper.h"
#include "words_db.h"

#include "greys256.h"
#include "top_left_button.h"
#include "top_left_button_active.h"
#include "top_right_button.h"
#include "top_right_button_active.h"
#include "bottom_left_button.h"
#include "bottom_left_button_active.h"
#include "bottom_right_button.h"
#include "bottom_right_button_active.h"
#include "top_paper_tab.h"
#include "top_paper_tab_active.h"
#include "top_paper_tab_inactive.h"
#include "bg_dragon.h"
#include "bottom_rating_bar.h"
#include "bottom_rating_easy.h"
#include "bottom_rating_medium.h"
#include "bottom_rating_hard.h"
#include "bottom_rating_impossible.h"


void NewWord::render( FreetypeRenderer& ft, RenderScreen& render_screen, NewWordRenderSettings& render_settings )
{
	// try to read the corresponding entry from the database:
	WordsDB::read_word(*this);
	// update words access time:
	this->atime = time(0);
	// write updated word to database:
	WordsDB::add_or_write_word( *this );
	render_screen.clear();
    
    // render hanzi centered
    RenderStyle render_style;
    render_style.center_x = true;
    int top = 5;
    int size = 32;
    if( render_settings.render_hanzi )
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
    if( render_settings.render_pinyin )
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
    if( render_settings.render_translation && render_settings.render_word_type 
		&& this->definitions.count(lang) && this->definitions[lang]->word_type.length() )
    {
        RenderInfo rect = ft.render( render_screen, this->definitions[lang]->word_type, ft.latin_face, size, 0, top, &render_style );
        top += rect.height+5;
    }

	unsigned int char_limit = 100;

    // render first n characters of translation
    size = 9;
    if( render_settings.render_translation && this->definitions.count(lang) 
		&& this->definitions[lang]->translation.length() )
    {
		std::string text = this->definitions[lang]->translation.substr(0,char_limit);
		if( text.length()==char_limit ) text += "...";
        RenderInfo rect = ft.render( render_screen, text, ft.latin_face, size, 0, top, &render_style );
        top += rect.height+10;
    }

	// render first n characters of comment
    size = 8;
    if( render_settings.render_comment && render_settings.render_translation 
		&& this->definitions.count(lang) && this->definitions[lang]->comment.length() )
    {
		std::string text = this->definitions[lang]->comment.substr(0,char_limit);
		if( text.length()==char_limit ) text += "...";
        RenderInfo rect = ft.render( render_screen, text, ft.latin_face, size, 0, top, &render_style );
        top += rect.height;
    }
}


int NewWordsViewer::BUTTON_ACTIVATION_DRAW_LIMIT = 5;

NewWordsViewer::NewWordsViewer( FreetypeRenderer& _freetype_renderer, NewWordList& _words, Config* _config )
	: freetype_renderer(_freetype_renderer), drawing_pad(drawing_screen), words(_words), 
		current_word(words.begin()), config(_config), 
		left_button(&oamSub,"<",SpriteSize_32x16,0,0,freetype_renderer.latin_face,10,0,0), 
		right_button(&oamSub,">",SpriteSize_32x16,drawing_screen.res_x-32,0,freetype_renderer.latin_face,10,2,0), 
		exit_button(&oamSub,"x",SpriteSize_16x16,0,drawing_screen.res_y-16,freetype_renderer.latin_face,10,-1,1),
		clear_button(&oamSub,"c",SpriteSize_16x16,drawing_screen.res_x-16,drawing_screen.res_y-16,freetype_renderer.latin_face,10,1,1),
		hanzi_tab(&oamSub,"汉字",SpriteSize_32x16,drawing_screen.res_x/2-16-32-8,0,freetype_renderer.han_face,9),
		pinyin_tab(&oamSub,"拼音",SpriteSize_32x16,drawing_screen.res_x/2-16,0,freetype_renderer.han_face,9,1,-1),
		latin_tab(&oamSub,"latin",SpriteSize_32x16,drawing_screen.res_x/2+16+8,0,freetype_renderer.latin_face,7,0,1),
		rating_bar(&oamSub,"",SpriteSize_64x32,drawing_screen.res_x/2-32,drawing_screen.res_y-32,freetype_renderer.latin_face,7,0,0),
		rating_easy(&oamSub,"",SpriteSize_16x16,drawing_screen.res_x/2-32,drawing_screen.res_y-16,freetype_renderer.latin_face,7,0,0),
		rating_medium(&oamSub,"",SpriteSize_16x16,drawing_screen.res_x/2-16,drawing_screen.res_y-16,freetype_renderer.latin_face,7,0,0),
		rating_hard(&oamSub,"",SpriteSize_16x16,drawing_screen.res_x/2,drawing_screen.res_y-16,freetype_renderer.latin_face,7,0,0),
		rating_impossible(&oamSub,"",SpriteSize_16x16,drawing_screen.res_x/2+16,drawing_screen.res_y-16,freetype_renderer.latin_face,7,0,0)
{
	this->freetype_renderer.init_screen( SCREEN_MAIN, this->word_screen );
	dmaCopy( bg_dragonBitmap, this->word_screen.bg_base_address, sizeof(bg_dragonBitmap) );
	set_16bpp_sprite_opague( this->word_screen.bg_base_address, 256, 192 );
	bgShow( this->word_screen.bg_id );
	this->word_screen.clear();
	this->freetype_renderer.init_screen( SCREEN_SUB, this->drawing_screen );
	this->drawing_screen.clear();

	// unteren Bildschirm für Spritenutzung initialisieren:
	vramSetBankD( VRAM_D_SUB_SPRITE );
	oamInit( &oamSub, SpriteMapping_Bmp_1D_128, 0 );
	oamAllocReset( &oamSub );
	oamEnable( &oamSub );

	// vorgerenderte Spritegrafiken laden:
	this->left_button.init_vram( top_left_buttonBitmap, this->left_button.bg_vram );
	this->left_button.init_vram( top_left_button_activeBitmap, this->left_button.bg_active_vram );
	this->right_button.init_vram( top_right_buttonBitmap, this->right_button.bg_vram );
	this->right_button.init_vram( top_right_button_activeBitmap, this->right_button.bg_active_vram );
	this->exit_button.init_vram( bottom_left_buttonBitmap, this->exit_button.bg_vram );
	this->exit_button.init_vram( bottom_left_button_activeBitmap, this->exit_button.bg_active_vram );
	this->clear_button.init_vram( bottom_right_buttonBitmap, this->clear_button.bg_vram );
	this->clear_button.init_vram( bottom_right_button_activeBitmap, this->clear_button.bg_active_vram );
	this->hanzi_tab.init_vram( top_paper_tabBitmap, this->hanzi_tab.bg_vram );
	this->hanzi_tab.init_vram( top_paper_tab_activeBitmap, this->hanzi_tab.bg_active_vram );
	this->hanzi_tab.init_vram( top_paper_tab_inactiveBitmap, this->hanzi_tab.bg_inactive_vram );
	this->rating_bar.init_vram( bottom_rating_barBitmap, this->rating_bar.bg_vram );
	this->rating_bar.bg_prio = 2; // place bar behind rating emotes
	this->rating_easy.init_vram( bottom_rating_easyBitmap, this->rating_easy.bg_vram );
	this->rating_medium.init_vram( bottom_rating_mediumBitmap, this->rating_medium.bg_vram );
	this->rating_hard.init_vram( bottom_rating_hardBitmap, this->rating_hard.bg_vram );
	this->rating_impossible.init_vram( bottom_rating_impossibleBitmap, this->rating_impossible.bg_vram );

	this->pinyin_tab.bg_vram = hanzi_tab.bg_vram;
	this->pinyin_tab.bg_active_vram = hanzi_tab.bg_active_vram;
	this->pinyin_tab.bg_inactive_vram = hanzi_tab.bg_inactive_vram;
	this->pinyin_tab.owns_bg_vram = false;
	this->latin_tab.bg_vram = hanzi_tab.bg_vram;
	this->latin_tab.bg_active_vram = hanzi_tab.bg_active_vram;
	this->latin_tab.bg_inactive_vram = hanzi_tab.bg_inactive_vram;
	this->latin_tab.owns_bg_vram = false;

	this->text_buttons.push_back( &this->left_button );
	this->text_buttons.push_back( &this->right_button );
	this->text_buttons.push_back( &this->exit_button );
	this->text_buttons.push_back( &this->clear_button );
	this->text_buttons.push_back( &this->hanzi_tab );
	this->text_buttons.push_back( &this->pinyin_tab );
	this->text_buttons.push_back( &this->latin_tab );
	this->text_buttons.push_back( &this->rating_bar );
	this->text_buttons.push_back( &this->rating_easy );
	this->text_buttons.push_back( &this->rating_medium );
	this->text_buttons.push_back( &this->rating_hard );
	this->text_buttons.push_back( &this->rating_impossible );

	for( TextButtonList::iterator i=this->text_buttons.begin(); i!=this->text_buttons.end(); i++ )
	{
		if( (*i)->owns_bg_vram )
		{
			// Alpha-Bits bei definierten Spritepixeln auf "undurchsichtig" setzen:
			if( (*i)->bg_vram ) set_16bpp_sprite_opague( (*i)->bg_vram, (*i)->width, (*i)->height, 0 );
			if( (*i)->bg_active_vram ) set_16bpp_sprite_opague( (*i)->bg_active_vram, (*i)->width, (*i)->height, 0 );
			if( (*i)->bg_inactive_vram ) set_16bpp_sprite_opague( (*i)->bg_inactive_vram, (*i)->width, (*i)->height, 0 );
		}
		if( (*i)->text.length() )
		{
			// VRAM für 8-Bit-Buttonbeschriftungs-Sprites reservieren:
			(*i)->text_vram = oamAllocateGfx( &oamSub, SpriteSize_32x16, SpriteColorFormat_256Color );
			RenderScreenBuffer button_text( (*i)->width, (*i)->height );
			RenderStyle render_style;
			render_style.center_x = true;
			this->freetype_renderer.render( button_text, (*i)->text, 
				(*i)->face, (*i)->font_size, 0, 1, &render_style );
			// Spritekonvertierung:
			// (Zwischenpufferung aus Bequemlichkeit, weil VRAM nur mit 16-bit-Wörtern beschreibbbar)
			u8 conversion_buffer[(*i)->width * (*i)->height];
			tile_8bpp_sprite( (u8*)(button_text.base_address), conversion_buffer, (*i)->width, (*i)->height );
			memcpy( (*i)->text_vram, conversion_buffer, (*i)->width * (*i)->height * 1 );
		}
	}
	
	// Palette für 8-Bit-Buttonbeschriftungen wie Hintergrundpalette initialisieren:
	dmaCopy( greys256Pal, SPRITE_PALETTE_SUB, 256*2 );

	// Wortliste initialisieren und auf gespeicherten Index positionieren:
	if( this->config ) 
	{
		int word_id = this->config->get_current_word_id();
		for( this->current_word=this->words.begin(); this->current_word!=this->words.end(); this->current_word++ )
		{
			if( (*this->current_word)->id == word_id ) break;
		}
		if( this->current_word==this->words.end() ) this->current_word=this->words.begin();
	}
	bgHide( this->word_screen.bg_id );
}

void NewWordsViewer::render( Screen screen )
{
	NewWord* new_word = 0;
	if( this->current_word!=this->words.end() )
	{
		new_word = *this->current_word;
	}
	if( screen == SCREEN_MAIN )
	{
		this->word_screen.clear();
		if( new_word )
		{
			new_word->render( this->freetype_renderer, this->word_screen, *this );
		}
	}
	else if( screen == SCREEN_SUB )
	{
		oamClear( &oamSub, 0, 0 );
		int oam_entry = 0;
		if( this->words.size() )
		{
			if( this->current_word != this->words.begin() )
			{
				this->left_button.render_to( oam_entry );
			}
			NewWordList::iterator test_it = this->current_word;
			if( ++test_it != this->words.end() )
			{
				this->right_button.render_to( oam_entry );
			}
		}
		this->exit_button.render_to( oam_entry );
		this->clear_button.render_to( oam_entry );
		this->hanzi_tab.render_to( oam_entry, this->hanzi_tab.x, this->hanzi_tab.y-(this->render_hanzi ? 0 : 8) );
		this->pinyin_tab.render_to( oam_entry, this->pinyin_tab.x, this->pinyin_tab.y-(this->render_pinyin ? 0 : 8) );
		this->latin_tab.render_to( oam_entry, this->latin_tab.x, this->latin_tab.y-(this->render_translation ? 0 : 8) );
		this->rating_bar.render_to( oam_entry );
		if( new_word )
		{
			if( !WordsDB::read_word(*new_word) ) WordsDB::add_or_write_word( *new_word );
			if( this->rating_easy.active || new_word->rating==RATING_EASY )
				this->rating_easy.render_to( oam_entry );
			if( this->rating_medium.active || new_word->rating==RATING_MEDIUM )
				this->rating_medium.render_to( oam_entry );
			if( this->rating_hard.active || new_word->rating==RATING_HARD )
				this->rating_hard.render_to( oam_entry );
			if( this->rating_impossible.active || new_word->rating==RATING_IMPOSSIBLE )
				this->rating_impossible.render_to( oam_entry );
		}
		// gepufferte Bilddaten einblenden bzw. in den VRAM kopieren:
		swiWaitForVBlank();
		oamUpdate( &oamSub );
	}
}

void NewWordsViewer::run_until_exit()
{
	if( this->config ) this->config->save_position( *this->current_word );
	this->render( SCREEN_SUB );
	this->render( SCREEN_MAIN );
	touchPosition old_touch;
    touchRead( &old_touch );
	bool touched = false;
	int pixels_drawn = 0;
	int old_distance = 0;
    while( this->current_word!=this->words.end() )
    {
        if( this->config ) this->config->save_position( *this->current_word );
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
		
		NewWordList::iterator test_it = this->current_word;
		if( pressed & KEY_L && this->current_word!=this->words.begin() )
		{
			this->left_button.active = true;
			this->render( SCREEN_SUB );
			this->left_button.active = false;
			this->current_word--;
			this->render( SCREEN_MAIN );
			this->render( SCREEN_SUB );
		}
		else if( pressed & KEY_R && ++test_it!=this->words.end() )
		{
			this->right_button.active = true;
			this->render( SCREEN_SUB );
			this->right_button.active = false;
			this->current_word++;
			this->render( SCREEN_MAIN );
			this->render( SCREEN_SUB );
		}
		
		touchPosition touch;
        touchRead( &touch );
        if( keysCurrent() & KEY_TOUCH )
        {
			if( !touched ) 
			{
				touched = true;
				pixels_drawn = 0;
				old_touch = touch;
			}
			NewWordList::iterator test_it = this->current_word;
            if( this->current_word!=this->words.begin()
				&& this->left_button.is_responsible(touch.px, touch.py)
				&& pixels_drawn < BUTTON_ACTIVATION_DRAW_LIMIT )
			{
				if( !this->left_button.active )
				{
					this->left_button.active = true;
					this->render( SCREEN_SUB );
				}
			}
            else if( ++test_it != this->words.end()
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
            else if( this->hanzi_tab.is_responsible(touch.px, touch.py) 
				&& pixels_drawn < BUTTON_ACTIVATION_DRAW_LIMIT )
			{
				if( !this->hanzi_tab.active )
				{
					this->hanzi_tab.active = true;
					this->render( SCREEN_SUB );
				}
			}
            else if( this->pinyin_tab.is_responsible(touch.px, touch.py) 
				&& pixels_drawn < BUTTON_ACTIVATION_DRAW_LIMIT )
			{
				if( !this->pinyin_tab.active )
				{
					this->pinyin_tab.active = true;
					this->render( SCREEN_SUB );
				}
			}
            else if( this->latin_tab.is_responsible(touch.px, touch.py) 
				&& pixels_drawn < BUTTON_ACTIVATION_DRAW_LIMIT )
			{
				if( !this->latin_tab.active )
				{
					this->latin_tab.active = true;
					this->render( SCREEN_SUB );
				}
			}
            else if( this->rating_easy.is_responsible(touch.px, touch.py) 
				&& pixels_drawn < BUTTON_ACTIVATION_DRAW_LIMIT )
			{
				if( !this->rating_easy.active )
				{
					this->rating_easy.active = true;
					this->render( SCREEN_SUB );
				}
			}
            else if( this->rating_medium.is_responsible(touch.px, touch.py) 
				&& pixels_drawn < BUTTON_ACTIVATION_DRAW_LIMIT )
			{
				if( !this->rating_medium.active )
				{
					this->rating_medium.active = true;
					this->render( SCREEN_SUB );
				}
			}
            else if( this->rating_hard.is_responsible(touch.px, touch.py) 
				&& pixels_drawn < BUTTON_ACTIVATION_DRAW_LIMIT )
			{
				if( !this->rating_hard.active )
				{
					this->rating_hard.active = true;
					this->render( SCREEN_SUB );
				}
			}
            else if( this->rating_impossible.is_responsible(touch.px, touch.py) 
				&& pixels_drawn < BUTTON_ACTIVATION_DRAW_LIMIT )
			{
				if( !this->rating_impossible.active )
				{
					this->rating_impossible.active = true;
					this->render( SCREEN_SUB );
				}
			}
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
				int distance = (int)std::sqrt( std::pow(x_diff,2) + std::pow(y_diff,2) );
				if( distance && ((old_distance && (distance <= old_distance*DrawingPad::MAX_ACCELERATION_FACTOR)) 
								|| (distance <= DrawingPad::MAX_ACCELERATION_FACTOR)) )
				{
					old_distance = distance;
					pixels_drawn += distance;
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
			NewWordList::iterator test_it = this->current_word;
            if( this->current_word != this->words.begin()
				&& this->left_button.is_responsible(old_touch.px, old_touch.py)
				&& this->left_button.active )
            {
				this->left_button.active = false;
				this->current_word--;
				this->render( SCREEN_MAIN );
				this->render( SCREEN_SUB );
            }
            else if( ++test_it != this->words.end()
				&& this->right_button.is_responsible(old_touch.px, old_touch.py)
				&& this->right_button.active )
            {
				this->right_button.active = false;
				this->current_word++;
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
				NewWord* word = *this->current_word;
				if( this->config ) this->config->save_position( word );
				return;
            }
            else if( this->hanzi_tab.is_responsible(old_touch.px, old_touch.py) 
				&& this->hanzi_tab.active )
            {
				this->hanzi_tab.active = false;
				this->toggle_hanzi();
				this->render( SCREEN_MAIN );
				this->render( SCREEN_SUB );
            }
            else if( this->pinyin_tab.is_responsible(old_touch.px, old_touch.py) 
				&& this->pinyin_tab.active )
            {
				this->pinyin_tab.active = false;
				this->toggle_pinyin();
				this->render( SCREEN_MAIN );
				this->render( SCREEN_SUB );
            }
            else if( this->latin_tab.is_responsible(old_touch.px, old_touch.py) 
				&& this->latin_tab.active )
            {
				this->latin_tab.active = false;
				this->toggle_translation();
				this->render( SCREEN_MAIN );
				this->render( SCREEN_SUB );
            }
            else if( this->rating_easy.is_responsible(old_touch.px, old_touch.py) 
				&& this->rating_easy.active )
            {
				this->rating_easy.active = false;
				(*this->current_word)->rating = RATING_EASY;
				WordsDB::add_or_write_word( **this->current_word );
				this->render( SCREEN_MAIN );
				this->render( SCREEN_SUB );
            }
            else if( this->rating_medium.is_responsible(old_touch.px, old_touch.py) 
				&& this->rating_medium.active )
            {
				this->rating_medium.active = false;
				(*this->current_word)->rating = RATING_MEDIUM;
				WordsDB::add_or_write_word( **this->current_word );
				this->render( SCREEN_MAIN );
				this->render( SCREEN_SUB );
            }
            else if( this->rating_hard.is_responsible(old_touch.px, old_touch.py) 
				&& this->rating_hard.active )
            {
				this->rating_hard.active = false;
				(*this->current_word)->rating = RATING_HARD;
				WordsDB::add_or_write_word( **this->current_word );
				this->render( SCREEN_MAIN );
				this->render( SCREEN_SUB );
            }
            else if( this->rating_impossible.is_responsible(old_touch.px, old_touch.py) 
				&& this->rating_impossible.active )
            {
				this->rating_impossible.active = false;
				(*this->current_word)->rating = RATING_IMPOSSIBLE;
				WordsDB::add_or_write_word( **this->current_word );
				this->render( SCREEN_MAIN );
				this->render( SCREEN_SUB );
            }
			else
			{
				this->drawing_pad.draw_point( old_touch.px, old_touch.py );
			}
		}
		else
		{
			swiWaitForVBlank();
			touched = false;
			pixels_drawn = 0;
			for( TextButtonList::iterator i=this->text_buttons.begin(); 
				i!=this->text_buttons.end(); i++ )
			{
				(*i)->active = false;
			}
		}
    }
}