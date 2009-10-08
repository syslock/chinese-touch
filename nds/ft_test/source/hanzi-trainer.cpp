#include <iostream>
#include <fstream>
#include <string.h>
#include <iomanip>
#include <map>

#include <nds.h>
#include <fat.h>

#include "freetype_renderer.h"
#include "unicode.h"
#include "lesson.h"
#include "drawing_pad.h"
#include "config.h"
#include "error_console.h"
#include "lesson_menu.h"

#ifndef DEBUG
#define DEBUG 0
#endif


int main()
{
#if DEBUG
    ErrorConsole::init();
#endif
    
    std::cout << "initializing fat driver" << std::endl;
    global_fat_initialized = fatInitDefault();
	if( !global_fat_initialized )
	{
	    ErrorConsole::init();
	    std::cout << "error initializing fat driver" << std::endl;
	}

	std::cout << "initializing config" << std::endl;
    Config config;
    std::cout << "loading config" << std::endl;
    config.load();
    std::cout << "initializing library" << std::endl;
    Library library( global_fat_initialized );
    std::cout << "scanning library..." << std::endl;
    library.rescan();
    std::cout << "scanning complete" << std::endl;
    if( !library.size() )
    {
	    ErrorConsole::init();
        std::cout << "warning: empty library" << std::endl;
        std::string book_name = "dummy book";
        library[ book_name ] = new Book( book_name, &library);
    }

	/* Testlauf des Lektionsauswahlmenüs: */
	std::cout << "initializing lesson menu" << std::endl;
	LessonMenu lesson_menu( "ukai.ttf", "VeraSe.ttf" );

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
            dragged = true;
		}
        if( keysUp() & KEY_TOUCH )
        {
            dragged = false;
			break;
        }
		swiWaitForVBlank();
	}

	/* Testlauf des Vokabeltrainers mit statischer Lektion und 
		gespeichertem Wortindex: */
	std::cout << "initializing drawing pad" << std::endl;
	DrawingPad dp;
    dp.render_buttons();
	std::cout << "initializing word view" << std::endl;
    FreetypeRenderer ft( "ukai.ttf", "VeraSe.ttf", SCREEN_MAIN );
     
	Book& book = *library.begin()->second;
    if( !book.size() )
    {
	    ErrorConsole::init();
        std::cout << "warning: empty book \"" << book.name << "\"" << std::endl;
        int lesson_number = 1;
        book[ lesson_number ] = new Lesson( lesson_number, &book );
    }
    Lesson& lesson = *book.begin()->second;
    if( !lesson.size() )
    {
	    ErrorConsole::init();
        std::cout << "warning: empty lesson \"" << lesson.name << "\"" << std::endl;
        Word* word = new Word( "汉字", "hànzì", &lesson, 0 );
        Definition* definition = new Definition();
        definition->lang = "de";
        definition->translation = "Chinesische Schrift";
        definition->word_type = "N";
        word->definitions[ definition->lang ] = definition;
        lesson.push_back( word );
    }

	Lesson::iterator word_it = lesson.begin();
    int word_index = (*word_it)->number;
    if( global_fat_initialized )
    {
        word_index = config.get_current_word_number();
        for( word_it=lesson.begin(); (*word_it)->number < word_index 
                && word_it!=lesson.end(); word_it++ );
        if( word_it == lesson.end() )
        {
	        ErrorConsole::init();
            std::cout << "warning: " << CONFIG_FILE_NAME << " id out of bounds" << std::endl;
            word_it--;
        }
        word_index = (*word_it)->number;
        (*word_it)->render( ft );
    }
    
    touchRead( &old_touch );
	dragged = false;
    bool restart_line = false;
    while( true )
    {
        config.save_position( *word_it );
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
                        config.save_position( *word_it );
                        (*word_it)->render( ft );
                    }
                } else restart_line = true;
            }
            else if( touch.px > (ft.res_x-15) && touch.py < 15 )
            {
                if( !dragged )
                {
                    word_it++;
                    word_index++;
                    if( word_it != lesson.end() )
                    {
                        std::cout << "next" << std::endl;
                        config.save_position( *word_it );
                        (*word_it)->render( ft );
                    }
                    else
                    {
                        word_it--;
                        word_index--;
                    }
                } else restart_line = true;
            }
            else if( touch.px > (ft.res_x-15) && touch.py > (ft.res_y-15) )
            {
                if( !dragged )
                {
#if ! DEBUG
                    dp.render_buttons();
                    //dp.clear();
#endif
                } else restart_line = true;
            }
            else if( touch.px < 15 && touch.py > (ft.res_y-15) )
            {
                if( !dragged )
                {
                    std::cout << "menu" << std::endl;
                } else restart_line = true;
            }
            else if( touch.py < 20 && touch.px > 84 && touch.px < 108 ) // hanzi
            {
                if( !dragged )
                {
                    lesson.toggle_hanzi();
                    if( global_fat_initialized ) 
                    {
                        (*word_it)->render( ft );
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
                        (*word_it)->render( ft );
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
                        (*word_it)->render( ft );
                    }
                } else restart_line = true;
            }
            else if( !dragged || restart_line )
            {
                restart_line = false;
#if ! DEBUG
                dp.draw_point( touch.px, touch.py );
                old_touch = touch;
#endif
            }
            else if( dragged )
            {
#if ! DEBUG
                dp.draw_line( touch.px, touch.py, old_touch.px, old_touch.py );
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
    return 0;
}
