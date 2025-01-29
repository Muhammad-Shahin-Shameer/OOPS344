#ifndef SENECA_DICTIONARY_H
#define SENECA_DICTIONARY_H

#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include "settings.h"
#include "dictionary.h"


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

    struct Word *m_words; 
    size_t m_size;

    // Helper function to load words from a file
    void loadFromFile(const char* filename);

public:
    Dictionary();                   // Default constructor
    Dictionary(const char* filename); // Constructor that loads from a file
    ~Dictionary();                  // Destructor (if needed for cleanup)

    void searchWord(const char* word);  // Search for a word in the dictionary

    

    
};
 std::string posToString(PartOfSpeech pos);
 std::string getSpeech(PartOfSpeech pos);
}
#endif // DICTIONARY_H
