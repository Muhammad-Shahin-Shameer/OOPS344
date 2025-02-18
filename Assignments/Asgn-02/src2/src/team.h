#ifndef SENECA_TEAM_H
#define SENECA_TEAM_H

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "CharacterTpl.h" // Include the base class

namespace seneca {


  class Team {

  private:
    Character** m_characterArr; // Array of pointers to Character
    std::string m_teamName;// team name 
    size_t m_chrSize;
  public:

    // rule of five
    // default constructor
    Team() :m_characterArr(nullptr), m_teamName(""), m_chrSize(0) {};
    //move constructor 
    Team(Team&& other) noexcept;
    //move  Assigemt operator
    Team& operator =(Team&& other)noexcept;
    //copy constructor
    Team(const Team& other);
    //copy assigment operator
    Team& operator =(const Team& other);
    //destructor
    ~Team();
    // one argument 
    Team(const char* name);
    //
    void addMember(const Character* c);
    //;
    void removeMember(const std::string& c);
    //
    Character* operator[](size_t idx) const;
    //
    void showMembers() const;






      //class closing
  };
}


#endif