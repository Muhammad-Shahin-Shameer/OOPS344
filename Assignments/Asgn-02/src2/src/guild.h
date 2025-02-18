#ifndef SENECA_GUILD_H
#define SENECA_GUILD_H
#include <iostream>
#include "character.h"
namespace seneca{
    class Guild{
        std::string m_guildName;
        Character** m_characterArr;
        size_t m_size;
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
}

#endif