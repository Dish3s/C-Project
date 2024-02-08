#include <string>
#include "PokeType.h"
#include "Abilities.h"

class Pokemon {
private:
    std::string name;
    std::string description;
    PokeType type;
    int level;
    int life;
    Ability abilities[4];

public:
    Pokemon(std::string mName, std::string mDescription, std::string mType, std::string mLevel, std::string mLife, std::string mAbilities);

    std::string GetName();
    std::string GetDescription();
    std::string GetType();
    std::string GetLevel();
    std::string GetLife();

    ~Pokemon();
};