#include "Pokemon.h"

Pokemon::Pokemon(std::string mName, std::string mDescription, PokeType mType, std::string mLevel, std::string mLife) {
	mName = mName;
	mDescription = mDescription;
	mType = mType;
	mLevel = mLevel;
	mLife = mLife;
}

Pokemon::~Pokemon() {}

std::string Pokemon::GetName() { return mName; }
std::string Pokemon::GetDescription() { return mDescription; }
PokeType Pokemon::GetType() { return mType; }
std::string Pokemon::GetLevel() { return mLevel; }
std::string Pokemon::GetLife() { return mLife; }
