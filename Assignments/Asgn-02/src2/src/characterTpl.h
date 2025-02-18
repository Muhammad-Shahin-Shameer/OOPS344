#ifndef SENECA_CHARACTERTPL_H
#define SENECA_CHARACTERTPL_H
#include <iostream>
#include "character.h"
namespace seneca {
    template <typename T>
    class CharacterTpL : public Character {
        int m_healthMax;
        T m_health;
    public:
        CharacterTpL(const char* name, int healthMax) : Character(name) {
            m_healthMax = healthMax;
            m_health = healthMax;
        }
    void takeDamage(int dmg)override {
      this->m_health -= dmg; //  update health
      if(m_health<0){
        m_health = 0;
      }
      if (!isAlive()) { // Check if the character is dead
        // std::cout << getName() << " has been defeated!" << std::endl;
        std::cout << std::setw(4) << ' ' << getName() << " has been defeated!" << std::endl;
      }
      else {
        std::cout << std::setw(4) << ' ' << getName() << " took " << dmg << " damage, " << getHealth() << " health remaining." << std::endl;
      }
    }

    int getHealth() const override {
      return static_cast<int>(m_health);
    }

    int getHealthMax() const override {

      return m_healthMax;
    }

    void setHealth(int health) override {
      // set the parameter value to currect health
      m_health = health;

    }

    void setHealthMax(int health) override {
      m_healthMax = health;
      m_health = health;

    }
    
    int getAttackAmnt() const override {
      return 0;
    }

    int getDefenseAmnt() const override {
      return 0;
    }

    Character* clone() const override {
      return new CharacterTpL<T>(*this);
    }

    void attack(Character* enemy) override {
      return;
    }



    //class closing
  };


  //name space closong
};






#endif