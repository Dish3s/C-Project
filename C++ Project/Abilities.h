#pragma once

#include <string>
#include "PokeType.h"
#include "Abilities.h"

class Abilities {
private:
    std::string name;
    int damageAmount;
    PokeType attackType;
    int numUses;

public:
    Abilities();

    Abilities(int damageAmount, PokeType attackType, int numUses);

    std::string GetName();
    int GetDamageAmount();
    PokeType GetAttackType();
    int GetNumUses();

    void Use();
    void Rest();
};