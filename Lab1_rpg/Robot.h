#pragma once
#include "Fighter.h"

using namespace std;

const int ENERGY_MULTIPLIER = 2;




class Robot: public Fighter{
public:
    Robot (string fighterName, int fighterMaxHP, int fighterStrength, int fighterSpeed, int fighterMagic);
    ~Robot() {}
    int getDamage();
    void reset();
    bool useAbility();
private:
    int currentEnergy;
    int maxEnergy;
    double bonusDamage;
};