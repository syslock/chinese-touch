#include "text_view.h"
#include "unicode.h"
#include "error_console.h"


int TextView::LINE_HEIGHT = 16;

TextView::TextView( FreetypeRenderer& _ft, Config& _config, Text& _text, Dictionary& _dict )
	: freetype_renderer(_ft), config(_config), text(_text), dict(_dict), y_offset(5), v_y(0),
		current_new_word_set_it(this->current_new_word_set.begin()), current_highlight(0),
		current_highlight_x(0), current_highlight_y(0), context_mode(CONTEXT_WORDS_BY_CONTEXT),
		context_render_char(0)
{
	this->freetype_renderer.init_screen( SCREEN_MAIN, this->word_screen );
	this->word_screen.clear();
	this->freetype_renderer.init_screen( SCREEN_SUB, this->text_screen );
	this->text_screen.clear();
	
	UCCharList char_list;
	if( !utf8_to_ucs4((unsigned char*)text.c_str(), char_list) )
    {
        WARN( "error in utf-8 input (non fatal)" );
    }
	unsigned int prev_size = 0;
	RenderInfo info( 0, 0, 0, 0 );
	while( prev_size!=char_list.size() )
	{
		// break when no characters where consumed within two consecutive iterations
		// 		to prevent endless loops
		prev_size = char_list.size();
		BufferedLine* buffered_line = new BufferedLine();
		RenderStyle render_style;
		render_style.linebreak = false;
		render_style.indentation_offset = info.indentation_offset;
		info = this->freetype_renderer.render( *buffered_line, char_list, 
			this->freetype_renderer.han_face, 10, 0, 0, &render_style, &buffered_line->render_char_list );
		this->push_back( buffered_line );
	}
}

TextView::~TextView()
{
	if( this->current_highlight ) delete this->current_highlight;
	for( TextView::iterator tv_it = this->begin();
		tv_it != this->end(); tv_it++ )
	{
		if( *tv_it ) delete *tv_it;
	}
}

void TextView::render( Screen screen )
{
	this->frame_count++;
	if( screen == SCREEN_MAIN )
	{
		this->word_screen.clear();
		if( this->current_new_word_set_it != this->current_new_word_set.end() )
		{
			NewWord* new_word = *this->current_new_word_set_it;
			new_word->render( this->freetype_renderer, this->word_screen );
		}
	}
	else if( screen == SCREEN_SUB )
	{
		int top = this->y_offset;
		this->text_screen.clear( 1 );
		if( this->current_highlight )
		{
			this->current_highlight->render_to( this->text_screen, 
				this->current_highlight_x, this->current_highlight_y+this->y_offset,
				/*replace=*/true );
		}
		for( TextView::iterator line_it = this->begin();
			line_it != this->end() && top<this->text_screen.res_y; 
			line_it++, top+=TextView::LINE_HEIGHT )
		{
			if( top > -TextView::LINE_HEIGHT )
			{
				(*line_it)->render_to( this->text_screen, 0, top );
				(*line_it)->top = top;
				(*line_it)->last_frame_rendered = this->frame_count;
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
			touched = false;
            if( old_touch.px < 15 && old_touch.py > (this->text_screen.res_y-15) )
            {
				this->config.save_position( this->text.lesson );
				return;
            }
            else if( old_touch.px < 15 && old_touch.py < 15 )
            {
				if( this->current_new_word_set_it != this->current_new_word_set.begin() )
				{
					this->current_new_word_set_it--;
					this->render( SCREEN_MAIN );
				}
			}
            else if( old_touch.px > (this->text_screen.res_x-15) && old_touch.py < 15 )
            {
				if( this->current_new_word_set_it != this->current_new_word_set.end() )
				{
					if( ++this->current_new_word_set_it == this->current_new_word_set.end() )
					{
						this->current_new_word_set_it--;
					}
					else
					{
						this->render( SCREEN_MAIN );
					}
				}
			}
			else
			{
				// Dictionary nach relevanten Treffern durchsuchen:
				bool found = false;
				TextView::iterator prev_line_it = this->end();
				for( TextView::iterator line_it = this->begin();
					!found && line_it != this->end() && (*line_it)->top<this->text_screen.res_y; 
					prev_line_it=line_it++ )
				{
					BufferedLine* line = *line_it;
					if( line->last_frame_rendered==this->frame_count
						&& old_touch.py > line->top  
						&& old_touch.py < line->top+TextView::LINE_HEIGHT  )
					{
						// create and fill tempory search list containing characters of 3 successive lines
						// for multi line context matches:
						UCCharList search_char_list;
						UCCharList::iterator search_char_it = search_char_list.begin();
						typedef std::list<TextView::iterator> SearchLineIterators;
						SearchLineIterators search_line_its;
						if( prev_line_it!=this->end() ) search_line_its.push_back( prev_line_it );
						search_line_its.push_back( line_it );
						TextView::iterator next_line_it = line_it; next_line_it++;
						if( next_line_it!=this->end() ) search_line_its.push_back( next_line_it );
						for( SearchLineIterators::iterator sli = search_line_its.begin();
							sli != search_line_its.end();
							sli++ )
						{
							for( RenderCharList::iterator r_it = (*(*sli))->render_char_list.begin();
								r_it != (*(*sli))->render_char_list.end();
								r_it++ )
							{
								search_char_list.push_back( (*r_it)->uc_char );
								// initiate search character position to first character of current line:
								if( r_it == line->render_char_list.begin() )
								{
									search_char_it = search_char_list.end(); search_char_it--;
								}
							}
						}
						// find character clicked on:
						for( RenderCharList::iterator char_it = line->render_char_list.begin();
							!found && char_it != line->render_char_list.end();
							char_it++, search_char_it++ )
						{
							RenderChar* curr_char = *char_it;
							if( old_touch.px > curr_char->x && old_touch.px < curr_char->x+curr_char->width )
							{
								if( this->context_render_char != curr_char 
									|| this->context_mode != CONTEXT_WORDS_BY_CONTEXT )
								{
									// first click (odd count) on a character: find words in current context:
									this->dict.find_words_by_context( this->text, search_char_list, search_char_it, 6, this->current_new_word_set );
									this->context_mode = CONTEXT_WORDS_BY_CONTEXT;
									// Farbindex 0 der Hintergrundpalette auf orange für's Highlight setzen:
									this->text_screen.palette[0] = 16<<10|24<<5|31;
								}
								else
								{
									// second click (even count) on a character: find words containing selected character:
									this->dict.find_words_by_char_code( curr_char->uc_char.code_point, this->current_new_word_set );
									this->context_mode = CONTEXT_WORDS_BY_CHARCODE;
									// Farbindex 0 der Hintergrundpalette auf blau für's Highlight setzen:
									this->text_screen.palette[0] = 31<<10|24<<5|24;
								}
								this->context_render_char = curr_char;
								this->current_new_word_set_it = this->current_new_word_set.begin();
								// (re-)define and render highlight for selected character in text view:
								if( this->current_highlight ) delete this->current_highlight;
								this->current_highlight = new RenderScreenBuffer( curr_char->width, TextView::LINE_HEIGHT );
								this->current_highlight->clear();
								this->current_highlight_x = curr_char->x;
								this->current_highlight_y = line->top-this->y_offset+curr_char->y-1;
								this->render( SCREEN_SUB );
								// render first search result on main screen:
								this->render( SCREEN_MAIN );
								found = true;
								break;
							}
						}
					}
				}
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
