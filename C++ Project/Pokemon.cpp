#include "Pokemon.h"
#include "Abilities.h"

Pokemon::Pokemon(std::string n, std::string desc, PokeType type, int lvl, int hp)
    : name(n), description(desc), pokeType(type), level(lvl), life(hp) {}

void Pokemon::useAbility(int abilityIndex) const {
    if (abilityIndex >= 0 && abilityIndex < abilities.size()) {
        abilities[abilityIndex].useAbility();
    }
    else {
        std::cout << "Invalid ability index.\n";
    }
}

void Pokemon::restAbilities() {
    for (auto& ability : abilities) {
        ability.rest();
    }
}

void Pokemon::learnAbility(const Ability& newAbility) {
    abilities.push_back(newAbility);
    std::cout << name << " learned a new ability: " << newAbility.getName() << "!\n";
}

std::string Pokemon::getName() const {
    return name;
}

int Pokemon::getLife() const {
    return life;
}

const std::vector<Ability>& Pokemon::getAbilities() const {
    return abilities;
}

