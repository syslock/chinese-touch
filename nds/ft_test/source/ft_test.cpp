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
      
    for( Lesson::iterator word_it = all_words_lesson.begin(); 
        word_it != all_words_lesson.end(); word_it++ )
    {
        (*word_it)->render( ft );
        for( int i=0; i<100; i++ ) swiWaitForVBlank();
    }
        
    std::cout << "clean exit" << std::endl;
    
    while( true ) swiWaitForVBlank();
}
