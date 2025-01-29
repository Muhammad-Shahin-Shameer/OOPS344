#include "Dictionary.h"

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
        Dictionary();
        
    }else{

     m_size = 0;

    string word;
  
    while (getline(file, word)) {
     m_size++;
    }


    m_words = new Word[m_size];

      file.clear();
      file.seekg(0, std::ios::beg);
    for (size_t i = 0; i < m_size; ++i)
      {
        // for pos
        string pos;
        getline(file, pos, ',');
        getline(file, pos, ',');
        
        if (pos == "n." || pos == "n. pl.")
        {
          m_words[i].m_pos = PartOfSpeech::Noun;
        }
        else if (pos == "adv.")
        {
          m_words[i].m_pos = PartOfSpeech::Adverb;
        }
        else if (pos == "a.")
        {
          m_words[i].m_pos = PartOfSpeech::Adjective;
        }
        else if (pos == "v." || pos == "v. i." || pos == "v. t." || pos == "v. t. & i.")
        {
          m_words[i].m_pos = PartOfSpeech::Verb;
        }
        else if (pos == "prep.")
        {
          m_words[i].m_pos = PartOfSpeech::Preposition;
        }
        else if (pos == "pron.")
        {
          m_words[i].m_pos = PartOfSpeech::Pronoun;
        }
        else if (pos == "conj.")
        {
          m_words[i].m_pos = PartOfSpeech::Conjunction;
        }
        else if (pos == "interj.")
        {
          m_words[i].m_pos = PartOfSpeech::Interjection;
        }
        else
        {
          m_words[i].m_pos = PartOfSpeech::Unknown;
        }
        std::getline(file, m_words[i].m_definition);
        std::getline(file, m_words[i].m_word, ',');

        // pos?
        for (size_t i = 1; i < 2; i++)
        {
          std::getline(file, m_words[i].m_word);
        }
      }
    }
    file.close();
}

// Destructor (if needed for cleanup)
Dictionary::~Dictionary() {}





// Search for a word and print its definitions
void Dictionary::searchWord(const char* word)
{
    bool wordFound = false;
   size_t wordLength = strlen(word);

    for (size_t i = 0; i < m_size; i++)
    {
        if (strcasecmp(m_words[i].m_word.c_str(), word) == 0)
        {
            if (!wordFound)
            {
                wordFound = true;
                
                std::cout << m_words[i].m_word;
                  if (!g_settings.m_verbose || m_words[i].m_pos != PartOfSpeech::Unknown)
               {
                std::cout << " - (" << getSpeech(m_words[i].m_pos) << ")";
             }
          std::cout << " " << m_words[i].m_definition << std::endl;
            if (!g_settings.m_show_all) {
                return;
            }
            }
            else
            {
                 std::cout << std::string(wordLength, ' ') << " -";
          if (g_settings.m_verbose || m_words[i].m_pos != PartOfSpeech::Unknown)
          {
            std::cout << " (" << getSpeech(m_words[i].m_pos) << ")";
          }
          std::cout << " " << m_words[i].m_definition << std::endl;
            }

           
          
        }
    }

    if (!wordFound)
    {
        cout << "Word '" << word << "' was not found in the dictionary." << endl;
    }
}

std::string getSpeech(PartOfSpeech pos)
  {
    if (pos == PartOfSpeech::Noun)
    {
      return "Noun";
    }
    else if (pos == PartOfSpeech::Pronoun)
    {
      return "Pronoun";
    }
    else if (pos == PartOfSpeech::Adjective)
    {
      return "Adjective";
    }
    else if (pos == PartOfSpeech::Adverb)
    {
      return "Adverb";
    }
    else if (pos == PartOfSpeech::Verb)
    {
      return "Verb";
    }
    else if (pos == PartOfSpeech::Preposition)
    {
      return "Preposition";
    }
    else if (pos == PartOfSpeech::Conjunction)
    {
      return "Conjunction";
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

}

  