#include "Pokemon.h"
#include "Abilities.h"  
#include <iostream>  

Pokemon::Pokemon()
{
}

Pokemon::Pokemon(std::string mName, std::string mDescription, PokeType mType, int mLevel, int mLife) {
    mName = mName;
    mDescription = mDescription;
    mType = mType;
    mLevel = mLevel;
    mLife = mLife;

    for (int i = 0; i < 4; ++i) {
        abilities[i] = Abilities(0, PokeType::Normal, 0);
    }
}

std::string Pokemon::GetName() {
    return name;
}

std::string Pokemon::GetDescription() {
    return description;
}

PokeType Pokemon::GetType() {
    return type;
}

int Pokemon::GetLevel() {
    return level;
}

int Pokemon::GetLife() {
    return life;
}

void Pokemon::SetType(PokeType mType) {
    type = mType;
}

void Pokemon::SetLevel(int mLevel) {
    level = mLevel;
}

void Pokemon::SetLife(int mLife) {
    life = mLife;
}

void Pokemon::LearnAbility(Abilities ability, int slot) {
    if (slot >= 0 && slot < 4) {
        abilities[slot] = ability;
    }
}

void Pokemon::UseAbility(int slot, Pokemon& target) {
    if (slot >= 0 && slot < 4) {
        abilities[slot].Use();
        int damageAmount = abilities[slot].GetDamageAmount();

        std::cout << name << " used " << abilities[slot].GetName() << " on " << target.GetName() << "!\n";
        target.TakeDamage(damageAmount);
    }
}

void Pokemon::GetInPokeball() {
    std::cout << name << " got inside a Pokeball!\n";
}

void Pokemon::GetOutOfPokeball() {
    std::cout << name << " got out of a Pokeball!\n";
}

void Pokemon::Rest() {
    life += 10;  // Restoring 10 health points
    for (int i = 0; i < 4; ++i) {
        abilities[i].Rest();  // Resetting ability uses
    }
    std::cout << name << " rested and restored health!\n";
}

void Pokemon::TakeDamage(int amount) {
    life -= amount;
    if (life < 0) {
        life = 0;
    }
    std::cout << name << " took " << amount << " damage! Remaining life: " << life << "\n";

    if (life == 0) {
        std::cout << name << " fainted!\n";
    }
}

Pokemon::~Pokemon() {
    std::cout << "Farewell, " << name << "!\n";
}
