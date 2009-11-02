#ifndef TEXT_VIEW_H
#define TEXT_VIEW_H

#include "freetype_renderer.h"
#include "lesson.h"
#include "config.h"
#include "dictionary.h"

class BufferedLine : public RenderScreenBuffer
{
public:
	RenderCharList render_char_list;
	int top;
	int last_frame_rendered;
public:
	BufferedLine() : RenderScreenBuffer(256, 16), top(0), last_frame_rendered(0) {};
};

class TextView : private std::list<BufferedLine*>
{
public:
	FreetypeRenderer& freetype_renderer;
	Config& config;
	Text& text;
	Dictionary& dict;
	RenderScreen word_screen, text_screen;
	int y_offset;
	int v_y;
	int frame_count;
	NewWordSet current_new_word_set;
	NewWordSet::iterator current_new_word_set_it;
	RenderScreenBuffer* current_highlight;
	int current_highlight_x, current_highlight_y;
	static int LINE_HEIGHT;
public:
	TextView( FreetypeRenderer& _ft, Config& _config, Text& _text, Dictionary& _dict );
	~TextView();
	void render( Screen screen );
	void run_until_exit();
};

#endif // TEXT_VIEW_H