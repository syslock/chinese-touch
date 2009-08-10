#include <iostream>
#include <fstream>
#include <ft2build.h>
#include FT_FREETYPE_H
#include <string.h>
#include <iomanip>
#include <map>

#include <nds.h>
#include <fat.h>

#include "unicode.h"
#include "lesson.h"

#undef __FTERRORS_H__
#define FT_ERROR_START_LIST     ErrorMap ft_errors; void FT_Init_Errors(){
#define FT_ERRORDEF( e, v, s )  ft_errors[e]=s;
#define FT_ERROR_END_LIST       };

typedef std::map<int,const char*> ErrorMap;
#include FT_ERRORS_H


int main()
{
    init_all_words_lesson();

    // set the mode for 2 text layers and two extended background layers
	videoSetMode(MODE_5_2D);
    vramSetBankA(VRAM_A_MAIN_BG_0x06000000);

    consoleDemoInit();

	int bg3 = bgInit(3, BgType_Bmp8, BgSize_B8_256x256, 0,0);
	// lineare 15-bit-graupalette mit 256 indizes aufbauen:
	for( int i=0; i<256; i++ )
	{
	    int value = (int)( ((double)i)*(double)(1<<5)/256.0 );
	    BG_PALETTE[255-i] = /*(1 << 15) |*/ (value << 10) | (value << 5) | value;
	}


	if( !fatInitDefault() ) 
	{
	    std::cout << "error initializing fat driver" << std::endl;
	    std::cout << "starting bg render test" << std::endl;
	    for( int row=0; row<256; row++ )
	    {
	        for( int col=0; col<256/2; col++ )
	        {
	            u16* base_address = bgGetGfxPtr(bg3)+row*256/2+col;
	            u16 value = ((2*col) << 8) + (2*col+1);
	            *base_address = value;
            }
            swiWaitForVBlank();
        }
        std::cout << "ready" << std::endl;
	    while( true ) swiWaitForVBlank();
	}
    
    FT_Init_Errors();
    std::cout << "ft_errors.size(): " << ft_errors.size() << std::endl;
    char* fontfile_name = "ukai.ttf";
    CharList char_list;    
    const char* input = "你好:nǐhǎo";
    if( !utf8_to_ucs4((unsigned char*)input, char_list) )
    {
        std::cout << "error in utf-8 input (non fatal)" << std::endl;
    }
    
    FT_Error error;
    FT_Library library;
    if( error=FT_Init_FreeType(&library) )
    {
        std::cout << "error initializing freetype: " << ft_errors[error] << std::endl;
        return 2;
    }
    FT_Face face;
    if( error=FT_New_Face(library, fontfile_name, 0, &face) )
    {
        std::cout << "error loading: " << fontfile_name << " (" << ft_errors[error] << ")" << std::endl;
        return 2;
    }
    
    // Setting pixel size
    int pixel_size = 32;
    if( error=FT_Set_Char_Size(face, 0, pixel_size*64, 100, 100) )
    {
        std::cout << "error setting pixel size: " << ft_errors[error] << std::endl;
        return 2;
    }
    
    std::cout << "face properties: " << std::endl;
    std::cout << "num_faces: " << face->num_faces << std::endl;
    std::cout << "face_index: " << face->face_index << std::endl;
    std::cout << "face_flags: " << face->face_flags << std::endl;
    std::cout << "style_flags: " << face->style_flags << std::endl;
    std::cout << "num_glyphs: " << face->num_glyphs << std::endl;
    std::cout << "family_name: " << face->family_name << std::endl;
    std::cout << "style_name: " << face->style_name << std::endl;
    std::cout << "num_fixed_sizes: " << face->num_fixed_sizes << std::endl;
    std::cout << "available_sizes: " << face->available_sizes << std::endl;
    std::cout << "num_charmaps: " << face->num_charmaps << std::endl;
    for( int i=0; i < face->num_charmaps; i++ )
    {
        std::cout << "charmap[" << i << "]: " << face->charmaps[i] << std::endl;
        std::string encoding( (char*)&face->charmaps[i]->encoding, 0, 4 );
        std::cout << "\tencoding: " << encoding << std::endl;
        std::cout << "\tplatform_id: " << face->charmaps[i]->platform_id << std::endl;
        std::cout << "\tencoding_id: " << face->charmaps[i]->encoding_id << std::endl;
    }
//    std::cout << "generic: " << face->generic << std::endl;
//    std::cout << "bbox: " << face->bbox << std::endl;
    std::cout << "units_per_EM: " << face->units_per_EM << std::endl;
    std::cout << "ascender: " << face->ascender << std::endl;
    std::cout << "descender: " << face->descender << std::endl;
    std::cout << "height: " << face->height << std::endl;
    std::cout << "max_advance_width: " << face->max_advance_width << std::endl;
    std::cout << "max_advance_height: " << face->max_advance_height << std::endl;
    std::cout << "underline_position: " << face->underline_position << std::endl;
    std::cout << "underline_thickness: " << face->underline_thickness << std::endl;
    std::cout << "glyph: " << face->glyph << std::endl;
    std::cout << "size: " << face->size << std::endl;
    std::cout << "charmap: " << face->charmap << std::endl;
    std::cout << "driver: " << face->driver << std::endl;
    std::cout << "memory: " << face->memory << std::endl;
    std::cout << "stream: " << face->stream << std::endl;
//    std::cout << "sizes_list: " << face->sizes_list << std::endl;
//    std::cout << "autohint: " << face->autohint << std::endl;
    std::cout << "extensions: " << face->extensions << std::endl;
    std::cout << "internal: " << face->internal << std::endl;
    std::cout << std::endl;
        
#if 0
    // Select charmap
    if( FT_Select_Charmap(face, FT_ENCODING_UNICODE) )
    {
        std::cout << "error loading unicode charmap" << std::endl;
        return 2;
    }
#endif
    
    FT_Vector pen;
    for( pixel_size=5, pen.y=0*64; pixel_size<70; pixel_size*=1.5 )
    {
        // Setting pixel size
        if( error=FT_Set_Char_Size(face, 0, pixel_size*64, 100, 100) )
        {
            std::cout << "error setting pixel size: " << ft_errors[error] << std::endl;
            return 2;
        }
        pen.x = 0*64;
        int max_advance = 0;
        int base_height = 0;
        for( CharList::iterator char_it=char_list.begin(); 
                char_it!=char_list.end() && pen.x/64<256; char_it++ )
        {
            // Load Char
            std::cout << "character code: " << *char_it << std::endl;
            //FT_UInt glyph_index = FT_Get_Name_Index(face, "a");
            FT_UInt glyph_index = FT_Get_Char_Index( face, *char_it );
            if( !glyph_index )
            {
                std::cout << "error translating character code: " << *char_it << std::endl;
                return 2;
            }
            FT_Set_Transform( face, 0, &pen );
            //std::cout << "glyph index: " << glyph_index << std::endl;
            if( error=FT_Load_Glyph(face, glyph_index, FT_LOAD_RENDER) )
            {
                std::cout << "error loading glyph index: " << glyph_index << std::endl;
                std::cout << ft_errors[error] << std::endl;
                return 2;
            }
            char buffer[256];
            FT_Get_Glyph_Name( face, glyph_index, buffer, 256 );
            //std::cout << "glyph name: " << buffer << std::endl;
            
            FT_GlyphSlot& glyph = face->glyph;
            FT_Bitmap& bitmap = face->glyph->bitmap;
            if( !base_height ) base_height = bitmap.rows;
            std::cout << "w/r: " << bitmap.width << "/" << bitmap.rows 
                        << " t: " << glyph->bitmap_top << std::endl;
            if( !bitmap.buffer )
            {
                std::cout << "error: got no bitmap for current glyph" << std::endl;
                return 2;
            }
            if( bitmap.rows > max_advance ) max_advance = bitmap.rows;
            for( int row=0; row<bitmap.rows; row++ )
            {
                // FIXME Korrektur an bitmap.width um -1, damit wir mit der
                // 16-Bit-Kopie nicht die Puffergrenze verletzen und falsche
                // Pixel kopieren. Allerdings kopieren wir so manchmal zu wenig.
                for( int pixel=0; pixel<bitmap.width-1; pixel+=2 )
                {
                    u16 value = (bitmap.buffer[row*bitmap.pitch+pixel+1] << 8)
                                + bitmap.buffer[row*bitmap.pitch+pixel];
                    u16* base_adress = bgGetGfxPtr(bg3) 
                            + (row+(base_height-glyph->bitmap_top))*256/2
                            + pixel/2 + glyph->bitmap_left/2;
                    *base_adress = value;
                }
            }
            pen.x += glyph->advance.x;
        }
        pen.y -= max_advance*64;
    }
        
    FT_Done_Face( face );
    FT_Done_FreeType( library );
    
    std::cout << "clean exit" << std::endl;
    
    while( true ) swiWaitForVBlank();
}
