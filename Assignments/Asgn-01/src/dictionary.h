#ifndef DICTINARY_H
#define DICTINARY_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "settings.h"


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


class Dictionary{

private:
    std::vector<Word> m_words;  // Vector to store words dynamically
    void loadFromFile(const char* filename);  // Helper function to load words from file

public:
    // Default constructor
    Dictionary();
    // Constructor that loads words from a file
    Dictionary(const char* filename);
    // Search for a word in the dictionary
    void searchWord(const char* word);
    // Helper function to convert a string to PartOfSpeech enum
    PartOfSpeech parsePartOfSpeech(const std::string& pos);


};




#endif