#include "Shop.h"
#include <iostream>

Shop::Shop() {
    availablePokemon.push_back(Pokemon("Charmander", "A fire lizard Pokemon", PokeType::Fire, 10, 30));
    availablePokemon.push_back(Pokemon("Squirtle", "A water turtle Pokemon", PokeType::Water, 10, 30));
    availablePokemon.push_back(Pokemon("Bulbasaur", "A grass seed Pokemon", PokeType::Grass, 10, 30));
}

void Shop::DisplayAvailablePokemon() {
    std::cout << "Available Pokemon in the shop:\n";
    for (size_t i = 0; i < availablePokemon.size(); ++i) {
        std::cout << i + 1 << ". " << availablePokemon[i].GetName() << " (Level " << availablePokemon[i].GetLevel() << ")\n";
    }
}

Pokemon Shop::PurchasePokemon(int index) {
    return availablePokemon[index - 1];
}
