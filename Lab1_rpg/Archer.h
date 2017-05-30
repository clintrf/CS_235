#pragma once
#include "Fighter.h"
using namespace std;

const int ABILITY_SPEED_INCREASE = 1;

class Archer: public Fighter{
public:
    Archer(string fighterName, int fighterMaxHP, int fighterStrength, int fighterSpeed, int fighterMagic);
    ~Archer() {}
    int getDamage();
    void reset();
    bool useAbility();
private:
    int startSpeed;
};