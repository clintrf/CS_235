#include "Archer.h"
using namespace std;

Archer::Archer(string fighterName, int fighterMaxHP, int fighterStrength, int fighterSpeed, int fighterMagic) 
	:Fighter(fighterName, fighterMaxHP, fighterStrength, fighterSpeed, fighterMagic){
	startSpeed = fighterSpeed;
	}
int Archer::getDamage() {
		return speed;
	}

void Archer::reset() {
		currentHP = maxHP;
		speed = startSpeed;
	}
	

bool Archer::useAbility() {
		speed = speed + ABILITY_SPEED_INCREASE;
		return true;
	}