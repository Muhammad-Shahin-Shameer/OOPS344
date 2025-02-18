#ifndef SENECA_ARCHER_H
#define SENECA_ARCHER_H
#include "characterTpl.h"
#include "character.h"

#include <iostream>
namespace seneca {

  template <typename Weapon_t>
  class Archer : public CharacterTpL<seneca::SuperHealth> {

  private:

    int m_baseDefense;
    int m_baseAttack;
    Weapon_t m_weapon;

  public:

    Archer(const char* name, int healthMax, int baseAttack, int baseDefense, Weapon_t weapon)
      : CharacterTpL<seneca::SuperHealth>(name, healthMax), m_baseDefense(baseDefense), m_baseAttack(baseAttack), m_weapon(weapon) {
    }


    int getAttackAmnt() const override {

      return static_cast<int>(1.3 * m_baseAttack);


    }

    int getDefenseAmnt() const override {
      return static_cast<int>(1.2 * m_baseDefense);
    }

    Character* clone() const override {

      return new Archer<Weapon_t>(*this);
    }

    void attack(Character* enemy) override {

      std::cout << getName() << " is attacking " << enemy->getName() << "." << std::endl;

      int attackDamage = getAttackAmnt();

      std::cout << std::setw(4) << ' '<< "Archer deals " << attackDamage << " ranged damage!" << std::endl;
      //apply damage to eney
      enemy->takeDamage(attackDamage);
    }

    void takeDamage(int dmg) {

      int defense = getDefenseAmnt();

      std::cout << getName() << " is attacked for " << dmg << " damage." << std::endl;

      std::cout << std::setw(4) << ' ' << "Archer has a defense of " << defense << ". Reducing damage received." << std::endl;

      int damage= dmg- defense;
      if (damage < 0) {
        damage = 0;
      }

      CharacterTpL<seneca::SuperHealth>::takeDamage(damage);

    }

    //class ending
  };

  //namespace closing
}



#endif
