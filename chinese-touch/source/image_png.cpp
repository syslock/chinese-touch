
#include <stdio.h>
#include <png.h>
#include <nds.h>
#include "image_png.h"
#include "error_console.h"

void read_png( const std::string& file_name, u16*& dest_buffer, int& width, int& height, int left, int top, char alpha_threshold )
{
	FILE *fp = fopen( file_name.c_str(), "rb" );
	if (!fp)
	{
		std::stringstream errstr;
		errstr << "could not open: " << file_name;
		throw ERROR( errstr.str() );
	}
	png_byte header[8];
	fread( header, 1, sizeof(header), fp );
	bool is_png = !png_sig_cmp( header, 0, sizeof(header) );
	if( !is_png )
	{
		fclose( fp );
		std::stringstream errstr;
		errstr << "not a png image: " << file_name;
		throw ERROR( errstr.str() );
	}
	png_structp png_ptr = png_create_read_struct( PNG_LIBPNG_VER_STRING, 0, 0, 0 );
	if( !png_ptr )
	{
		fclose( fp );
		std::stringstream errstr;
		errstr << "png_create_read_struct failed for: " << file_name;
		throw ERROR( errstr.str() );
	}
	png_infop info_ptr = png_create_info_struct( png_ptr );
	if( !info_ptr )
	{
		png_destroy_read_struct( &png_ptr, (png_infopp)NULL, (png_infopp)NULL );
		fclose( fp );
		std::stringstream errstr;
		errstr << "1. png_create_info_struct failed for: " << file_name;
		throw ERROR( errstr.str() );
	}
	png_infop end_info = png_create_info_struct( png_ptr );
	if( !end_info )
	{
		png_destroy_read_struct( &png_ptr, &info_ptr, (png_infopp)NULL );
		fclose( fp );
		std::stringstream errstr;
		errstr << "2. png_create_info_struct failed for: " << file_name;
		throw ERROR( errstr.str() );
	}
	if( setjmp(png_jmpbuf(png_ptr)) )
	{
		png_destroy_read_struct( &png_ptr, &info_ptr, &end_info);
		fclose( fp );
		std::stringstream errstr;
		errstr << "error reading: " << file_name;
		throw ERROR( errstr.str() );
	}
	png_init_io( png_ptr, fp );
	png_set_sig_bytes( png_ptr, sizeof(header) );
	png_read_png( png_ptr, info_ptr, PNG_TRANSFORM_STRIP_16|PNG_TRANSFORM_STRIP_ALPHA|PNG_TRANSFORM_PACKING, NULL );
	if( info_ptr->bit_depth!=8 or 
		!(info_ptr->color_type==PNG_COLOR_TYPE_RGB or info_ptr->color_type==PNG_COLOR_TYPE_RGB_ALPHA) )
	{
		png_destroy_read_struct( &png_ptr, &info_ptr, &end_info);
		fclose( fp );
		std::stringstream errstr;
		errstr << "not 8bpc RGB(A) image: " << file_name;
		throw ERROR( errstr.str() );
	}
	
	if( !width || !height ) 
	{
		// user wants us to allocate buffer dynamically
		width = info_ptr->width;
		height = info_ptr->height;
		if( dest_buffer ) delete dest_buffer;
		dest_buffer = 0;
	}
	
	int dest_width = width;
	int dest_height = height;
	// ensure 16-bit-alignment of dest buffer lines:
	dest_width = dest_width/2*2+dest_width%2*2;
	if( !dest_buffer )
	{
		// user wants us to allocate buffer
		dest_buffer = new u16[ dest_width * dest_height ];
	}
	
	if( width>info_ptr->width+1 ) width = info_ptr->width;
	if( height>info_ptr->height+1 ) height = info_ptr->height;
	
	if( left < 0 ) left=0;
	if( top < 0 ) top=0;
	if( left > info_ptr->width-dest_width ) left = info_ptr->width-dest_width;
	if( top > info_ptr->height-dest_height ) top = info_ptr->height-dest_height;
	
	png_byte** row_pointers = png_get_rows( png_ptr, info_ptr );
	for( int row=top; row<info_ptr->height && row<(height+top); row++ )
	{
		for( int col=left; col<info_ptr->width && col<(width+left); col++ )
		{
			int byte_offset = col*(info_ptr->pixel_depth/8);
			
			u16 opague_mask = 1 << 15;
			if( info_ptr->color_type==PNG_COLOR_TYPE_RGB_ALPHA )
			{
				png_byte alpha = row_pointers[row][byte_offset+3] /*ALPHA*/;
				if( alpha > alpha_threshold )
				{
					opague_mask = 0;
				}
			}
			
			u16 pixel_value = opague_mask;
			for( int channel=0; channel<3; channel++ )
			{
				png_byte channel_value = row_pointers[row][byte_offset+channel];
				pixel_value |= (channel_value/8) << (channel*5);
			}
			
			dest_buffer[ (row-top) * dest_width+(col-left) ] = pixel_value;
		}
	}
	width = dest_width;
	height = dest_height;
	png_destroy_read_struct( &png_ptr, &info_ptr, &end_info);
	fclose( fp );
}