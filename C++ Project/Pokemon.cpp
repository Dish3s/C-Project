#include "Pokemon.h"

Pokemon::Pokemon(std::string mName, std::string mDescription, std::string mType, std::string mLevel, std::string mLife, std::string mAbilities) {
    mName = mName;
    mDescription = mDescription;
    mType = mType;
    mLevel = mLevel;
    mLife = mLife;
    mAbilities = mAbilities
}

Pokemon::~Pokemon() {}

std::string Pokemon::GetName() { return name; }
std::string Pokemon::GetDescription() { return description; }
std::string Pokemon::GetType() { return type; }
std::string Pokemon::GetLevel() { return level; }
std::string Pokemon::GetLife() { return mLife; }
