#include "Robot.h"
#include <cmath>
using namespace std;

//const double BONUS_DAMAGE_CONST = 4;

    
Robot::Robot(string fighterName, int fighterMaxHP, int fighterStrength, int fighterSpeed, int fighterMagic) 
	:Fighter(fighterName, fighterMaxHP, fighterStrength, fighterSpeed, fighterMagic){
		maxEnergy = fighterMagic * ENERGY_MULTIPLIER;
    	currentEnergy = maxEnergy;
        currentHP = maxHP;
    	bonusDamage = 0;
} 

int Robot::getDamage() {
		int damage ;
		damage = strength + bonusDamage;
		bonusDamage = 0;
		return damage;
	}
void Robot::reset() {
		currentHP = maxHP;
		currentEnergy = maxEnergy;
		bonusDamage = 0.0;
	}
bool Robot::useAbility() {
		if (currentEnergy >= ROBOT_ABILITY_COST) {
			double temp = double(strength)*pow((double(currentEnergy)/double(maxEnergy)), 4);
        	bonusDamage = int(temp);
			
			currentEnergy = currentEnergy - ROBOT_ABILITY_COST;
			return true;
		}
		return false;
	}
