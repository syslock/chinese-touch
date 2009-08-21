#include "unicode.h"

bool utf8_to_ucs4( const unsigned char* src, CharList& result_list )
{
    if( !src ) return false;
    const unsigned char* first = src;
    while( *first )
    {
        int len = 0;
        unsigned long result = 0;
        if( (*first >> 7) == 0 )
        {
            len = 1;
            result = *first;
        }
        else if( (*first >> 5) == 6 )
        {
            len = 2;
            result = *first & 31;
        }
        else if( (*first >> 4) == 14 )
        {
            len = 3;
            result = *first & 15;
        }
        else if( (*first >> 3) == 30 )
        {
            len = 4;
            result = *first & 7;
        }
        else return false;
        //std::cout << "len: " << len << std::endl;
        const unsigned char* next;
        for( next = first + 1;
            *next && ((*next >> 6) == 2) && (next-first<len); 
            next++ )
        {
            //std::cout << "result*: " << result << std::endl;
            result = result << 6;
            result |= *next & 63;
        }
        first = next;
        //std::cout << "result: " << result << std::endl;
        result_list.push_back( result );
    }
    return true;
}
