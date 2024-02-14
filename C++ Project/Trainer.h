
#pragma once

#include <iostream>
#include <vector>
#include "Pokemon.h"
#include "Abilities.h"

class Trainer {
private:
    std::string firstName;
    std::string lastName;
    std::string catchphrase;
    int money;
    int lifePoints;
    std::vector<Pokemon> team;
    int pokeballs;

public:
    Trainer(std::string first, std::string last, std::string phrase, int startingMoney, int startingLife, int startingPokeballs);

    void introduce() const;
    void startBattle(Trainer& opponent);
    void captureWildPokemon(const Pokemon& wildPokemon);
    void sendPokemon(int index);
    void useAbility(const Pokemon& attacker, const Pokemon& target, const std::string& ability);
    void earnMoney(int amount);
    void earnPokeballs(int amount);

    std::string getFirstName() const;
    const std::vector<Pokemon>& getTeam() const;
    void restTeam();
    void addPokemonToTeam(const Pokemon& newPokemon);
};
