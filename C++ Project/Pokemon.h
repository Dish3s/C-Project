#ifndef POKEMON_H
#define POKEMON_H

#include <iostream>
#include <vector>
#include "Abilities.h"
#include "PokeType.h"

class Pokemon {
private:
    std::string name;
    std::string description;
    PokeType pokeType;
    int level;
    int life;
    std::vector<Ability> abilities;

public:
    Pokemon();
    Pokemon(std::string n, std::string desc, PokeType type, int lvl, int hp);
    void useAbility(int abilityIndex, Pokemon& target);
    void useAbility(int abilityIndex, const Pokemon& target) const;
    void restAbilities();
    void learnAbility(const Ability& newAbility);

    std::string getName() const;
    int getLife() const;
    const std::vector<Ability>& getAbilities() const;
};
#endif
