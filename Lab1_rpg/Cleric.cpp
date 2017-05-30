#include "Cleric.h"

using namespace std;
const int MANA_REGENERATE = 5;
const int ABILITY_CONST = 3;


Cleric::Cleric(string fighterName, int fighterMaxHP, int fighterStrength, int fighterSpeed, int fighterMagic)
    :Fighter(fighterName, fighterMaxHP, fighterStrength, fighterSpeed, fighterMagic){
        maxMana = fighterMagic * MANA_BONUS;
        currentMana = maxMana;
    }
    
int Cleric::getDamage() {
		return magic;
	}

void Cleric::reset() {
	Fighter::reset();
		currentMana = maxMana;
	}
	
void Cleric::regenerate() {
	Fighter::regenerate();
	currentMana = currentMana + (magic / MANA_REGENERATE);
		if (currentMana > maxMana) {
			currentMana = maxMana;
		}
	}


bool Cleric::useAbility() {
	
	if (currentMana > CLERIC_ABILITY_COST){
		currentHP = currentHP + (magic/ABILITY_CONST);
		currentMana = currentMana - CLERIC_ABILITY_COST;
		if ((magic / ABILITY_CONST) < MIN_DAMAGE){
			currentHP = currentHP + MIN_DAMAGE;
		}
		if (currentHP > maxHP){
			currentHP = maxHP;
		}
		return true;
		
	}
	
	return false;
}
