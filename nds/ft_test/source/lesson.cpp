#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <list>
#include <nds.h>
#include <fat.h>
#include <dirent.h>
#include <errno.h>
#include <sstream>

#include "lesson.h"
#include "config.h"
#include "error_console.h"

void NewWord::render( FreetypeRenderer& ft, RenderScreen& render_screen )
{
	render_screen.clear();
    
    // 2. render hanzi in the faces suggested layout (e.g. fixed width)
    RenderStyle render_style;
    render_style.center_x = true;
    int top = 10;
    int size = 32;
    if( this->lesson->render_hanzi )
    {
        RenderRect rect = ft.render( render_screen, this->hanzi, ft.han_face, size, 0, top, &render_style );
        top += rect.height;
    }
    else
    {
        top += size;
    }
    
    // 3. render pinyin in variable width
    top += 10;
    size = 16;
    if( this->lesson->render_pinyin )
    {
        RenderRect rect = ft.render( render_screen, this->pinyin, ft.han_face, size, 0, top, &render_style );
        top += rect.height;
    }
    else
    {
        top += size;
    }
    
    // 4. render translation in variable width
    top += 10;
    size = 9;
    if( this->lesson->render_translation && this->definitions.count("de") )
    {
        RenderRect rect = ft.render( render_screen, this->definitions["de"]->translation, ft.latin_face, size, 0, top, &render_style );
        top += rect.height;
    }
    else
    {
        top += size;
    }
}


void Library::rescan()
{
    std::string books_path = "/" PROGRAM_NAME "/books";
    DIR* books_dir = opendir( books_path.c_str() );
    if( !books_dir )
    {
        std::stringstream msg;
		msg << "failed to open: " << books_path << " (" << strerror(errno) << ")";
		throw ERROR( msg.str() );
    }
    struct dirent* books_entry;
    while( (books_entry = readdir(books_dir))!=NULL )
    {
        struct stat book_stat;
        std::string book_name = books_entry->d_name;
        std::string book_path = books_path + "/" + book_name;
        if( stat(book_path.c_str(), &book_stat)==-1 )
        {
            LOG( "failed to stat: " << books_entry->d_name );
            LOG( strerror(errno) );
            continue;
        }
        if( S_ISDIR(book_stat.st_mode) && book_name!="." && book_name!=".." )
        {
            std::string lessons_path = books_path + "/" + book_name;
            std::string book_conf_path = lessons_path + "/" + book_name + ".conf";
            struct stat book_conf_stat;
            if( stat(book_conf_path.c_str(), &book_conf_stat)==-1 )
            {
                LOG( "failed to open (read): " << book_conf_path );
                LOG( strerror(errno) );
                continue;
            }
            Book* book = new Book( book_name, this );
            book->parse_config( book_conf_path );
            (*this)[ book_name ] = book;
            LOG( "book: " << book_path );
            DIR* lessons_dir = opendir( lessons_path.c_str() );
            if( !lessons_dir )
            {
                LOG( "failed to open: " << lessons_path );
                LOG( strerror(errno) );
                continue;
            }
            struct dirent* lessons_entry;
            while( (lessons_entry = readdir(lessons_dir))!=NULL )
            {
                struct stat lesson_stat;
                std::string lesson_name = lessons_entry->d_name;
                std::string lesson_path = lessons_path + "/" + lesson_name;
                if( stat(lesson_path.c_str(), &lesson_stat)==-1 )
                {
                    LOG( "failed to stat: " << lessons_entry->d_name );
                    LOG( strerror(errno) );
                    continue;
                }
                if( !S_ISDIR(lesson_stat.st_mode) )
                {
                    std::string::size_type ldot_pos = lesson_name.find( '.' );
                    std::string::size_type rdot_pos = lesson_name.rfind( '.' );
                    std::string lesson_extension = "";
                    if( rdot_pos != std::string::npos )
                    {
                        lesson_extension = lesson_name.substr( rdot_pos+1 );
                    }
					std::stringstream lesson_number_stringstream( lesson_name.substr(0, ldot_pos) );
					int lesson_number = -1;
					lesson_number_stringstream >> lesson_number;
					if( lesson_number > 0 )
					{
						LOG( "lesson #" << lesson_number << ": " << lesson_path );
						Lesson* lesson;
						if( book->count(lesson_number) )
						{
							lesson = (*book)[ lesson_number ];
						}
						else
						{
							lesson = new Lesson( lesson_number, book );
							(*book)[ lesson_number ] = lesson;
						}
						if( lesson_extension == "dict" )
						{
							lesson->parse_dictionary( lesson_path );
						}
						else if( lesson_extension == "conf" )
						{
							lesson->parse_config( lesson_path );
						}
					}
                }
            }
            closedir( lessons_dir );
        }
    }
    closedir( books_dir );
}


