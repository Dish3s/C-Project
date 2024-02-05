#ifndef POKEMON_H
#define POKEMON_H

#include <string>
#include <vector>

enum PokeType {
    NORMAL,
    FIRE,
    WATER,
    ELECTRIC,
    GRASS,
    ICE,
    FIGHTING,
    POISON,
    GROUND,
    FLYING,
    PSYCHIC,
    BUG,
    ROCK,
    GHOST,
    DRAGON,
    DARK,
    STEEL,
    FAIRY
};



class Pokemon {
public:
    Pokemon(std::string name, std::string description, PokeType type, std::string level, std::string life);
    ~Pokemon();

    std::string GetName();
    std::string GetDescription();
    PokeType GetType();
    std::string GetLevel();
    std::string GetLife();

private:
    std::string mName;
    std::string mDescription;
    PokeType mType;
    std::string mLevel;
    std::string mLife;
    std::vector<std::string> mAbilities;
};

#endif
