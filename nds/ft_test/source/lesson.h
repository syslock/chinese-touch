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
class Lesson;
class Word
{
public:
    Word( const std::string& _hanzi, const std::string& _pinyin, Lesson* _lesson ) 
        : hanzi(_hanzi), pinyin(_pinyin), successes(0), errors(0), 
        lesson(_lesson) {};
    void render( FreetypeRenderer& ft );
public:
    std::string hanzi, pinyin;
    Translations translations;
    unsigned int successes, errors;
    Lesson* lesson;
};

class Lesson : public std::list<Word*>
{
public:
    Lesson( const std::string& _name ) : name(_name), render_hanzi(true), 
        render_pinyin(true), render_translation(true) {};
    void toggle_hanzi() { this->render_hanzi = !this->render_hanzi; }
    void toggle_pinyin() { this->render_pinyin = !this->render_pinyin; }
    void toggle_translation() { this->render_translation = !this->render_translation; }
public:
    std::string name;
    bool render_hanzi, render_pinyin, render_translation;
};

extern Lesson all_words_lesson;
void init_all_words_lesson();

#endif // LESSON_H
