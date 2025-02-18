
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

#ifndef SENECA_ARCHER_H
#define SENECA_ARCHER_H

#include <iostream>
#include "characterTpl.h"
#include "character.h"

namespace seneca {
    template <typename Weapon_t>
    class Archer : public CharacterTpL<seneca::SuperHealth> {
        int m_baseDefense;
        int m_baseAttack;
        Weapon_t m_weapon;
    public:
        Archer(const char* name, int healthMax, int baseAttack, int baseDefense, Weapon_t weapon) 
            : CharacterTpL<seneca::SuperHealth>(name, healthMax), m_baseDefense(baseDefense), m_baseAttack(baseAttack), m_weapon(weapon) {
        }

        int getAttackAmnt() const override {
            return 1.3 * m_baseAttack;
        }

        int getDefenseAmnt() const override {
            return 1.2 * m_baseDefense;
        }

        Character* clone() const override {
            return new Archer<Weapon_t>(*this);
        }

        void attack(Character* enemy) override {
            std::cout << this->getName() << " is attacking " << enemy->getName() << "." << std::endl;
            int damage = this->getAttackAmnt();
            std::cout << "Archer deals " << damage << " ranged damage!" << std::endl;
            enemy->takeDamage(damage);
        }

        void takeDamage(int dmg) override {
            std::cout << this->getName() << " is attacked for " << dmg << " damage." << std::endl;
            
            std::cout << std::setw(4) << ' ' << "Archer has a defense of " << m_baseDefense << ". Reducing damage received." << std::endl;
            int new_damage = dmg - m_baseDefense;
            if (new_damage < 0) {
                new_damage = 0;
            }
            CharacterTpL<seneca::SuperHealth>::takeDamage(new_damage); 
        }

       
    };
}

#endif