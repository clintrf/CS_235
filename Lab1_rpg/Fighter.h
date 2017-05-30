#pragma once
#include "FighterInterface.h"
using namespace std;
const int MIN_DAMAGE = 1;

class Fighter : public FighterInterface{
public:
    Fighter();
    Fighter(std::string fighterName = "None", int fighterMaxHP = 0, int fighterStrength = 0, int fighterSpeed = 0, int fighterMagic = 0);
    ~Fighter() {}
    
    string getName() const;
    int getMaximumHP() const;
    int getCurrentHP() const;
    int getStrength() const;
    int getSpeed() const;
    int getMagic() const;
    virtual int getDamage() = 0;
    virtual void takeDamage(int damage);
    virtual void reset();
    virtual void regenerate();
    virtual bool useAbility() = 0;
    
protected:
    string name;
    int maxHP;
    int currentHP;
    int strength;
    int speed;
    int magic;
    
};