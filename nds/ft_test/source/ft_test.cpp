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

int main()
{
    init_all_words_lesson();
    //consoleDemoInit();

    DrawingPad dp;

    bool fat_initialized = fatInitDefault();
    FreetypeRenderer ft( "ukai.ttf", "VeraSe.ttf" );
	if( !fat_initialized )
	{
	    std::cout << "error initializing fat driver" << std::endl;
	    while( true ) swiWaitForVBlank();
	}
      
    touchPosition old_touch;
    touchRead( &old_touch );
    Lesson& lesson = all_words_lesson;
    Lesson::iterator word_it = lesson.begin();
    (*word_it)->render( ft );
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
                    std::cout << "prev" << std::endl;
                    (*word_it)->render( ft );
                }
            }
            else if( touch.px > (ft.res_x-15) && touch.py < 15 )
            {
                word_it++;
                if( word_it != lesson.end() )
                {
                    std::cout << "next" << std::endl;
                    (*word_it)->render( ft );
                }
                else
                {
                    word_it--;
                }
            }
            else if( touch.px > (ft.res_x-15) && touch.py > (ft.res_y-15) )
            {
                dp.clear();
            }
            else if( touched )
            {
                dp.draw_line( touch.px, touch.py, old_touch.px, old_touch.py );
            }
            else
            {
                dp.draw( touch.px, touch.py );
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
