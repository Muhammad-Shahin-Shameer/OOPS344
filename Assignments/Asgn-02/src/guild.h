
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
#ifndef SENECA_GUILD_H
#define SENECA_GUILD_H

#include <iostream>
#include <string>
#include <algorithm>
#include "characterTpl.h" // Include the base class

namespace seneca {

  class Guild {
  private:
    std::string m_guildName;
    Character** m_characterArr; // Raw pointer array for characters
    size_t m_size;         // Current number of members
      // Capacity of the array

  public:
  Guild();
  Guild(const char* name);
  ~Guild();
  Guild(const Guild& other);//copy constructor
  Guild& operator=(const Guild& other); //copy assignment operator
  Guild(Guild&& other) noexcept; //move constructor
  Guild& operator=(Guild&& other) noexcept; //move assignment operator
  void addMember(Character* c);//add a member to the guild
  void removeMember(const std::string& c); //remove a member from the guild
  Character* operator[](size_t idx) const; //return a character from the guild
  void showMembers() const; //show the members of the guild
  };

} // namespace seneca

#endif
