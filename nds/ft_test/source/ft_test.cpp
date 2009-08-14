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


int main()
{
    init_all_words_lesson();
    consoleDemoInit();

    bool fat_initialized = fatInitDefault();
    FreetypeRenderer ft( "ukai.ttf", "VeraSe.ttf" );
	if( !fat_initialized )
	{
	    std::cout << "error initializing fat driver" << std::endl;
	    std::cout << "starting bg render test" << std::endl;
	    for( int row=0; row<256; row++ )
	    {
	        for( int col=0; col<256/2; col++ )
	        {
	            u16* base_address = bgGetGfxPtr(ft.bg3)+row*256/2+col;
	            u16 value = ((2*col) << 8) + (2*col+1);
	            *base_address = value;
            }
            swiWaitForVBlank();
        }
        std::cout << "ready" << std::endl;
	    while( true ) swiWaitForVBlank();
	}
      
#if 0
    int pixel_size;
    int y;
    for( pixel_size=5, y=0; pixel_size<70; pixel_size*=1.5 )
    {
        ft.render( "你好：nǐhǎo", ft.han_face, pixel_size, 0, y );
        y += pixel_size;
    }
#endif
    touchPosition old_touch;
    touchRead( &old_touch );
    Lesson& lesson = all_words_lesson;
    Lesson::iterator word_it = lesson.begin();
    (*word_it)->render( ft );
    while( true )
    {
        scanKeys();
        touchPosition touch;
        touchRead( &touch );
        int area = touch.px * touch.z2 / touch.z1 - touch.px;
        if( keysHeld() & KEY_TOUCH 
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
            if( touch.px > (ft.res_x-15) && touch.py < 15 )
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
            std::cout << "x: " << touch.px << " y: " << touch.py << " a: " << area << std::endl;
            old_touch = touch;
        }
        swiWaitForVBlank();
    }
    return 0;
}
