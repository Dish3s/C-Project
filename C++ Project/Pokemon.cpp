#include "Pokemon.h"

Pokemon::Pokemon(std::string mName, std::string mDescription, PokeType mType, int mLevel, int mLife) {
	mName = mName;
	mDescription = mDescription;
	mType = mType;
	mLevel = mLevel;
	mLife = mLife;
}
Pokemon::~Pokemon() {}

std::string Pokemon::GetName() { return name; }
std::string Pokemon::GetDescription() { return description; }
PokeType Pokemon::GetType() { return type; }
int Pokemon::GetLevel() { return level; }
int Pokemon::GetLife() { return life; }
