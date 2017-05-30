#pragma once
#include "Fighter.h"

using namespace std;

const int MANA_BONUS = 5; // multiplier to determine start mana
const double ABILITY_RATIO = 3;
const int REGENERATE_MANA_RATIO = 5;
const int MIN_MANA_ADDED = 1;

class Cleric: public Fighter {
public:
    Cleric(string fighterName, int fighterMaxHP, int fighterStrength, int fighterSpeed, int fighterMagic);
    ~Cleric() {}
    bool useAbility();
    void reset();
    void regenerate();
    int getDamage();
private:
    int currentMana;
    int maxMana;
};

