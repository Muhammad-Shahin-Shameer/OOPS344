#include "guild.h"
#include <iostream>
#include <iomanip>

namespace seneca {
    // Default constructor
    Guild::Guild() : m_guildName(""), m_characterArr(nullptr), m_size(0) {}

    // Parameterized constructor
    Guild::Guild(const char* name) : m_guildName(name), m_characterArr(nullptr), m_size(0) {}

    // Destructor: Deletes only the array of pointers (not the characters)
    Guild::~Guild() {
        delete[] m_characterArr;
        m_characterArr = nullptr;
    }

    // Copy constructor: Shallow copy (no cloning)
    Guild::Guild(const Guild& other) {
        m_guildName = other.m_guildName;
        m_size = other.m_size;
        m_characterArr = new Character*[m_size];
        for (size_t i = 0; i < m_size; i++) {
            m_characterArr[i] = other.m_characterArr[i]; // Point to original characters
        }
    }

    // Copy assignment operator: Shallow copy (no cloning)
    Guild& Guild::operator=(const Guild& other) {
        if (this != &other) {
            delete[] m_characterArr;
            m_guildName = other.m_guildName;
            m_size = other.m_size;
            m_characterArr = new Character*[m_size];
            for (size_t i = 0; i < m_size; i++) {
                m_characterArr[i] = other.m_characterArr[i]; // Point to original characters
            }
        }
        return *this;
    }

    // Move constructor: Transfer ownership of the array
    Guild::Guild(Guild&& other) noexcept {
        m_guildName = std::move(other.m_guildName);
        m_size = other.m_size;
        m_characterArr = other.m_characterArr;
        other.m_characterArr = nullptr;
        other.m_size = 0;
    }

    // Move assignment operator: Transfer ownership of the array
    Guild& Guild::operator=(Guild&& other) noexcept {
        if (this != &other) {
            delete[] m_characterArr;
            m_guildName = std::move(other.m_guildName);
            m_size = other.m_size;
            m_characterArr = other.m_characterArr;
            other.m_characterArr = nullptr;
            other.m_size = 0;
        }
        return *this;
    }

    // Add a member (modify the original character)
    void Guild::addMember(Character* c) {
        // Check if the character is already in the guild
        for (size_t i = 0; i < m_size; i++) {
            if (m_characterArr[i] == c || m_characterArr[i]->getName() == c->getName()) {
                return;
            }
        }

        // Increase the original character's health
        c->setHealthMax(c->getHealthMax() + 300);
        c->setHealth(c->getHealthMax());

        // Add the character to the guild
        Character** temp = new Character*[m_size + 1];
        for (size_t i = 0; i < m_size; i++) {
            temp[i] = m_characterArr[i];
        }
        temp[m_size] = c; // Store the original pointer

        delete[] m_characterArr;
        m_characterArr = temp;
        m_size++;
    }

    // Remove a member (modify the original character)
    void Guild::removeMember(const std::string& name) {
        size_t index = m_size;
        for (size_t i = 0; i < m_size; i++) {
            if (m_characterArr[i]->getName() == name) {
                index = i;
                break;
            }
        }
        if (index == m_size) return;

        // Reduce the original character's health
        Character* charToRemove = m_characterArr[index];
        int newMax = charToRemove->getHealthMax() - 300;
        charToRemove->setHealthMax(newMax);
        if (charToRemove->getHealth() > newMax) {
            charToRemove->setHealth(newMax);
        }

        // Remove the pointer from the array
        Character** temp = new Character*[m_size - 1];
        for (size_t i = 0, j = 0; i < m_size; i++) {
            if (i != index) temp[j++] = m_characterArr[i];
        }

        delete[] m_characterArr;
        m_characterArr = temp;
        m_size--;
    }

    // Access operator
    Character* Guild::operator[](size_t idx) const {
        return (idx < m_size) ? m_characterArr[idx] : nullptr;
    }

    // Display members
    void Guild::showMembers() const {
        
        if (m_characterArr==nullptr||m_guildName=="") {
            std::cout << "No guild." << std::endl;
        } else {
            std::cout << "[Guild] " << m_guildName << std::endl;
            for (size_t i = 0; i < m_size; i++) {
                std::cout << std::setw(4) << ' ' << i + 1 << ": " << *m_characterArr[i] << std::endl;
            }
        }
    }
}