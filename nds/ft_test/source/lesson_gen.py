#!/usr/bin/python
# coding: utf-8

import sys

print """
#include <iostream>
#include "lesson.h"

Lesson all_words_lesson("Alle Wörter");
void init_all_words_lesson()
{
    int count = 0;
    Word* word;"""

def escape( text ):
    text = text.replace("\n"," ");
    text = text.replace("\"","\\\"")
    return text

for line in sys.stdin:
    word = line.split("|")[1:]
    hanzi = escape( word[0] )
    pinyin = escape( word[1] )
    de = escape( word[2] )
    print """
    word = new Word( "%(hanzi)s", "%(pinyin)s" );
    word->translations["de"] = "%(de)s";
    all_words_lesson.push_back( word );
    std::cout << "#" << ++count << std::endl;""" \
        % locals()
    
print """
}"""
