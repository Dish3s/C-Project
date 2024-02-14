#pragma once

#include "Pokemon.h"
#include <vector>

class Shop {
private:
    std::vector<Pokemon> availablePokemon;

public:
    Shop();

    void DisplayAvailablePokemon() const;
    Pokemon PurchasePokemon(int choice);
    const std::vector<Pokemon>& getAvailablePokemon() const;
};