void Book::parse_config( const std::string& conf_file_name )
{
	std::ifstream book_conf_file( conf_file_name.c_str() );
	char line_buffer[1024];
	std::string key, value;
	while( book_conf_file.good() )
	{
		book_conf_file.getline( line_buffer, sizeof(line_buffer) );
		std::string line = line_buffer;
		std::string::size_type equals_pos = line.find( '=' );
		if( equals_pos != std::string::npos )
		{
			key = line.substr( 0, equals_pos );
			value = line.substr( equals_pos+1 );
			if( key=="title" )
			{
				this->title = value;
			}
			else if( key=="description" )
			{
				this->description = value;
			}
			else if( key=="author" )
			{
				this->author = value;
			}
			else if( key=="publisher" )
			{
				this->publisher = value;
			}
			else if( key=="isbn" )
			{
				this->isbn = value;
			}
			else if( key=="year" )
			{
				this->year = atoi( value.c_str() );
			}
		}
	}
}


void Lesson::parse_config( const std::string& conf_file_name )
{
	std::ifstream lesson_conf_file( conf_file_name.c_str() );
	char line_buffer[1024];
	std::string key, value;
	while( lesson_conf_file.good() )
	{
		lesson_conf_file.getline( line_buffer, sizeof(line_buffer) );
		std::string line = line_buffer;
		std::string::size_type equals_pos = line.find( '=' );
		if( equals_pos != std::string::npos )
		{
			key = line.substr( 0, equals_pos );
			value = line.substr( equals_pos+1 );
			if( key=="title" )
			{
				this->title = value;
			}
			else if( key=="description" )
			{
				this->description = value;
			}
		}
	}
}


void Lesson::parse_dictionary( const std::string& dict_file_name )
{
    std::ifstream shengci_file( dict_file_name.c_str() );
    char line_buffer[1024];
    std::string hanzi, pinyin;
    Definition definition;
    definition.lang = "de";
    int word_count = 0;
    int column = 0;
    while( shengci_file.good() )
    {
        shengci_file.getline( line_buffer, sizeof(line_buffer) );
        std::string line = line_buffer;
        if( line.substr(0, 2) == "|-" )
        {
            if( word_count )
            {
                NewWord* word = new NewWord( hanzi, pinyin, this );
                word->definitions[ definition.lang ] = new Definition( definition );
                this->new_words.push_back( word );
                hanzi = "";
                pinyin = "";
                definition.translation = "";
                definition.word_type = "";
                definition.comment = "";
            }
            word_count++;
            column = 0;
        }
        else if( line.substr(0, 2) == "|}" && word_count )
        {
            NewWord* word = new NewWord( hanzi, pinyin, this );
            word->definitions[ definition.lang ] = new Definition( definition );
            this->new_words.push_back( word );
            column = 0;
        }
        else if( line.substr(0, 2) == "| " )
        {
            column++;
            line = line.substr(2);
        }
        switch( column )
        {
        case 1: hanzi.append( line ); break;
        case 2: pinyin.append( line ); break;
        case 3: definition.translation.append( line ); break;
        case 4: definition.word_type.append( line ); break;
        case 5: definition.comment.append( line ); break;
        }
    }
    shengci_file.close();
}

