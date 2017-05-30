#include "Fighter.h"
using namespace std;

const int DAMAGE_DIVIDER = 4;

const int REGENERATE_DIVIDER = 6;

    Fighter::Fighter(string fighterName, int fighterMaxHP, int fighterStrength, int fighterSpeed, int fighterMagic){
        name = fighterName;
        maxHP = fighterMaxHP;
        currentHP = fighterMaxHP;
        strength = fighterStrength;
        speed = fighterSpeed;
        magic = fighterMagic;
    }
    
    string Fighter::getName() const{
        return name;
    }
    int Fighter::getMaximumHP() const{
        return maxHP;
    }
    int Fighter::getCurrentHP() const{
        return currentHP;
    }
    int Fighter::getStrength() const{
        return strength;
    }
    int Fighter::getSpeed() const{
        return speed;
    }
    int Fighter::getMagic() const{
        return magic;
    }
    void Fighter::takeDamage(int damage){
        cout << name << " damage " << damage << " currentHP " << currentHP << endl;
        
        damage = damage - (speed/4);
        if(damage <= 0){
            currentHP = currentHP - MIN_DAMAGE;
        }
        else{
            currentHP = currentHP - damage;
        }
    }
    void Fighter::reset(){
        currentHP = maxHP;
        
    }
    void Fighter::regenerate(){
        currentHP = currentHP + (strength / REGENERATE_DIVIDER);
        if ((strength / REGENERATE_DIVIDER) < MIN_DAMAGE){
            currentHP = currentHP + MIN_DAMAGE;
        }
        if (currentHP > maxHP){
            currentHP = maxHP;
        }
    }
    
    