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

#define DEBUG 0

const std::string save_state_name = "ft_test.sav";

union SaveState
{
    struct
    {
        int word_index;
    } data;
    char sugar_cube[4096];
};
SaveState save_state;

int main()
{
#if DEBUG
    consoleDemoInit();
#else
    DrawingPad dp;
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
        FILE* stf = fopen( save_state_name.c_str(), "r" );
        if( stf )
        {
            fread( &save_state, sizeof(save_state), 1, stf );
            word_index = save_state.data.word_index;
            fclose( stf );
        }
        else std::cout << "error opening: " << save_state_name << std::endl;
        for( int i=0; i<word_index && word_it!=lesson.end(); i++ )
        {
            word_it++;
        }
        if( word_it == lesson.end() )
        {
            std::cout << "warning: " << save_state_name << " id out of bounds" << std::endl;
            word_it--;
        }
        (*word_it)->render( ft );
    }
      
    bool touched = false;
    while( true )
    {
        scanKeys();
        touchPosition touch;
        touchRead( &touch );
        int area = touch.px * touch.z2 / touch.z1 - touch.px;
        if( keysCurrent() & KEY_TOUCH 
                && (touch.px!=old_touch.px || touch.py!=old_touch.py) )
        {
            if( touch.px < 15 && touch.py < 15 )
            {
                if( word_it != lesson.begin() )
                {
                    word_it--;
                    word_index--;
                    std::cout << "prev" << std::endl;
                    if( fat_initialized ) (*word_it)->render( ft );
                }
            }
            else if( touch.px > (ft.res_x-15) && touch.py < 15 )
            {
                word_it++;
                word_index++;
                if( word_it != lesson.end() )
                {
                    std::cout << "next" << std::endl;
                    if( fat_initialized ) (*word_it)->render( ft );
                }
                else
                {
                    word_it--;
                    word_index--;
                }
            }
            else if( touch.px > (ft.res_x-15) && touch.py > (ft.res_y-15) )
            {
#if ! DEBUG
                dp.clear();
#endif
            }
            else if( touch.px < 15 && touch.py > (ft.res_y-15) )
            {
                std::cout << "save" << std::endl;
                if( fat_initialized )
                {
                    FILE* stf = fopen( save_state_name.c_str(), "w" );
                    if( stf )
                    {
                        save_state.data.word_index = word_index;
                        fwrite( &save_state, sizeof(save_state), 1, stf );
                        fflush( stf );
                        fclose( stf );
                    }
                    else std::cout << "error opening: " << save_state_name << std::endl;
                }
            }
            else if( touched )
            {
#if ! DEBUG
                dp.draw_line( touch.px, touch.py, old_touch.px, old_touch.py );
#endif
            }
            else
            {
#if ! DEBUG
                dp.draw( touch.px, touch.py );
#endif
            }
            std::cout << "x: " << touch.px << " y: " << touch.py << " a: " << area << std::endl;
            old_touch = touch;
            touched = true;
        }
        if( keysUp() & KEY_TOUCH )
        {
            touched = false;
        }
        swiWaitForVBlank();
    }
    return 0;
}
