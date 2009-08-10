#ifndef FREETYPE_RENDERER_H
#define FREETYPE_RENDERER_H

#include <map>
#include <string>

#include <ft2build.h>
#include FT_FREETYPE_H

#include "unicode.h"

typedef std::map<int,const char*> ErrorMap;
extern ErrorMap ft_errors;

class FreetypeRenderer
{
public:
    FreetypeRenderer( const std::string& fontfile_name );
    ~FreetypeRenderer();
    void render( const std::string& text, int pixel_size, int x, int y );
    void render( CharList& char_list, int pixel_size, int x, int y );
    void render_x_centered( const std::string& text, int pixel_size, int y );
public:
    FT_Error error;
    FT_Face face;
    FT_Library library;
    int dpi_x, dpi_y;
    int bg3;
};

#endif // FREETYPE_RENDERER_H
