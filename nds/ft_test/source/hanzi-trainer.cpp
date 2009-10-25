#include <fstream>
#include <string.h>
#include <iomanip>
#include <map>

#include <nds.h>
#include <fat.h>

#include "hanzi-trainer.h"
#include "freetype_renderer.h"
#include "unicode.h"
#include "lesson.h"
#include "drawing_pad.h"
#include "config.h"
#include "error_console.h"
#include "lesson_menu.h"
#include "new_words.h"

int main()
{
	try
	{
		INIT_LOG();
		LOG( "initializing fat driver" );
		global_fat_initialized = fatInitDefault();
		if( !global_fat_initialized )
		{
			throw ERROR( "error initializing fat driver" );
		}

		LOG( "initializing library" );
		Library library( global_fat_initialized );
		LOG( "scanning library..." );
		library.rescan();
		LOG( "scanning complete" );
		if( !library.size() )
		{
			ErrorConsole::init();
			LOG( "warning: empty library" );
			std::string book_name = "dummy book";
			library[ book_name ] = new Book( book_name, &library);
		}
		Book& book = *library.begin()->second;
		if( !book.size() )
		{
			ErrorConsole::init();
			LOG( "warning: empty book \"" <<  book.name << "\"" );
			int lesson_number = 1;
			book[ lesson_number ] = new Lesson( lesson_number, &book );
		}

		LOG( "initializing Freetype" );
		FreetypeRenderer* ft = new FreetypeRenderer( "ukai.ttf", "VeraSe.ttf" );

		Config config;
		LOG( "loading config" );
		config.load();

		while( true )
		{
			try
			{
				/* Testlauf des Lektionsauswahlmenüs: */
				LOG( "initializing lesson menu" );
				LessonMenu* lesson_menu = new LessonMenu( *ft, library, config );
				LessonMenuChoice lesson_menu_choice;
				lesson_menu->run_for_user_choice( lesson_menu_choice );
				delete lesson_menu;

				/* Testlauf des Vokabeltrainers: */
				if( lesson_menu_choice.lesson )
				{
					switch( lesson_menu_choice.content_type )
					{
						case LessonMenuChoice::CONTENT_TYPE_NEW_WORDS:
						{
							NewWords* new_words = new NewWords( *ft, *lesson_menu_choice.lesson, config );
							new_words->run_until_exit();
							delete new_words;
							break;
						}
						case LessonMenuChoice::CONTENT_TYPE_GRAMMAR:
						{
							throw ERROR( "Display of grammar texts is still not implemented" );
						}
						case LessonMenuChoice::CONTENT_TYPE_TEXT:
						{
							throw ERROR( "Display of lesson texts is still implemented" );
						}
						case LessonMenuChoice::CONTENT_TYPE_EXERCISES:
						{
							throw ERROR( "Display of excercises is still not implemented" );
						}
						default: throw ERROR( "LessonMenu returned invalid content type!" );
					}
				}
				else throw ERROR( "LessonMenu returned no lesson!" );
			}
			catch( Error& e )
			{
				RenderScreen error;
				ft->init_screen( SCREEN_MAIN, error );
				error.clear();
				ft->render( error, e.what(), ft->latin_face, 8, 3, 3 );
				for( int i=0; i<500; i++ ) swiWaitForVBlank();
			}
		}
	}
	catch( Error& e )
	{
		ErrorConsole::init();
		std::cout << e.what() << std::endl;
	}
	catch( std::exception& e )
	{
		ErrorConsole::init();
		std::cout << "unknown std::exception: " << e.what() << std::endl;
	}
    return 0;
}
