#include <iostream>

#include <nds.h>

#include "new_words.h"
#include "config.h"
#include "error_console.h"


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


NewWordsViewer::NewWordsViewer( FreetypeRenderer& _freetype_renderer, Lesson& _lesson, Config& _config )
	: freetype_renderer(_freetype_renderer), lesson(_lesson), 
		word_index(0), config(_config)
{
	this->freetype_renderer.init_screen( SCREEN_MAIN, this->word_view );

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
	word->render( this->freetype_renderer, this->word_view );
}

void NewWordsViewer::run_until_exit()
{
	this->drawing_pad.render_buttons();
	touchPosition old_touch;
    touchRead( &old_touch );
	bool dragged = false;
    bool restart_line = false;
    while( this->word_index < this->lesson.new_words.size() )
    {
        this->config.save_position( this->lesson.new_words[this->word_index], this->word_index );
        scanKeys();
		int pressed = keysDown();
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
        if( keysCurrent() & KEY_TOUCH 
            && (touch.px!=old_touch.px || touch.py!=old_touch.py) )
        {
            if( touch.px < 15 && touch.py < 15 )
            {
                if( !dragged )
                {
                    if( this->word_index > 0 )
                    {
                        this->word_index--;
						NewWord* word = this->lesson.new_words[this->word_index];
                        this->config.save_position( word, this->word_index );
                        word->render( this->freetype_renderer, this->word_view );
                    }
                } else restart_line = true;
            }
            else if( touch.px > (this->word_view.res_x-15) && touch.py < 15 )
            {
                if( !dragged )
                {
					if( this->word_index+1 < this->lesson.new_words.size() )
					{
						this->word_index++;
						NewWord* word = this->lesson.new_words[this->word_index];
                        this->config.save_position( word, this->word_index );
                        word->render( this->freetype_renderer, this->word_view );
                    }
                } else restart_line = true;
            }
            else if( touch.px > (this->word_view.res_x-15) && touch.py > (this->word_view.res_y-15) )
            {
                if( !dragged )
                {
                    this->drawing_pad.render_buttons();
                    //this->drawing_pad.clear();
                } else restart_line = true;
            }
            else if( touch.px < 15 && touch.py > (this->word_view.res_y-15) )
            {
                if( !dragged )
                {
					NewWord* word = this->lesson.new_words[ this->word_index ];
					this->config.save_position( word, this->word_index );
					return;
                } else restart_line = true;
            }
            else if( touch.py < 20 && touch.px > 84 && touch.px < 108 ) // hanzi
            {
                if( !dragged )
                {
                    this->lesson.toggle_hanzi();
                    if( global_fat_initialized ) 
                    {
						NewWord* word = this->lesson.new_words[ this->word_index ];
                        word->render( this->freetype_renderer, this->word_view );
                    }
                } else restart_line = true;
            }
            else if( touch.py < 20 && touch.px > 114 && touch.px < 138 ) // pinyin
            {
                if( !dragged )
                {
                    this->lesson.toggle_pinyin();
                    if( global_fat_initialized ) 
                    {
						NewWord* word = this->lesson.new_words[ this->word_index ];
                        word->render( this->freetype_renderer, this->word_view );
                    }
                } else restart_line = true;
            }
            else if( touch.py < 20 && touch.px > 144 && touch.px < 168 ) // translation
            {
                if( !dragged )
                {
                    this->lesson.toggle_translation();
                    if( global_fat_initialized ) 
                    {
						NewWord* word = this->lesson.new_words[ this->word_index ];
                        word->render( this->freetype_renderer, this->word_view );
                    }
                } else restart_line = true;
            }
            else if( !dragged || restart_line )
            {
                restart_line = false;
                this->drawing_pad.draw_point( touch.px, touch.py );
                old_touch = touch;
            }
            else if( dragged )
            {
                this->drawing_pad.draw_line( touch.px, touch.py, old_touch.px, old_touch.py );
                old_touch = touch;
            }
            dragged = true;
        }
        if( keysUp() & KEY_TOUCH )
        {
            dragged = false;
        }
        swiWaitForVBlank();
    }
}
