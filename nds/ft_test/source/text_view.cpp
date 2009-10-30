#include "text_view.h"
#include "unicode.h"
#include "error_console.h"


TextView::TextView( FreetypeRenderer& _ft, Config& _config, Text& _text, Dictionary& _dict )
	: freetype_renderer(_ft), config(_config), text(_text), dict(_dict)
{
	UCCharList char_list;
	if( !utf8_to_ucs4((unsigned char*)text.c_str(), char_list) )
    {
        WARN( "error in utf-8 input (non fatal)" );
    }
	unsigned int prev_size = 0;
	ErrorConsole::init_screen( SCREEN_MAIN );
	std::cout << "TextView(): while..." << std::endl;
	while( prev_size!=char_list.size() )
	{
		std::cout << "TextView(): noch " << char_list.size() << " (" << char_list.begin()->code_point << ")" << std::endl;
		std::cout.flush();
		// break when no characters where consumed within two consecutive iterations
		// 		to prevent endless loops
		prev_size = char_list.size();
		BufferedLine* buffered_line = new BufferedLine();
		RenderStyle render_style;
		render_style.linebreak = false;
		RenderRect rect = this->freetype_renderer.render( *buffered_line, char_list, 
			this->freetype_renderer.han_face, 10, 0, 0, &render_style, &buffered_line->render_char_list );
		this->push_back( buffered_line );
	}
	std::cout << "TextView(): init_screen" << std::endl;
	//this->freetype_renderer.init_screen( SCREEN_MAIN, this->word_screen );
	this->freetype_renderer.init_screen( SCREEN_SUB, this->text_screen );
	std::cout << "TextView(): fertig" << std::endl;
}

TextView::~TextView()
{
	std::cout << "~TextView()" << std::endl; std::cout.flush();
	for( TextView::iterator tv_it = this->begin();
		tv_it != this->end(); tv_it++ )
	{
		if( *tv_it ) delete *tv_it;
	}
}

void TextView::render()
{
	std::cout << "render()" << std::endl; std::cout.flush();
	this->text_screen.clear();
	int top = 0;
	for( TextView::iterator line_it = this->begin();
		line_it != this->end() && top<this->text_screen.res_y; line_it++, top+=16 )
	{
		(*line_it)->render_to( this->text_screen, 0, top );
	}
}
