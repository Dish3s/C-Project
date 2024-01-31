#pragma once
#include <iostream>
#include <vector>
#include <string>


class Pokemon
{
private:
	std::string mName;
	std::string mPokedex;
	int Life;
	std::vector<std::string> mAbilities;

public:
	Pokemon(std::string name, std::string pokedex, std::string abilities);
	~Pokemon();
	std::string GetName();
	std::string GetPokedex();
	std::vector<std::string> GetAbilities();
};

