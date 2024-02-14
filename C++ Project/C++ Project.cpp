#include <chrono>
#include <thread>
#include <iostream>
#include "PokeType.h"
#include "Abilities.h" 
#include "Pokemon.h"
#include "Trainer.h"
#include "Shop.h"

bool askYesNoQuestion(const std::string& question) {
    std::string answer;
    std::cout << question << " (Yes/No)\n";
    while (true) {
        std::cin >> answer;
        if (answer == "Yes" || answer == "yes") {
            return true;
        }
        else if (answer == "No" || answer == "no") {
            return false;
        }
        else {
            std::cout << "Invalid answer. Please enter 'Yes' or 'No'.\n";
        }
    }
}

int main() {
    // Introduction
    system("cls");
    std::cout << "You wake up in what seems to be a vast, grassy field, the blades swaying gently in the breeze.";

    // Initialize the player
    Trainer player("Ash", "Ketchum", "I choose you!", 100, 100, 5);

    // Decision to get up
    if (askYesNoQuestion("\nDo you get up?")) {
        // Explore the forest
        std::cout << "\nIn the distance, you spot a dense forest.\n";
        std::cout << "\nYou decide to explore the forest. As you enter, you hear rustling in the bushes.\n";
        std::cout << "Suddenly, a wild Pokemon appears!\n";

        if (askYesNoQuestion("Do you want to run away?")) {
            // Run away
            system("cls");
            std::cout << "\nYou quickly turn around and run back into the open field, leaving the forest behind.\n";
            std::cout << "After catching your breath, you realize you have no means to defend yourself against wild Pokemon.\n";
            std::cout << "\nSo you look around...\n";
            std::this_thread::sleep_for(std::chrono::seconds(2));
            std::cout << "You've been walking for a while through tall grass and trip over a soft creature.\n";
            std::cout << "It's a Pikachu!\n";

            if (askYesNoQuestion("\nWill you interact with the Pikachu?")) {
                // Interact with Pikachu
                std::cout << "\nYou reach out to the Pikachu, offering your hand in friendship.\n";
                std::cout << "To your surprise, the Pikachu responds positively, nuzzling your hand with its soft fur.\n";
                std::cout << "It seems you've made a new friend!\n";
                std::this_thread::sleep_for(std::chrono::seconds(3));
                std::cout << "Feeling a sense of companionship, you decide to follow the Pikachu as it leads you through the grassy field.\n";
            }
            else {
                // Ignore Pikachu
                std::cout << "\nYou ignore the Pikachu, shooing it away.\n";
                std::cout << "The Pikachu looks disappointed and reluctantly leaves, disappearing into the tall grass.\n";
                std::cout << "Without any guidance, you are stuck in an everlasting maze of tall grass...\n";

                if (askYesNoQuestion("\nDo you wish to play again?")) {
                    // Play again
                    main();
                    return 0;
                }
                else {
                    // End the game
                    return 0;
                }
            }
        }
        else {
            // Battle with wild Pokemon
            system("cls");
            Pokemon wildPokemon("Wild Rattata Pokemon", "A mysterious wild Pokemon", PokeType::Normal, 20, 30);
            Ability tackle("Tackle", 15, PokeType::Normal, 10); 
            wildPokemon.learnAbility(tackle);

            player.captureWildPokemon(wildPokemon);
        }
    }
    else {
        // Stay lying down
        std::cout << "\nYou decide to stay lying down a little longer, hoping the throbbing ache in your head will subside.\n";
        if (askYesNoQuestion("Will you get up?")) {
            // Get up
            std::cout << "\nYou realize that you're lying down in the middle of nowhere, where unknown dangers may appear.\n";
            Pokemon pikachu("Pikachu", "An electric mouse Pokemon", PokeType::Electric, 30, 50);
            Ability thunderShock("Thunder Shock", 20, PokeType::Electric, 5);
            pikachu.learnAbility(thunderShock);

            std::cout << "Feeling a sense of curiosity and adventure, you decide to explore further.\n";
            std::cout << "As you walk, you notice a small creature darting through the grass nearby.\n";
            std::cout << "It's a Pikachu!\n";

            if (askYesNoQuestion("\nWill you interact with the Pikachu?")) {
                // Interact with Pikachu
                system("cls");
                std::cout << "\nYou reach out to the Pikachu, offering your hand in friendship.\n";
                std::cout << "To your surprise, the Pikachu responds positively, nuzzling your hand with its soft fur.\n";
                std::cout << "It seems you've made a new friend!\n";
                std::this_thread::sleep_for(std::chrono::seconds(3));
                std::cout << "\nFeeling a sense of companionship, you decide to follow the Pikachu as it leads you through the grassy field.\n";
            }
            else {
                // Ignore Pikachu
                system("cls");
                std::cout << "\nYou ignore the Pikachu, shooing it away.\n";
                std::cout << "The Pikachu looks disappointed and reluctantly leaves, disappearing into the tall grass.\n";
                std::cout << "You stay where you are for a while longer, contemplating your next move with an overwhelming sense of regret.\n";

                if (askYesNoQuestion("\nDo you wish to play again?")) {
                    // Play again
                    main();
                    return 0; // Ensure the previous instance of the game ends
                }
                else {
                    // End the game
                    return 0;
                }
            }
        }
        else {
            // Stay lying down stubbornly
            system("cls");
            std::cout << "\nYou stubbornly remain lying down, ignoring any thoughts of getting up.\n";
            std::this_thread::sleep_for(std::chrono::seconds(3));

            Pokemon pikachu("Pikachu", "An electric mouse Pokemon", PokeType::Electric, 30, 50);
            Ability thunderShock("ThunderShock", 20, PokeType::Electric, 5);
            pikachu.learnAbility(thunderShock);

            std::cout << "\nAfter a while of resting your head, you feel a slight nudge on your thigh.\n";
            std::cout << "Curious, you open your eyes to find a small Pikachu nudging you, its cheeks sparking with electricity.\n";
            std::cout << "It seems to want your attention. What will you do?\n";

            if (askYesNoQuestion("\nWill you interact with the Pikachu?")) {
                // Interact with Pikachu
                std::cout << "\nYou reach out to the Pikachu, offering your hand in friendship.\n";
                std::cout << "To your surprise, the Pikachu responds positively, nuzzling your hand with its soft fur.\n";
                std::cout << "It seems you've made a new friend!\n";

                std::cout << "Feeling a sense of companionship, you decide to follow the Pikachu as it leads you through the grassy field.\n";
            }
            else {
                // Ignore Pikachu
                std::cout << "\nYou ignore the Pikachu, shooing it away as you remain lying down.\n";
                std::cout << "The Pikachu looks disappointed and reluctantly leaves, disappearing into the tall grass.\n";
                std::cout << "You stay where you are for a while longer, contemplating your next move.\n";
            }
        }
    }

    std::this_thread::sleep_for(std::chrono::seconds(3));
    std::cout << "\nIn the near distance, a town appears.\n";
    std::cout << "As you near the town, you see its road filled with young faces.\n";
    std::cout << "You realize you seem to be the center of attention for a reason you cannot figure out.\n";
    std::this_thread::sleep_for(std::chrono::seconds(3));
    std::cout << "You brush it off and notice a nice-looking shop. Maybe you might find something important for your little friend.\n";
    std::this_thread::sleep_for(std::chrono::seconds(10));
    Shop pokemart;
    system("cls");
    std::cout << "Shopkeeper: Welcome to the Pokemart! Take a look at our available Pokemon and items.\n";
    pokemart.DisplayAvailablePokemon();

    int purchaseChoice;
    Pokemon purchasedPokemon;

    do {
        pokemart.DisplayAvailablePokemon();
        std::cout << "Enter the number corresponding to the Pokemon you'd like to purchase (or 0 to exit): ";
        std::cin >> purchaseChoice;

        if (purchaseChoice == 0) {
            break;
        }

        if (purchaseChoice < 1 || purchaseChoice > pokemart.availablePokemon.size()) {
            std::cout << "Invalid choice. Please choose a valid option.\n";
        }
        else {
            purchasedPokemon = pokemart.PurchasePokemon(purchaseChoice);

            std::cout << "You've purchased " << purchasedPokemon.getName() << "!\n";
            std::cout << "Shopkeeper: Thank you for your purchase! Here, take these Pokeballs to help you on your journey.\n";

            player.earnPokeballs(10);

            std::this_thread::sleep_for(std::chrono::seconds(2));
            std::cout << "Now equipped with a new Pokemon and Pokeballs, you decide to leave the town and continue your journey.\n";
        }
    } while (purchaseChoice != 0);

    player.addPokemonToTeam(purchasedPokemon);

    std::cout << "\nAs you leave the town, you find yourself on a winding path through the wilderness.\n";
    std::cout << "Suddenly, a wild Pokemon appears!\n";

    Pokemon wildPokemon("Wild Pidgey", "A wild Pidgey", PokeType::Flying, 25, 35);
    Ability peck("peck", 18, PokeType::Flying, 15);
    wildPokemon.learnAbility(peck);

    player.captureWildPokemon(wildPokemon);

    std::cout << "\nYou continue walking and encounter another Trainer!\n";

    Trainer opponent("Gary", "Oak", "Smell ya later!", 120, 120, 6);

    Pokemon opponentPokemon("Squirtle", "A cute water-type Pokemon", PokeType::Water, 35, 40);
    Ability waterGun("waterGun", 22, PokeType::Water, 12);
    opponentPokemon.learnAbility(waterGun);
    opponent.addPokemonToTeam(opponentPokemon);

    player.startBattle(opponent);

    return 0;
}
