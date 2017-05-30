#include "Arena.h"
#include <iostream>
#include <ios>
#include <sstream>

using namespace std;

Arena::Arena(){
    
}
Arena::~Arena(){
    
}
bool Arena::addFighter(string info){
	stringstream ss(info);
	string name;
	string type;
	string empty;
	int maxHp;
	int strength;
	int speed;
	int magic;
	ss >> name >> type >> maxHp >> strength >> speed >> magic;
	
	for (int i = 0; i < fighterVector.size(); ++i){
	    if(name == fighterVector.at(i)->getName()){
	            return false;
	    }
	}
	if (ss.fail()){
	    ss.clear();
	    return false;
	}
	ss >> empty;
	if (ss.fail()){
	    ss.clear();
	}
	else {
	    ss.clear();
	    return false;
	}
	if (type == "A"){
	    fighterVector.push_back(new Archer(name, maxHp, strength, speed, magic));
	}
	if (type == "C"){
	    fighterVector.push_back(new Cleric(name, maxHp, strength, speed, magic));
	}
	if (type == "R"){
	    fighterVector.push_back(new Robot(name, maxHp, strength, speed, magic));
	}
	return true;
}
bool Arena::removeFighter(string name){
	for(int i = 0; i < fighterVector.size(); ++i){
	    if (name == fighterVector.at(i)->getName()){
	    	delete fighterVector.at(i);
	        fighterVector.erase(fighterVector.begin() + i);
	        return true;
	    }
	}
	return false;
}
FighterInterface* Arena::getFighter(string name){
    for (int i = 0; i < fighterVector.size(); ++i){
        if (name == fighterVector.at(i)->getName()){
            return fighterVector.at(i);
        }
    }
    return NULL;
}
int Arena::getSize() const{
    return fighterVector.size();
}