#include "team.h"
using namespace std;

namespace seneca {


  void Team::removeMember(const std::string& c) {
    size_t i;


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

  Character* Team::operator[](size_t idx) const
  {

    if (idx < m_chrSize) {
      return m_characterArr[idx];
    }

    return nullptr;
  }

  void Team::showMembers() const
  {

    if (m_teamName == "") {
      std::cout << "No team." << std::endl;
    }
    else {
      std::cout << "[Team] " << m_teamName << std::endl;
      for (size_t i = 0;i < m_chrSize;i++) {
        if (m_characterArr[i] != nullptr) {
          cout << std::setw(4) << ' ' << i + 1 << ": " << *m_characterArr[i] << std::endl;

        }
      }

    }
  }
  Team::Team(const char* name)
  {
    m_teamName = name;
    m_chrSize = 0;
    m_characterArr = nullptr;

  }
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

  Team::Team(const Team& other) {
    m_teamName = other.m_teamName;
    m_chrSize = other.m_chrSize;
    m_characterArr = new Character * [m_chrSize];
    for (size_t i = 0; i < m_chrSize; i++) {
      m_characterArr[i] = other.m_characterArr[i]->clone();
    }
  }

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

  Team::Team(Team&& other) noexcept {
    m_teamName = other.m_teamName;
    m_chrSize = other.m_chrSize;
    m_characterArr = other.m_characterArr;
    other.m_characterArr = nullptr;
    other.m_chrSize = 0; // Reset size
  }

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

  void Team::addMember(const Character* c)
  {
    size_t i;
    bool isFound = false;

    for (i = 0;i < m_chrSize || isFound == false;i++) {

      if (m_characterArr[i]->getName() == c->getName()) {
        isFound = true;
      }
    }

    if (isFound == false) {
      Character** tempArr = new Character * [m_chrSize + 1];

      for (i = 0;i < m_chrSize;i++) {
        tempArr[i] = m_characterArr[i];

      }

      tempArr[m_chrSize] = c->clone();
      delete[] m_characterArr;
      m_characterArr = tempArr;
      m_chrSize++;

    }

  }



  //name soace close
}