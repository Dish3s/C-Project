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
    Abilities abilities[4];

public:
    Pokemon(std::string mName, std::string mDescription, PokeType mType, int mLevel, int mLife, Abilities mAbilities[4]);

    std::string GetName();
    std::string GetDescription();
    PokeType GetType();
    int GetLevel();
    int GetLife();

    void SetType(PokeType mType);
    void SetLevel(int mLevel);
    void SetLife(int mLife);

    Pokemon(std::string mName, std::string mDescription, PokeType mType, int mLevel, int mLife);

    ~Pokemon();
};
