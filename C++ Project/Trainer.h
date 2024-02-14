#ifndef TRAINER_H
#define TRAINER_H

#include <iostream>
#include <string>
#include "Pokemon.h"

class Trainer {
private:
    std::string firstName;
    std::string lastName;
    std::string catchphrase;
    int money;
    int lifePoints;
    Pokemon pokemonTeam[6];
    int numPokeballs;

public:
    Trainer(std::string firstName, std::string lastName, std::string catchphrase, int money, int lifePoints, int numPokeballs);

    void Introduce();
    void Challenge(Trainer& opponent);
    void CapturePokemon(Pokemon wildPokemon);
    void SendPokemon(int index);
    void ChangePokemon(int index, Pokemon newPokemon);
    void UseAbility(int index, Pokemon& target);
    void EarnMoney(int amount);
    void EarnPokeballs(int amount);

    void BattleWildPokemon(Pokemon& wildPokemon);
    void AddToTeam(Pokemon newPokemon);

private:
    int GetNextAvailablePokemonIndex();
    bool HasAvailablePokemon();
    void DisplayPokemonTeam();
    void DisplayPokemonAbilities(const Pokemon& pokemon);
};

#endif
