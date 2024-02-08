#include "Abilities.h"

Ability::Ability(int damageAmount, PokeType attackType, int numUses) 
    : damageAmount(damageAmount), attackType(attackType), numUses(numUses) {}

void Ability::use() {
    if (numUses > 0) {
        // Perform attack
        numUses--;
    } else {
        // Handle no uses left
    }
}

void Ability::rest() {
    // Reset uses after resting
    numUses = 5;
}
