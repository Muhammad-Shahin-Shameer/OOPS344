
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
#ifndef SENECA_ROGUE_H
#define SENECA_ROGUE_H

#include "characterTpl.h"
#include "character.h"

namespace seneca {
    template <typename T, typename FirstAbility_t, typename SecondAbility_t>
    class Rogue : public CharacterTpL<T> {
        int m_baseAttack;
        int m_baseDefense;
        FirstAbility_t m_firstAbility;
        SecondAbility_t m_secondAbility;
        seneca::Dagger m_weapon;
    public:
        Rogue(const char* name, int healthMax, int baseAttack, int baseDefense) 
            : CharacterTpL<T>(name, healthMax), m_baseAttack(baseAttack), m_baseDefense(baseDefense) {
        }

        int getAttackAmnt() const override {
            return m_baseAttack + 2*static_cast<double>(m_weapon);
        }

        int getDefenseAmnt() const override {
            return m_baseDefense;
        }

        Character* clone() const override {
            return new Rogue<T, FirstAbility_t, SecondAbility_t>(*this);
        }

        void attack(Character* enemy) override {
            std::cout << this->getName() << " is attacking " << enemy->getName() << "." << std::endl;
            m_firstAbility.useAbility(this);
            m_secondAbility.useAbility(this);
            int damage = this->getAttackAmnt();
            m_firstAbility.transformDamageDealt(damage);
            m_secondAbility.transformDamageDealt(damage);
            std::cout << "Rogue deals " << damage << " damage!" << std::endl;
            enemy->takeDamage(damage);
        }

        void takeDamage(int dmg) override {
            std::cout << this->getName() << " is attacked for " << dmg << " damage." << std::endl;
            int new_damage = dmg-m_baseDefense;
            m_firstAbility.transformDamageReceived(new_damage);
            m_secondAbility.transformDamageReceived(new_damage);
            CharacterTpL<T>::takeDamage(new_damage); 
        }
    
    //class clo
      };
}

#endif