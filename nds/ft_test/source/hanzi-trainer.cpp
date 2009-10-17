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
#include "new_words.h"

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
	Book& book = *library.begin()->second;
	if( !book.size() )
	{
		ErrorConsole::init();
		std::cout << "warning: empty book \"" << book.name << "\"" << std::endl;
		int lesson_number = 1;
		book[ lesson_number ] = new Lesson( lesson_number, &book );
	}

	std::cout << "initializing Freetype" << std::endl;
    FreetypeRenderer* ft = new FreetypeRenderer( "ukai.ttf", "VeraSe.ttf" );

	Config config;
	std::cout << "loading config" << std::endl;
	config.load();

	while( true )
	{
		try
		{
			/* Testlauf des Lektionsauswahlmenüs: */
			std::cout << "initializing lesson menu" << std::endl;
			LessonMenu* lesson_menu = new LessonMenu( *ft, library );
			LessonMenuChoice lesson_menu_choice;
			lesson_menu->run_for_user_choice( lesson_menu_choice );
			delete lesson_menu;

			/* Testlauf des Vokabeltrainers: */
			if( lesson_menu_choice.lesson )
			{
				NewWords* new_words = new NewWords( *ft, *lesson_menu_choice.lesson, config );
				new_words->run_until_exit();
				delete new_words;
			}
			else
			{
				ErrorConsole::init();
				std::cout << "LessonMenu returned invalid choice!" << std::endl;
			}
		}
		catch( std::exception& e )
		{
			ErrorConsole::init();
			std::cout << e.what() << std::endl;
			for( int i=0; i<500; i++ ) swiWaitForVBlank();
		}
	}
    return 0;
}
