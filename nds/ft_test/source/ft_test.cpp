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
#include "time.h"

#define DEBUG 0

const std::string STATE_FILE_NAME = "ft_test.sav";
const int MIN_SAVE_PERIOD = 5;
const int AUTO_SAVE_PERIOD = 30;

union State
{
    struct
    {
        int word_index;
    } data;
    char sugar_cube[4096];
};
State state;

void save_state( int word_index )
{
    FILE* stf = fopen( STATE_FILE_NAME.c_str(), "w" );
    if( stf )
    {
        state.data.word_index = word_index;
        std::cout << "writing: " << STATE_FILE_NAME << std::endl;
        fwrite( &state, sizeof(state), 1, stf );
        fflush( stf );
        fclose( stf );
    }
    else std::cout << "error opening: " << STATE_FILE_NAME << std::endl;
}

int load_state()
{
    FILE* stf = fopen( STATE_FILE_NAME.c_str(), "r" );
    if( stf )
    {
        std::cout << "reading: " << STATE_FILE_NAME << std::endl;
        fread( &state, sizeof(state), 1, stf );
        int word_index = state.data.word_index;
        fclose( stf );
        return word_index;
    }
    else std::cout << "error opening: " << STATE_FILE_NAME << std::endl;
    return 0;
}


int main()
{
#if DEBUG
    consoleDemoInit();
#else
    DrawingPad dp;
    dp.render_buttons();
#endif
    
    init_all_words_lesson();

    bool fat_initialized = fatInitDefault();
    FreetypeRenderer ft( "ukai.ttf", "VeraSe.ttf" );
	if( !fat_initialized )
	{
	    std::cout << "error initializing fat driver" << std::endl;
	    //while( true ) swiWaitForVBlank();
	}
     
    touchPosition old_touch;
    touchRead( &old_touch );
    Lesson& lesson = all_words_lesson;
    Lesson::iterator word_it = lesson.begin();

    int word_index = 0;
    if( fat_initialized )
    {
        word_index = load_state();
        for( int i=0; i<word_index && word_it!=lesson.end(); i++ )
        {
            word_it++;
        }
        if( word_it == lesson.end() )
        {
            std::cout << "warning: " << STATE_FILE_NAME << " id out of bounds" << std::endl;
            word_it--;
        }
        (*word_it)->render( ft );
    }
    
    bool dragged = false;
    bool restart_line = false;
    time_t curr_time = time(0);
    time_t prev_time = curr_time;
    int prev_saved_word_index = word_index;
    while( true )
    {
        curr_time = time(0);
        if( fat_initialized 
            && curr_time > (prev_time + AUTO_SAVE_PERIOD)
            && word_index != prev_saved_word_index )
        {
            save_state( word_index );
            prev_time = curr_time;
            prev_saved_word_index = word_index;
         }
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
                        if( fat_initialized ) 
                        {
                            (*word_it)->render( ft );
                            if( curr_time > (prev_time + AUTO_SAVE_PERIOD) 
                                && word_index != prev_saved_word_index )
                            {
                                save_state( word_index );
                                prev_time = curr_time;
                                prev_saved_word_index = word_index;
                            }
                        }
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
                        if( fat_initialized ) 
                        {
                            (*word_it)->render( ft );
                            if( curr_time > (prev_time + AUTO_SAVE_PERIOD) 
                                && word_index != prev_saved_word_index )
                            {
                                save_state( word_index );
                                prev_time = curr_time;
                                prev_saved_word_index = word_index;
                            }
                        }
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
                    if( fat_initialized ) 
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
                    if( fat_initialized ) 
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
                    if( fat_initialized ) 
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
