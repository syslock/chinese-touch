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
	RenderScreen( int _res_x=256, int _res_y=192 ) 
		: id(0), base_address(0), palette(0), 
			res_x(_res_x), res_y(_res_y) {}
	void init( int _id )
	{
		this->id = _id;
		this->base_address = bgGetGfxPtr( _id );
		bgSetPriority( _id, 2 );
	}
	void clear( int color=0 );
public:
	int id;
	u16* base_address;
	u16* palette;
    int res_x, res_y;
};


class RenderScreenBuffer : public RenderScreen
{
public:
	RenderScreenBuffer( int _res_x, int _res_y )
		: RenderScreen( _res_x, _res_y )
	{
		int size = this->res_x*this->res_y*1;
		this->base_address = (u16*)malloc( size );
		this->clear();
	}
	~RenderScreenBuffer()
	{
		free( this->base_address );
	}
	void render_to( RenderScreen& dest, int x, int y, bool replace=false );
};


class RenderChar
{
public:
    RenderChar( UCChar _uc_char, unsigned long _glyph_index ) 
        : x(0), y(0), width(0), height(0), 
          uc_char(_uc_char), glyph_index(_glyph_index), 
          line_begin(false), curr_line_end_char(0) {}
public:
    int x, y, width, height;
	UCChar uc_char;
    unsigned long glyph_index;
    bool line_begin;
    RenderChar* curr_line_end_char;
};

class RenderCharList : public std::list<RenderChar*>
{
public:
	~RenderCharList();
};


class FreetypeRenderer
{
public:
    FreetypeRenderer( const std::string& han_font, 
                    const std::string& latin_font );
    ~FreetypeRenderer();
	void init_screen( Screen screen, RenderScreen& render_screen );
    RenderRect render( const RenderScreen& render_screen, const std::string& text, FT_Face& face, int pixel_size, 
                int x, int y, RenderStyle* render_style=0, RenderCharList* render_char_list=0 );
    RenderRect render( const RenderScreen& render_screen, UCCharList& char_list, FT_Face& face, int pixel_size, 
                int x, int y, RenderStyle* render_style=0, RenderCharList* render_char_list=0 );
public:
    FT_Error error;
    FT_Face han_face, latin_face;
    FT_Library library;
    int dpi_x, dpi_y;
};

#endif // FREETYPE_RENDERER_H
