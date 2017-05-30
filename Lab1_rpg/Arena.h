#pragma once
#include "ArenaInterface.h"
#include "FighterInterface.h"
#include "Fighter.h"
#include "Archer.h"
#include "Robot.h"
#include "Cleric.h"
#include <vector>

using namespace std;

class Arena : public ArenaInterface{
public:
    Arena();
    ~Arena();
    bool addFighter(string info);
    bool removeFighter(string name);
    FighterInterface* getFighter(string name);
    int getSize() const;

private:
    std::vector<Fighter*> fighterVector ;
};