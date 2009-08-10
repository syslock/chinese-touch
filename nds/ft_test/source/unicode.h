#ifndef UNICODE_H
#define UNICODE_H

#include <list>

typedef std::list<unsigned long> CharList;

bool utf8_to_ucs4( const unsigned char* src, CharList& result_list );

#endif // UNICODE_H

