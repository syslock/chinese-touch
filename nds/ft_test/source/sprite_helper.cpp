#include <nds.h>

void tile_32x16_8bpp_sprite( u8* source_buffer, u8* dest_buffer )
{
	int dest_offset = 0;
	for( int tlin=0; tlin<2; tlin++ )
		for( int trow=0; trow<4; trow++ )
			for( int plin=0; plin<8; plin++ )
				for( int prow=0; prow<8; prow++, dest_offset++ )
				{
					int source_offset = (32*8*tlin)+(plin*4+trow)*8+prow;
					//int dest_offset = plin*8+prow+64*trow+256*tlin;
					dest_buffer[dest_offset] = source_buffer[source_offset];
				}
}