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
public:
	BufferedLine() : RenderScreenBuffer(256, 16) {};
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
public:
	TextView( FreetypeRenderer& _ft, Config& _config, Text& _text, Dictionary& _dict );
	~TextView();
	void render( Screen screen );
	void run_until_exit();
};

#endif // TEXT_VIEW_H