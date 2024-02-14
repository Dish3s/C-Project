#include "Abilities.h"
#include "Pokemon.h"
#include <iostream>

Ability::Ability(std::string n, int damage, PokeType type, int uses)
    : name(n), damageAmount(damage), attackType(type), maxUses(uses), remainingUses(uses) {}

void Ability::useAbility(Pokemon& target) {
    if (remainingUses > 0) {
        std::cout << name << " deals " << damageAmount << " damage of type " << static_cast<int>(attackType)
            << " to " << target.getName() << ".\n";
        remainingUses--;
    }
    else {
        std::cout << name << " has no remaining uses. Please rest to restore uses.\n";
    }
}

void Ability::rest() {
    remainingUses = maxUses;
    std::cout << name << " has been rested. Remaining uses restored to " << maxUses << ".\n";
}

std::string Ability::getName() const {
    return name;
}