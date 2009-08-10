#ifndef LESSON_H
#define LESSON_H

#include <list>
#include <map>
#include <string>

#include "freetype_renderer.h"

// Word ist eine Komposition aus einem chinesischen Wort, der zugehörigen 
// Lautumschrift in Pinyin, sowie einer Abbildung von ISO-Sprachcodes zu in den 
// jeweiligen Sprachen verfassten Übersetzungen bzw. Definitionen
typedef std::map<std::string,std::string> Translations;
class Word
{
public:
    Word( const std::string& _hanzi, const std::string& _pinyin ) : hanzi(_hanzi), 
        pinyin(_pinyin), successes(0), errors(0) {};
    void render( FreetypeRenderer& ft );
public:
    std::string hanzi, pinyin;
    Translations translations;
    unsigned int successes, errors;
};

class Lesson : public std::list<Word*>
{
public:
    Lesson( const std::string& _name ) : name(_name) {};
public:
    std::string name;
};

extern Lesson all_words_lesson;
void init_all_words_lesson();

#endif // LESSON_H
