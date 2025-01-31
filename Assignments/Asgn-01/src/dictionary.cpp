
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
#include "dictionary.h"

using namespace std;

namespace seneca {

  // Default constructor
  Dictionary::Dictionary() {
    m_words = nullptr;
    m_size = 0;
  }


  // Constructor that loads from a file
  Dictionary::Dictionary(const char* filename)
  {

    ifstream file(filename);

    if (!file.is_open()) {
      // make it safe empty
      m_words = nullptr;
      m_size = 0;

    }
    else {

      m_size = 0;

      string temp_Line;

      while (getline(file, temp_Line)) 
      {
        m_size++;
      }

      //Clears any error flags (like EOF) so the file stream can be used again.
      file.clear();

      //Moves the read position back to the first line of the file.
      file.seekg(0, std::ios::beg);

      //dynamically allocates an array of Word 
      m_words = new Word[m_size];

      string line;
      int index=0
      
      ;
// loop to get and store file data
      while (getline(file, line)) {

        string c_Word, c_Pos, c_Def;

        std::stringstream ss(line);

        if (ss.good()) {

          getline(ss, c_Word, ',');
          getline(ss, c_Pos, ',');
          getline(ss, c_Def);

        }

        // set word 
        m_words[index].m_word = c_Word;
        
        //set definition
        m_words[index].m_definition = c_Def;
        
        //set pos
        if (c_Pos == "n." || c_Pos == "n. pl.")
        {
          m_words[index].m_pos = PartOfSpeech::Noun;
        }
        else if (c_Pos == "adv.")
        {
          m_words[index].m_pos = PartOfSpeech::Adverb;
        }
        else if (c_Pos == "a.")
        {
          m_words[index].m_pos = PartOfSpeech::Adjective;
        }
        else if (c_Pos == "v." || c_Pos == "v. i." || c_Pos == "v. t." || c_Pos == "v. t. & i.")
        {
          m_words[index].m_pos = PartOfSpeech::Verb;
        }
        else if (c_Pos == "prep.")
        {
          m_words[index].m_pos = PartOfSpeech::Preposition;
        }
        else if (c_Pos == "pron.")
        {
          m_words[index].m_pos = PartOfSpeech::Pronoun;
        }
        else if (c_Pos == "conj.")
        {
          m_words[index].m_pos = PartOfSpeech::Conjunction;
        }
        else if (c_Pos == "interj.")
        {
          m_words[index].m_pos = PartOfSpeech::Interjection;
        }
        else
        {
          m_words[index].m_pos = PartOfSpeech::Unknown;
        }
        //increment the index
        index++;
      }

    }
    file.close();

  }

  void Dictionary::display(Word p_Word, bool is_verbose, bool isFirstLine)
  {
    size_t wordLength = strlen(p_Word.m_word.c_str());

    if (isFirstLine)
    {
      std::cout << p_Word.m_word;
    }
    else
    {
      std::cout << std::string(wordLength, ' ');
    }

    std::cout << " - ";

    if (is_verbose)
    {
      if (p_Word.m_pos != PartOfSpeech::Unknown)
      {
        std::cout << "(" << getPos(p_Word.m_pos) << ") ";
      }
    }

    std::cout << p_Word.m_definition;
    std::cout << std::endl;
  }

  // Search for a word and print its definitions
    void Dictionary::searchWord(const char *word)
  {

    bool firstLine = true;

// screach the arry using loop to check 
    for (size_t i = 0; i < m_size; i++)
    {
      // check the word is same or not useing str compare
      if (strcasecmp(m_words[i].m_word.c_str(), word) == 0)
      {
        // once we are here, we have the index of the word in m_words
        Word found_word = m_words[i];
        // print the first line, include the word
        // print rest of lines, dont include the word but print whitespace

        // print the first line along with the word
        if (firstLine)
        {
        display(found_word, g_settings.m_verbose, true);
          firstLine = false;
        }
      //  print the rest of the line 
        else
        {
          if (g_settings.m_show_all)
          {
            display(found_word, g_settings.m_verbose);
          }
          else
          {
            return;
          }
        }
      }
    }
    if (firstLine)
    {
      cout << "Word '" << word << "' was not found in the dictionary." << endl;
    }
  }

  std::string  Dictionary::getPos(PartOfSpeech pos) {
    if (pos == PartOfSpeech::Noun)
    {
      return "noun";
    }
    else if (pos == PartOfSpeech::Pronoun)
    {
      return "pronoun";
    }
    else if (pos == PartOfSpeech::Adjective)
    {
      return "adjective";
    }
    else if (pos == PartOfSpeech::Adverb)
    {
      return "adverb";
    }
    else if (pos == PartOfSpeech::Verb)
    {
      return "verb";
    }
    else if (pos == PartOfSpeech::Preposition)
    {
      return "preposition";
    }
    else if (pos == PartOfSpeech::Conjunction)
    {
      return "conjunction";
    }
    else if (pos == PartOfSpeech::Interjection)
    {
      return "Interjection";
    }
    else
    {
      return "";
    }
  }



//  deconstructor 
  Dictionary::~Dictionary()
  {
    // delete the dynamically allocated memory
    delete[] m_words;
    // set to safe empty
    m_words = nullptr;
    m_size = 0;
  }
// copy constructor 
  Dictionary::Dictionary(const Dictionary &other)
  {
    // copy other to m_size
    m_size = other.m_size;
    // create a dynamic array using the msize
    if (m_size > 0)
    {

      m_words = new Word[m_size];
      // copy the array with the other 
      for (size_t i = 0; i < m_size; ++i)
      {
        m_words[i] = other.m_words[i];
      }
    }
    else
    {
      m_words = nullptr;
    }
  }

  Dictionary &Dictionary::operator=(const Dictionary &other)
  {

    if (this != &other)
    {
      delete[] m_words;

      m_size = other.m_size;
      if (m_size > 0)
      {
        m_words = new Word[m_size];
        for (size_t i = 0; i < m_size; ++i)
        {
          m_words[i] = other.m_words[i];
        }
      }
      else
      {
        m_words = nullptr;
      }
    }
    return *this;
  }

  // move constructor 
  Dictionary::Dictionary(Dictionary &&other)
  {
    m_words = other.m_words;
    m_size = other.m_size;

    other.m_size = 0;
    other.m_words = nullptr;
  }
  Dictionary &Dictionary::operator=(Dictionary &&other) noexcept
  {
    if (this != &other)
    {
      delete[] m_words;

      m_size = other.m_size;
      m_words = other.m_words;

      other.m_size = 0;
      other.m_words = nullptr;
    }
    return *this;
  }

}
