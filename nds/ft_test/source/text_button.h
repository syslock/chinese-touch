#ifndef TEXT_BUTTON_H
#define TEXT_BUTTON_H

#include <string>
#include <list>

class RenderScreen;

class TextButton
{
public:
	OamState* oam;
	std::string text;
	int width, height, x, y;
	u16 *text_vram, *bg_vram, *bg_active_vram, *bg_inactive_vram;
	bool active;
public:
	TextButton( OamState* _oam, const std::string& _text, int _width, int _height, int _x, int _y );
	~TextButton();
	void render_to( RenderScreen& render_screen );
	bool is_responsible( int ref_x, int ref_y );
};

class TextButtonList : public std::list<TextButton*>
{
};

class TextButtonListStorage : public TextButtonList
{
public:
	~TextButtonListStorage();
};

#endif