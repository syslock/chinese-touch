#ifndef DICTIONARY_H
#define DICTIONARY_H

#include "lesson.h"

class WordOccurrence
{
public:
	Text* text;
	std::string::size_type offset;
public:
	WordOccurrence() : text(0), offset(0) {}
};

typedef std::map<std::string,WordOccurrence> OccurrencesByString;
typedef std::map<std::string,NewWord*> NewWordsByString;


class Dictionary
{
public:
	OccurrencesByString occurrences_by_string;
	NewWordsByString new_words_by_string;
public:
	Dictionary() {}
};

#endif // DICTIONARY_H