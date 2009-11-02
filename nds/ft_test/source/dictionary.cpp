#include "dictionary.h"
#include "lesson.h"

void Dictionary::add_new_word( NewWord* new_word )
{
	this->new_words_by_word_string[ new_word->hanzi ].insert( new_word );
	UCCharList char_list;
	utf8_to_ucs4( (const unsigned char*)new_word->hanzi.c_str(), char_list );
	for( UCCharList::iterator char_it = char_list.begin(); char_it != char_list.end(); char_it++ )
	{
		this->new_words_by_char_code[ char_it->code_point ].insert( new_word );
	}
}

void Dictionary::find_words_by_char_code( unsigned long char_code, NewWordSet& result )
{
	if( this->new_words_by_char_code.count(char_code) )
	{
		result = this->new_words_by_char_code[ char_code ];
	}
	else
	{
	}
	return;
}
