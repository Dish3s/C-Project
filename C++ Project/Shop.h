#ifndef SHOP_H
#define SHOP_H

#include <vector>
#include "Pokemon.h"

class Shop {
private:
    std::vector<Pokemon> availablePokemon;

public:
    Shop();

    void DisplayAvailablePokemon();
    Pokemon PurchasePokemon(int index);
};

#endif
