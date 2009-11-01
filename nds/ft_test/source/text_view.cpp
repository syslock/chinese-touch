#include "text_view.h"
#include "unicode.h"
#include "error_console.h"


TextView::TextView( FreetypeRenderer& _ft, Config& _config, Text& _text, Dictionary& _dict )
	: freetype_renderer(_ft), config(_config), text(_text), dict(_dict), y_offset(5), v_y(0)
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

void TextView::render( Screen screen )
{
	if( screen == SCREEN_SUB )
	{
		int top = this->y_offset;
		this->text_screen.clear();
		for( TextView::iterator line_it = this->begin();
			line_it != this->end() && top<this->text_screen.res_y; 
			line_it++, top+=16 )
		{
			if( top > -16 )
			{
				(*line_it)->render_to( this->text_screen, 0, top );
			}
		}
	}
}

void TextView::run_until_exit()
{
	this->config.save_position( this->text.lesson );
	this->render( SCREEN_MAIN );
	this->render( SCREEN_SUB );
	touchPosition old_touch;
    touchRead( &old_touch );
	bool touched = false;
	int old_y_offset = this->y_offset;
	while( true )
	{
        scanKeys();
		int pressed = keysDown();
		int held = keysHeld();
		if( held & KEY_SELECT && pressed & KEY_UP )
		{
			ErrorConsole::init_screen( SCREEN_MAIN );
		}
		if( held & KEY_SELECT && pressed & KEY_DOWN )
		{
			ErrorConsole::init_screen( SCREEN_SUB );
		}
		if( held & KEY_SELECT && pressed & KEY_LEFT )
		{
			ErrorConsole::clear();
		}
		if( held & KEY_SELECT && pressed & KEY_RIGHT )
		{
			ErrorConsole::dump();
		}
        touchPosition touch;
        touchRead( &touch );
        int area = touch.px * touch.z2 / touch.z1 - touch.px;
        if( keysCurrent() & KEY_TOUCH )
        {
			if( !touched ) 
			{
				touched = true;
				old_touch = touch;
				old_y_offset = this->y_offset;
			}
			int y_diff = touch.py - old_touch.py;
			if( y_diff )
			{
				this->y_offset += y_diff;
				this->v_y = y_diff;
				this->render( SCREEN_SUB );
			}
			old_touch = touch;
		}
		else if( touched && abs(abs(old_y_offset)-abs(this->y_offset)) < 2 )
		{
			std::cout << "(" << old_touch.px << "," << old_touch.py << ")" << " -> (" << touch.px << "," << touch.py << ")" << std::endl;
			touched = false;
            if( old_touch.px < 15 && old_touch.py > (this->text_screen.res_y-15) )
            {
				//NewWord* word = this->lesson.new_words[ this->word_index ];
				//this->config.save_position( word, this->word_index );
				return;
            }
		}
		else if( this->v_y )
		{
			touched = false;
			int resistance = this->v_y / 4;
			if( !resistance ) resistance = this->v_y / 2;
			if( !resistance ) resistance = this->v_y;
			this->v_y -= resistance;
			this->y_offset += this->v_y;
			this->render( SCREEN_SUB );
		}
        else
        {
			touched = false;
        }
		swiWaitForVBlank();
	}
}
