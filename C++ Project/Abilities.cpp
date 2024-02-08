#include "Abilities.h"

Abilities::Abilities(int damageAmount, PokeType attackType, int numUses) {
    damageAmount = damageAmount;
    attackType = attackType;
    numUses = numUses;
}

void Abilities::use() {
    if (numUses > 0) {
        // Perform attack
        numUses--;
    } else {
        // Handle no uses left
    }
}

void Abilities::rest() {
    // Reset uses after resting
    numUses = 5;
}
