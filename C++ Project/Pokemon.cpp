#include "Pokemon.h"
#include "iostream"

Pokemon::Pokemon(std::string name, std::string pokedex, std::string abilities) {
	name = name;
	pokedex = pokedex;
	abilities = abilities;
}
Pokemon::~Pokemon(){}

std::string Pokemon::GetName() { return mName; }
std::string Pokemon::GetPokedex() { return mPokedex; }
std::vector<std::string> Pokemon::GetAbilities() { return mAbilities; }
