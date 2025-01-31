
//////////////////////////////////////////////////////////////////////////*/
//Name  :Muhammad Shahin Shameer
//Student ID#:166626234
//Email      :msshameer@myseneca.ca
//Section    :NGG

//Authenticity Declaration:
//I declare this submission is the result of my own work and has not been
//shared with any other student or 3rd party content provider. This submitted
//piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/
#ifndef SENECA_DICTIONARY_H
#define SENECA_DICTIONARY_H

#include <iostream>
#include <fstream>
#include <cstring>
#include <sstream>
#include <string>
#include "settings.h"


namespace seneca {

    enum class PartOfSpeech
    {
        Unknown,
        Noun,
        Pronoun,
        Adjective,
        Adverb,
        Verb,
        Preposition,
        Conjunction,
        Interjection,
    };

    struct Word
    {
        std::string m_word{};
        std::string m_definition{};
        PartOfSpeech m_pos = PartOfSpeech::Unknown;
    };

    class Dictionary
    {

        Word* m_words;
        size_t m_size;

        // Helper function to load words from a file

        std::string getPos(PartOfSpeech pos);
        void display(Word p_Word, bool is_verbose, bool isFirstLine = false);

    public:
        Dictionary();                   // Default constructor
        Dictionary(const char* filename); // Constructor that loads from a file
        ~Dictionary();               // Destructor (if needed for cleanup)
         void searchWord(const char* word);  // Search for a word in the dictionary

        // copy  construter
        Dictionary(const Dictionary& other);
        Dictionary& operator=(const Dictionary& other);
        //move
        Dictionary(Dictionary&& other);
        Dictionary& operator=(Dictionary&& other) noexcept;


       

    };

}
#endif // DICTIONARY_H
