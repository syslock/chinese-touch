#ifndef FREETYPE_RENDERER_H
#define FREETYPE_RENDERER_H

#include <map>
#include <string>

#include <ft2build.h>
#include FT_FREETYPE_H

#include <nds.h>

#include "unicode.h"
#include "screen.h"

typedef std::map<int,const char*> ErrorMap;
extern ErrorMap ft_errors;

class RenderStyle
{
public:
    RenderStyle() : center_x(false), center_y(false), 
            linebreak(true), autoscale(false) {}
public:
    bool center_x, center_y, linebreak, autoscale;
};

class RenderRect
{
public:
    RenderRect( int _x, int _y, int _width, int _height )
        : x(_x), y(_y), width(_width), height(_height) {}
public:
    int x, y, width, height;
};

class RenderScreen
{
public:
	RenderScreen() : id(0), base_address(0), palette(0) {}
	void init( int _id )
	{
		this->id = _id;
		this->base_address = bgGetGfxPtr( _id );
	}
public:
	int id;
	u16* base_address;
	u16* palette;
};

class FreetypeRenderer
{
public:
    FreetypeRenderer( const std::string& han_font, 
                    const std::string& latin_font );
    ~FreetypeRenderer();
	void init_screen( Screen screen, RenderScreen& render_screen );
	void clear_screen( const RenderScreen& render_screen );
    RenderRect render( const RenderScreen& render_screen, const std::string& text, FT_Face& face, int pixel_size, 
                int x, int y, RenderStyle* render_style=0 );
public:
    FT_Error error;
    FT_Face han_face, latin_face;
    FT_Library library;
    int dpi_x, dpi_y;
    int bg3;
    int res_x, res_y;
};

#endif // FREETYPE_RENDERER_H
