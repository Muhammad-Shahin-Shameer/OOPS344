#include "Dictionary.h"

// Default constructor
Dictionary::Dictionary() {}

// Constructor that loads words from a file
Dictionary::Dictionary(const char* filename) {
    loadFromFile(filename);
}

// Helper function to load words from a file
void Dictionary::loadFromFile(const char* filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Could not open the file!" << std::endl;
        return;
    }

    std::string word;
    std::string definition;
    std::string pos;
    while (std::getline(file, word)) {
        if (word.empty()) continue;
        
        std::getline(file, definition);
        std::getline(file, pos);

        PartOfSpeech partOfSpeech = parsePartOfSpeech(pos);

        Word newWord{word, definition, partOfSpeech};
        m_words.push_back(newWord);
    }
        file.close();
}