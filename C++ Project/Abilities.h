#ifndef ABILITIES_H
#define ABILITIES_H

#include <iostream>
#include "PokeType.h"

class Pokemon; 

class Ability {
private:
    std::string name;
    int damageAmount;
    PokeType attackType;
    int maxUses;
    int remainingUses;

public:
    Ability(std::string n, int damage, PokeType type, int uses);
    void useAbility(const Pokemon& target);
    void rest();

    std::string getName() const;
};
#endif