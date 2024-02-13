#include "Abilities.h"

Abilities::Abilities(int damageAmount, PokeType attackType, int numUses) {
    damageAmount = damageAmount;
    attackType = attackType;
    numUses = numUses;
}

int Abilities::GetDamageAmount() {
    return damageAmount;
}

PokeType Abilities::GetAttackType() {
    return attackType;
}

int Abilities::GetNumUses() {
    return numUses;
}

void Abilities::Use() {
    if (numUses > 0) {
        // Perform attack
        numUses--;
    }
    else {
        // Handle no uses left
    }
}

void Abilities::Rest() {
    // Reset uses after resting
    numUses = 5;
}