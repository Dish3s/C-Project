#include "Trainer.h"

Trainer::Trainer(std::string firstName, std::string lastName, std::string catchphrase, int money, int lifePoints, int numPokeballs){
    firstName = firstName;
    lastName = lastName;
    catchphrase = catchphrase;
    money = money;
    lifePoints = lifePoints;
    numPokeballs = numPokeballs;
}


void Trainer::introduce() {
    // Implement
}

void Trainer::challenge(Trainer& opponent) {
    // Implement
}

void Trainer::capturePokemon(Pokemon wildPokemon) {
    // Implement
}

void Trainer::sendPokemon(int index) {
    // Implement
}

void Trainer::changePokemon(int index, Pokemon newPokemon) {
    // Implement
}

void Trainer::useAbility(int index, Pokemon& target) {
    // Implement
}

void Trainer::earnMoney(int amount) {
    // Implement
}

void Trainer::earnPokeballs(int amount) {
    // Implement
}
