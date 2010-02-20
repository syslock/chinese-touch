#ifndef LESSON_H
#define LESSON_H

#include <list>
#include <vector>
#include <map>
#include <string>

#include "freetype_renderer.h"
#include "dictionary.h"


class NewWordRenderSettings
{
	public:
		bool render_hanzi, render_pinyin, render_word_type, render_translation, render_comment;
	public:
		NewWordRenderSettings() : render_hanzi(true), render_pinyin(true), render_word_type(true),
			render_translation(true), render_comment(true) {}
		void toggle_hanzi() { this->render_hanzi = !this->render_hanzi; }
		void toggle_pinyin() { this->render_pinyin = !this->render_pinyin; }
		void toggle_word_type() { this->render_word_type = !this->render_word_type; }
		void toggle_translation() { this->render_translation = !this->render_translation; }
		void toggle_comment() { this->render_comment = !this->render_comment; }
};

class Lesson;

class Text : public std::string
{
public:
	std::string title;
	Lesson* lesson;
public:
	Text( const std::string& _title, Lesson* _lesson ) : title(_title), lesson(_lesson) {}
};
typedef std::vector<Text*> TextVector;

class Definition
{
public:
    std::string lang, translation, word_type, comment, example;
};
typedef std::map<std::string,Definition*> Definitions;

/*! \brief Difficulty rating levels */
typedef enum
{
	RATING_NONE = 0,
	RATING_IMPOSSIBLE,
	RATING_HARD,
	RATING_MEDIUM,
	RATING_EASY,
} Rating;

/*! \brief Encapsulates a new word and all related information
	Composition of a chinese word, chinese pronunciation in Pinyin and a mapping 
	from ISO language codes to definitions/translations in the corresponding languages */
class NewWord
{
public:
    NewWord( const std::string& _hanzi, const std::string& _pinyin, 
            Lesson* _lesson ) 
        : hanzi(_hanzi), pinyin(_pinyin), lesson(_lesson),
        rating(RATING_NONE) {};
    void render( FreetypeRenderer& ft, RenderScreen& render_screen, NewWordRenderSettings& render_settings );
public:
    std::string hanzi, pinyin;
    Definitions definitions;
    Lesson* lesson;
	Rating rating; //!< User defined difficulty rating
	int id;
};
typedef std::vector<NewWord*> NewWordVector;

class Book;

class Lesson
{
public:
    Lesson( int _number, Book* _book ) : number(_number), book(_book) {};
    void parse_config( const std::string& lesson_file_name );
    void parse_dictionary( const std::string& lesson_file_name, Dictionary& dictionary );
	void parse_text( const std::string& text_file_name, TextVector& container );
public:
	NewWordVector new_words;
	TextVector lesson_texts;
	TextVector grammar_texts;
	TextVector exercises;
    std::string title, description;
    int number;
    Book* book;
	int id;
};

class Library;
//! \brief Bücher bilden Lektionsnummern auf Lektionsobjekte ab:
class Book : public std::map<int,Lesson*>
{
public:
    Book( const std::string& _name, Library* _library ) : name(_name),
        library(_library) {}
    void parse_config( const std::string& book_conf_file_name );
public:
    std::string name, title, description, author, publisher, isbn;
    int year;
    Library* library;
	int id;
};

//! \brief Die Buchsammlung bildet Buchnamen auf Buchobjekte ab:
class Library : public std::map<std::string,Book*>
{
public:
    Library( bool _fat_initialized, Dictionary& _dictionary ) 
		: fat_initialized(_fat_initialized), dictionary(_dictionary) {}
    void rescan();
protected:
    bool fat_initialized;
	Dictionary& dictionary;
};

extern Lesson all_words_lesson;
void init_all_words_lesson();

#endif // LESSON_H
