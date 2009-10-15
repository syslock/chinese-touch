#include <iostream>

#include <nds.h>

#include "new_words.h"
#include "config.h"
#include "error_console.h"

NewWords::NewWords( FreetypeRenderer& _freetype_renderer, Lesson& _lesson, Config& _config )
	: freetype_renderer(_freetype_renderer), lesson(_lesson), 
		word_it(lesson.begin()), word_index((*word_it)->number), 
		config(_config)
{
	this->freetype_renderer.init_screen( SCREEN_MAIN, this->word_view );

	word_index = this->config.get_current_word_number();
	for( word_it=lesson.begin(); (*word_it)->number < word_index 
			&& word_it!=lesson.end(); word_it++ );
	if( word_it == lesson.end() )
	{
		ErrorConsole::init();
		std::cout << "warning: " << CONFIG_FILE_NAME << " id out of bounds" << std::endl;
		word_it--;
	}
	word_index = (*word_it)->number;
	(*word_it)->render( this->freetype_renderer, word_view );
}

void NewWords::run_until_exit()
{
	this->drawing_pad.render_buttons();
	touchPosition old_touch;
    touchRead( &old_touch );
	bool dragged = false;
    bool restart_line = false;
    while( true )
    {
        this->config.save_position( *word_it );
        scanKeys();
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
                    if( word_it != lesson.begin() )
                    {
                        word_it--;
                        word_index--;
                        std::cout << "prev" << std::endl;
                        this->config.save_position( *word_it );
                        (*word_it)->render( this->freetype_renderer, word_view );
                    }
                } else restart_line = true;
            }
            else if( touch.px > (this->freetype_renderer.res_x-15) && touch.py < 15 )
            {
                if( !dragged )
                {
                    word_it++;
                    word_index++;
                    if( word_it != lesson.end() )
                    {
                        std::cout << "next" << std::endl;
                        this->config.save_position( *word_it );
                        (*word_it)->render( this->freetype_renderer, word_view );
                    }
                    else
                    {
                        word_it--;
                        word_index--;
                    }
                } else restart_line = true;
            }
            else if( touch.px > (this->freetype_renderer.res_x-15) && touch.py > (this->freetype_renderer.res_y-15) )
            {
                if( !dragged )
                {
#if ! DEBUG
                    this->drawing_pad.render_buttons();
                    //this->drawing_pad.clear();
#endif
                } else restart_line = true;
            }
            else if( touch.px < 15 && touch.py > (this->freetype_renderer.res_y-15) )
            {
                if( !dragged )
                {
					return;
                } else restart_line = true;
            }
            else if( touch.py < 20 && touch.px > 84 && touch.px < 108 ) // hanzi
            {
                if( !dragged )
                {
                    lesson.toggle_hanzi();
                    if( global_fat_initialized ) 
                    {
                        (*word_it)->render( this->freetype_renderer, word_view );
                    }
                } else restart_line = true;
            }
            else if( touch.py < 20 && touch.px > 114 && touch.px < 138 ) // pinyin
            {
                if( !dragged )
                {
                    lesson.toggle_pinyin();
                    if( global_fat_initialized ) 
                    {
                        (*word_it)->render( this->freetype_renderer, word_view );
                    }
                } else restart_line = true;
            }
            else if( touch.py < 20 && touch.px > 144 && touch.px < 168 ) // translation
            {
                if( !dragged )
                {
                    lesson.toggle_translation();
                    if( global_fat_initialized ) 
                    {
                        (*word_it)->render( this->freetype_renderer, word_view );
                    }
                } else restart_line = true;
            }
            else if( !dragged || restart_line )
            {
                restart_line = false;
#if ! DEBUG
                this->drawing_pad.draw_point( touch.px, touch.py );
                old_touch = touch;
#endif
            }
            else if( dragged )
            {
#if ! DEBUG
                this->drawing_pad.draw_line( touch.px, touch.py, old_touch.px, old_touch.py );
                old_touch = touch;
#endif
            }
            std::cout << "x: " << touch.px << " y: " << touch.py << " a: " << area << std::endl;
            dragged = true;
        }
        if( keysUp() & KEY_TOUCH )
        {
            dragged = false;
        }
        swiWaitForVBlank();
    }
}
