#ifndef TEXT_VIEW_H
#define TEXT_VIEW_H

#include "freetype_renderer.h"
#include "lesson.h"
#include "config.h"
#include "dictionary.h"

class BufferedLine : public RenderScreenBuffer
{
public:
	int char_offset, char_count;
public:
	BufferedLine() : RenderScreenBuffer(256, 16), char_offset(0), char_count(0) {};
};

class TextView : private std::list<BufferedLine*>
{
public:
	FreetypeRenderer& freetype_renderer;
	Config& config;
	Text& text;
	Dictionary& dict;
public:
	TextView( FreetypeRenderer& _ft, Config& _config, Text& _text, Dictionary& _dict );
	~TextView();
};

#endif // TEXT_VIEW_H