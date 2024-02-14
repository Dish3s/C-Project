#include "Trainer.h"
#include "Pokemon.h"
#include <iostream>
#include <chrono>
#include <thread>
#include <cstdlib>

Trainer::Trainer(std::string firstName, std::string lastName, std::string catchphrase, int money, int lifePoints, int numPokeballs) {
    firstName = firstName;
    lastName = lastName;
    catchphrase = catchphrase;
    money = money;
    lifePoints = lifePoints;
    numPokeballs = numPokeballs;
}

void Trainer::DisplayPokemonTeam() {
    std::cout << "Pokemon Team:\n";
    for (int i = 0; i < 6; ++i) {
        if (!pokemonTeam[i].GetName().empty()) {
            std::cout << i + 1 << ". " << pokemonTeam[i].GetName() << " (Level " << pokemonTeam[i].GetLevel() << ")\n";
        }
        else {
            std::cout << i + 1 << ". [Empty Slot]\n";
        }
    }
}

void Trainer::DisplayPokemonAbilities(const Pokemon& pokemon) {
    std::cout << "Abilities of " << pokemon.name << ":\n";
    for (const auto& abilities : pokemon.abilities) {
        std::cout << "- " << abilities.GetName();
    }
}

int Trainer::GetNextAvailablePokemonIndex() {
    for (int i = 0; i < 6; ++i) {
        if (pokemonTeam[i].GetName().empty()) {
            return i;
        }
    }
    return -1;  // No available slot
}

bool Trainer::HasAvailablePokemon() {
    for (int i = 0; i < 6; ++i) {
        if (!pokemonTeam[i].GetName().empty() && pokemonTeam[i].GetLife() > 0) {
            return true;
        }
    }
    return false;
}

void Trainer::BattleWildPokemon(Pokemon& wildPokemon) {
    std::cout << "A wild " << wildPokemon.GetName() << " appeared!\n";

    // Trainer chooses a Pokemon to send into battle
    int chosenPokemonIndex;
    do {
        std::cout << "Choose a Pokemon to send into battle:\n";
        DisplayPokemonTeam();
        std::cin >> chosenPokemonIndex;
    } while (chosenPokemonIndex <= 0 || chosenPokemonIndex > 6 || pokemonTeam[chosenPokemonIndex - 1].GetName().empty());

    Pokemon& activePokemon = pokemonTeam[chosenPokemonIndex - 1];

    // Battle loop
    while (true) {
        std::cout << "Your " << activePokemon.GetName() << " vs. wild " << wildPokemon.GetName() << "!\n";
        std::cout << "1. Use Pokemon Ability\n";
        std::cout << "2. Attempt to Capture\n";
        std::cout << "3. Run Away\n";

        int choice;
        std::cin >> choice;

        switch (choice) {
        case 1: {
            // Trainer chooses an ability to use
            int chosenAbilityIndex;
            do {
                std::cout << "Choose an ability to use:\n";
                DisplayPokemonAbilities(activePokemon);
                std::cin >> chosenAbilityIndex;
            } while (chosenAbilityIndex <= 0 || chosenAbilityIndex > 4);

            activePokemon.UseAbility(chosenAbilityIndex - 1, wildPokemon);
            break;
        }
        case 2: {
            // Attempt to capture the wild Pokemon
            if (numPokeballs > 0) {
                std::cout << "Throwing a Pokeball...\n";
                std::this_thread::sleep_for(std::chrono::seconds(2));

                // Capture success is based on a random chance
                if (std::rand() % 2 == 0) {
                    std::cout << "Congratulations! You captured the wild " << wildPokemon.GetName() << "!\n";
                    pokemonTeam[GetNextAvailablePokemonIndex()] = wildPokemon;
                    return;
                }
                else {
                    std::cout << "Oh no! The wild " << wildPokemon.GetName() << " broke free.\n";
                }

                numPokeballs--;
                std::cout << "Remaining Pokeballs: " << numPokeballs << "\n";
            }
            else {
                std::cout << "You don't have any Pokeballs left!\n";
            }
            break;
        }
        case 3: {
            // Run away from the battle
            std::cout << "You fled from the battle!\n";
            return;
        }
        default:
            std::cout << "Invalid choice. Try again.\n";
        }

        // Wild Pokemon counterattacks
        wildPokemon.UseAbility(std::rand() % 4, activePokemon);

        // Check if the player's Pokemon fainted
        if (activePokemon.GetLife() <= 0) {
            std::cout << "Your " << activePokemon.GetName() << " fainted!\n";

            // Choose another Pokemon if available
            if (HasAvailablePokemon()) {
                do {
                    std::cout << "Choose another Pokemon to send into battle:\n";
                    DisplayPokemonTeam();
                    std::cin >> chosenPokemonIndex;
                } while (chosenPokemonIndex <= 0 || chosenPokemonIndex > 6 || pokemonTeam[chosenPokemonIndex - 1].GetName().empty());

                activePokemon = pokemonTeam[chosenPokemonIndex - 1];
            }
            else {
                std::cout << "All your Pokemon fainted! You blacked out...\n";
                std::this_thread::sleep_for(std::chrono::seconds(2));
                std::exit(0);
            }
        }
    }
}
