#include "Shop.h"
#include "Abilities.h"

Shop::Shop() {
    Pokemon bulbasaur("Bulbasaur", "A grass/poison-type Pokemon", PokeType::Grass, 9, 48);
    Ability tackle("tackle", 15, PokeType::Normal, 10);
    bulbasaur.learnAbility(tackle);
    availablePokemon.push_back(bulbasaur);

}

void Shop::DisplayAvailablePokemon() const {
    std::cout << "Available Pokemon in the shop:\n";
    for (size_t i = 0; i < availablePokemon.size(); ++i) {
        std::cout << i + 1 << ". " << availablePokemon[i].getName() << "\n";
    }
}
const std::vector<Pokemon>& Shop::getAvailablePokemon() const {
    return availablePokemon;
}

Pokemon Shop::PurchasePokemon(int choice) {
    if (choice >= 1 && choice <= availablePokemon.size()) {
        Pokemon purchasedPokemon = availablePokemon[choice - 1];
        availablePokemon.erase(availablePokemon.begin() + choice - 1);
        return purchasedPokemon;
    }
    else {
        std::cout << "Invalid choice. Returning default Pokemon.\n";
        return Pokemon("Default", "A default Pokemon", PokeType::Normal, 10, 20);
    }
}
