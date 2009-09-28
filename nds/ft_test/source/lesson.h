#ifndef LESSON_H
#define LESSON_H

#include <list>
#include <map>
#include <string>

#include "freetype_renderer.h"


class Definition
{
public:
    std::string lang, translation, word_type, comment, example;
};


// Word ist eine Komposition aus einem chinesischen Wort, der zugehörigen 
// Lautumschrift in Pinyin, sowie einer Abbildung von ISO-Sprachcodes zu in den 
// jeweiligen Sprachen verfassten Übersetzungen bzw. Definitionen
typedef std::map<std::string,Definition*> Definitions;
class Lesson;
class Word
{
public:
    Word( const std::string& _hanzi, const std::string& _pinyin, 
            Lesson* _lesson, int _number ) 
        : hanzi(_hanzi), pinyin(_pinyin), successes(0), errors(0), 
        lesson(_lesson), number(_number) {};
    void render( FreetypeRenderer& ft );
public:
    std::string hanzi, pinyin;
    Definitions definitions;
    unsigned int successes, errors;
    Lesson* lesson;
    int number;
};

class Book;
// Für die Lektion nehmen wir einfach 'ne Liste zwecks Reihenfolgeerhaltung:
class Lesson : public std::list<Word*>
{
public:
    Lesson( int _number, Book* _book ) : number(_number), 
        render_hanzi(true), render_pinyin(true), render_translation(true),
        book(_book) {};
    void toggle_hanzi() { this->render_hanzi = !this->render_hanzi; }
    void toggle_pinyin() { this->render_pinyin = !this->render_pinyin; }
    void toggle_translation() { this->render_translation = !this->render_translation; }
    void parse_config( const std::string& lesson_file_name );
public:
    std::string name;
    int number;
    bool render_hanzi, render_pinyin, render_translation;
    Book* book;
};

class Library;
// Bücher bilden Lektionsnummern auf Lektionsobjekte ab:
class Book : public std::map<int,Lesson*>
{
public:
    Book( const std::string& _name, Library* _library ) : name(_name),
        library(_library) {}
    void parse_config( const std::string& book_conf_file_name );
public:
    std::string name, description, author, publisher, isbn;
    int year;
    Library* library;
};

// Die Buchsammlung bildet Buchnamen auf Buchobjekte ab:
class Library : public std::map<std::string,Book*>
{
public:
    Library( bool _fat_initialized ) : fat_initialized(_fat_initialized) {}
    void rescan();
protected:
    bool fat_initialized;
};

extern Lesson all_words_lesson;
void init_all_words_lesson();

#endif // LESSON_H
