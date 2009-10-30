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
#include "text_view.h"

int main()
{
	defaultExceptionHandler();
	try
	{
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
			WARN( "empty library" );
			std::string book_name = "dummy book";
			library[ book_name ] = new Book( book_name, &library);
		}
		Book& book = *library.begin()->second;
		if( !book.size() )
		{
			WARN( "empty book \"" <<  book.name << "\"" );
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
							NewWordsViewer* new_words = new NewWordsViewer( *ft, *lesson_menu_choice.lesson, config );
							new_words->run_until_exit();
							delete new_words;
							break;
						}
						case LessonMenuChoice::CONTENT_TYPE_GRAMMAR:
						{
							throw ERROR( "Die Anzeige der Grammatik ist noch nicht implementiert" );
							break;
						}
						case LessonMenuChoice::CONTENT_TYPE_TEXT:
						{
							Dictionary dict;
							Text* text = new Text( "foobar", lesson_menu_choice.lesson );
/*							text->append( "课文 这是爸爸\n"
										"这是爸爸，这是妈妈。\n"
										"这是姐姐和妹妹。\n"
										"那是哥哥，那是弟弟。\n"
										"那是爷爷和奶奶。\n"
										"这是猫，这是狗。\n"
										"这是猫和狗。\n" );
*/
							text->append( "「《施氏食獅史》\n"
										"石室詩士施氏，嗜獅，誓食十獅。\n"
										"氏時時適市視獅。\n"
										"十時，適十獅適市。\n"
										"是時，適施氏適市。\n"
										"氏視是十獅，恃矢勢，使是十獅逝世。\n"
										"氏拾是十獅屍，適石室。\n"
										"石室濕，氏使侍拭石室。\n"
										"石室拭，氏始試食是十獅。\n"
										"食時，始識是十獅，實十石獅屍。\n"
										"試釋是事。」" );
							TextView* text_view = new TextView( *ft, config, *text, dict );
							text_view->render();
							for( int i=0; i<500; i++ ) swiWaitForVBlank();
							delete text_view;
							delete text;
							break;
						}
						case LessonMenuChoice::CONTENT_TYPE_EXERCISES:
						{
							throw ERROR( "Die Anzeige von Übungsaufgaben ist noch nicht implementiert" );
							break;
						}
						default: throw ERROR( "LessonMenu returned invalid content type!" );
					}
				}
				else throw ERROR( "LessonMenu returned no lesson!" );
			}
			catch( Error& e )
			{
				RenderScreen error_screen;
				ft->init_screen( SCREEN_MAIN, error_screen );
				error_screen.clear();
				ft->render( error_screen, e.what(), ft->latin_face, 8, 3, 3 );
				error_stream << "caught " << e.what() << std::endl;
				for( int i=0; i<500; i++ ) swiWaitForVBlank();
			}
		}
	}
	catch( Error& e )
	{
		error_stream << "caught " << e.what() << std::endl;
		ErrorConsole::init_screen();
	}
	catch( std::exception& e )
	{
		error_stream << "caught " << e.what() << std::endl;
		ErrorConsole::init_screen();
	}
    return 0;
}
