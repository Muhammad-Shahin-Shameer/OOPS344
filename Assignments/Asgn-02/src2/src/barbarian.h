#ifndef SENECA_BARBARIAN_H
#define SENECA_BARBARIAN_H

#include "characterTpl.h"
#include "character.h"

namespace seneca {
    template <typename T, typename Ability_t, typename Weapon_t>
    class Barbarian : public CharacterTpL<T> {
        int m_baseAttack;
        int m_baseDefense;
        Ability_t m_ability;
        Weapon_t m_weapon[2];
    public:
        Barbarian(const char* name, int healthMax, int baseAttack, int baseDefense, Weapon_t primaryWeapon, Weapon_t secondaryWeapon)
            : CharacterTpL<T>(name, healthMax) {
            m_baseAttack = baseAttack;
            m_baseDefense = baseDefense;
            m_weapon[0] = primaryWeapon;
            m_weapon[1] = secondaryWeapon;
        }

        int getAttackAmnt() const override {
            return (m_baseAttack)+(0.5*static_cast<double>(m_weapon[0]))+(0.5*static_cast<int>(m_weapon[1]));
        }

        int getDefenseAmnt() const override {
            return m_baseDefense;
        }

        Character* clone() const override {
            return new Barbarian<T, Ability_t, Weapon_t>(*this);
        }

    void attack(Character* enemy) override {
      // Print attacking message
      std::cout << this->getName() << " is attacking " << enemy->getName() << "." << std::endl;

      // Activate special ability on self
      m_ability.useAbility(this);

      // getting the damage that the charetr can make
      int damage = getAttackAmnt();

      // Enhance damage with ability effect
      m_ability.transformDamageDealt(damage);

      // Print damage  message
      std::cout << std::setw(4) << ' ' << "Barbarian deals " << damage << " melee damage!" << std::endl;

      // Apply damage to the enemy
      enemy->takeDamage(damage);
    }

    void takeDamage(int dmg) override {

      std::cout << this->getName() << " is attacked for " << dmg << " damage." << std::endl; 
           
      std::cout << std::setw(4) << ' ' << "Barbarian has a defense of " << m_baseDefense << ". Reducing damage received." << std::endl;

      int damage = dmg- m_baseDefense;

      if (damage < 0)
      {
        damage = 0;
      }

      m_ability.transformDamageReceived(damage);
      CharacterTpL<T>::takeDamage(damage);




    }



    // class closing
  };
  //namespace closing
};


#endif