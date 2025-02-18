
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
#include <iostream>
#include <iomanip>
#include "team.h"
namespace seneca {


  void Team::addMember(const Character* c) {
    size_t i = 0;
    bool isfound = false;
    //add new member
    while (i < m_chrSize && !isfound) {
      //check for simalar name
      if (m_characterArr[i]->getName() == c->getName()) {
        // set flag
        isfound = true;
      }
      i++;
    }
    //if no similar
    if (!isfound) {
      //increaase arr size
      Character** temp = new Character * [m_chrSize + 1];
      //copy to temp
      for (size_t i = 0; i < m_chrSize; i++) {
        temp[i] = m_characterArr[i];
      }
      //male a clone
      temp[m_chrSize] = c->clone();
      //delete arr 
      delete[] m_characterArr;
      //asign the inreaed size
      m_characterArr = temp;
      m_chrSize++;
    }
  }

  void Team::removeMember(const std::string& c) {
    size_t i = 0;
    while (i < m_chrSize) {
      if (m_characterArr[i]->getName() == c) {
        delete m_characterArr[i];
        for (size_t j = i; j < m_chrSize - 1; j++) {
          m_characterArr[j] = m_characterArr[j + 1];
        }
        m_chrSize--;
      }
      else {
        i++;
      }
    }
  }

  Character* Team::operator[](size_t idx) const {
    if (idx < m_chrSize) {
      return m_characterArr[idx];
    }
    return nullptr;
  }

  void Team::showMembers() const {

    if (this->m_teamName == "" || this->m_characterArr == nullptr || this->m_chrSize == 0) {
      std::cout << "No team." << std::endl;
    }
    else {
      std::cout << "[Team] " << m_teamName << std::endl;
      for (size_t i = 0; i < m_chrSize; i++) {
        if (m_characterArr[i] != nullptr) {
          std::cout << std::setw(4) << ' ' << i + 1 << ": " << *m_characterArr[i] << std::endl;
        }
      }
    }


  }

  Team::Team(const char* name) {
    m_teamName = name;
    m_characterArr = nullptr;
    m_chrSize = 0;
  }


  /// Rule of FIVE
  //1
  Team::~Team() {
    if (m_characterArr) {
      for (size_t i = 0; i < m_chrSize; i++) {
        delete m_characterArr[i];
        m_characterArr[i] = nullptr;
      }
      delete[] m_characterArr;
      m_characterArr = nullptr;
    }
  }
  //2
  Team::Team(const Team& other) {
    m_teamName = other.m_teamName;
    m_chrSize = other.m_chrSize;
    m_characterArr = new Character * [m_chrSize];
    for (size_t i = 0; i < m_chrSize; i++) {
      m_characterArr[i] = other.m_characterArr[i]->clone();
    }
  }
  //3
  Team& Team::operator=(const Team& other) {
    if (this != &other) {
      if (m_characterArr) {
        for (size_t i = 0; i < m_chrSize; i++) {
          delete m_characterArr[i];
        }
        delete[] m_characterArr;
      }

      m_teamName = other.m_teamName;
      m_chrSize = other.m_chrSize;
      m_characterArr = new Character * [m_chrSize];
      for (size_t i = 0; i < m_chrSize; i++) {
        m_characterArr[i] = other.m_characterArr[i]->clone();
      }
    }
    return *this;
  }
  //4
  Team::Team(Team&& other) noexcept {
    m_teamName = other.m_teamName;
    m_chrSize = other.m_chrSize;
    m_characterArr = other.m_characterArr;
    other.m_characterArr = nullptr;
    other.m_chrSize = 0; // Reset size
  }
  //5
  Team& Team::operator=(Team&& other) noexcept {
    if (this != &other) {
      if (m_characterArr) {
        for (size_t i = 0; i < m_chrSize; i++) {
          delete m_characterArr[i];
        }
        delete[] m_characterArr;
      }

      m_teamName = other.m_teamName;
      m_chrSize = other.m_chrSize;
      m_characterArr = other.m_characterArr;
      other.m_characterArr = nullptr;
      other.m_chrSize = 0; // Reset size
    }
    return *this;
  }
}