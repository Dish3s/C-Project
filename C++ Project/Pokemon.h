#pragma once

#include <string>
#include "PokeType.h"
#include "Abilities.h"


class Pokemon {
public:
    std::string name;
    std::string description;
    PokeType type; 
    int level;
    int life;
    Abilities abilities[4];


public:
    Pokemon();

    Pokemon(std::string mName, std::string mDescription, PokeType mType, int mLevel, int mLife);

    std::string GetName();
    std::string GetDescription();
    PokeType GetType();
    int GetLevel();
    int GetLife();

    void SetType(PokeType mType);
    void SetLevel(int mLevel);
    void SetLife(int mLife);

    void LearnAbility(Abilities ability, int slot);
    void UseAbility(int index, Pokemon& target);
    void GetInPokeball();
    void GetOutOfPokeball();
    void Rest();
    void TakeDamage(int amount);

    ~Pokemon();
};