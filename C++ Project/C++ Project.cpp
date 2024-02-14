#include <iostream>
#include <chrono>
#include <thread>
#include "Pokemon.h"
#include "Trainer.h"
#include "Abilities.h"
#include "PokeType.h"

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
    while (true) {
        std::cout << "You wake up in what seems to be a vast, grassy field, the blades swaying gently in the breeze.";

        if (askYesNoQuestion("\nDo you get up?")) {
            Trainer player("Ash", "Ketchum", "I choose you!", 100, 100, 5);

            //YES
            std::cout << "\nIn the distance you spot a dense forest.\n";
            std::cout << "\nYou decide to explore the forest. As you enter, you hear rustling in the bushes.\n";
            std::cout << "Suddenly, a wild Pokemon appears!\n";

            if (askYesNoQuestion("Do you want to run away?")) {
                //YES
                std::cout << "\nYou quickly turn around and run back into the open field, leaving the forest behind.\n";
                std::cout << "After catching your breath, you realize you have no means to defend yourself against wild Pokemon.\n";
            }
            else {
                //NO
                Pokemon wildPokemon("Wild Pokemon", "A mysterious wild Pokemon", PokeType::Normal, 20, 30);
                Abilities tackle(15, PokeType::Normal, 10);
                wildPokemon.LearnAbility(tackle, 0);

                player.BattleWildPokemon(wildPokemon);
                
            }
        }
        else {
            //NO
            std::cout << "\nYou decide to stay lying down a little longer, hoping the throbbing ache in your head will subside.\n";
            if (askYesNoQuestion("Will you get up?")) {
                //YES
                std::cout << "\nYou realize that you're lying down in the middle of nowhere, where unknown dangers may appear.\n";
                Pokemon pikachu("Pikachu", "An electric mouse Pokemon", PokeType::Electric, 30, 50);
                Abilities thunderShock(20, PokeType::Electric, 5);
                pikachu.LearnAbility(thunderShock, 0);

                std::cout << "Feeling a sense of curiosity and adventure, you decide to explore further.\n";
                std::cout << "As you walk, you notice a small creature darting through the grass nearby.\n";
                std::cout << "It's a Pikachu!\n";

                if (askYesNoQuestion("Will you interact with the Pikachu?")) {
                    //YES
                    std::cout << "\nYou reach out to the Pikachu, offering your hand in friendship.\n";
                    std::cout << "To your surprise, the Pikachu responds positively, nuzzling your hand with its soft fur.\n";
                    std::cout << "It seems you've made a new friend!\n";

                    std::cout << "Feeling a sense of companionship, you decide to follow the Pikachu as it leads you through the grassy field.\n";
                    std::cout << "After a while, you arrive at the outskirts of a bustling town, its buildings bustling with activity.\n";
                    std::cout << "This must be where trainers and Pokemon congregate!\n";
                    //
                }
                else {
                    //NO
                    std::cout << "\nYou ignore the Pikachu, shooing it away as you remain lying down.\n";
                    std::cout << "The Pikachu looks disappointed and reluctantly leaves, disappearing into the tall grass.\n";
                    std::cout << "You stay where you are for a while longer, contemplating your next move.\n";
                    //
                }
            }
            else {
                //NO
                std::cout << "\nYou stubbornly remain lying down, ignoring any thoughts of getting up.\n";
                std::this_thread::sleep_for(std::chrono::seconds(3));

                Pokemon pikachu("Pikachu", "An electric mouse Pokemon", PokeType::Electric, 30, 50);
                Abilities thunderShock(20, PokeType::Electric, 5);
                pikachu.LearnAbility(thunderShock, 0);

                std::cout << "After a while of resting your head, you feel a slight nudge on your thigh.\n";
                std::cout << "Curious, you open your eyes to find a small Pikachu nudging you, its cheeks sparking with electricity.\n";
                std::cout << "It seems to want your attention. What will you do?\n";

                if (askYesNoQuestion("Will you interact with the Pikachu?")) {
                    //YES
                    std::cout << "\nYou reach out to the Pikachu, offering your hand in friendship.\n";
                    std::cout << "To your surprise, the Pikachu responds positively, nuzzling your hand with its soft fur.\n";
                    std::cout << "It seems you've made a new friend!\n";

                    std::cout << "Feeling a sense of companionship, you decide to follow the Pikachu as it leads you through the grassy field.\n";
                    std::cout << "After a while, you arrive at the outskirts of a bustling town, its buildings bustling with activity.\n";
                    std::cout << "This must be where trainers and Pokemon congregate!\n";
                    
                }
                else {
                    //NO
                    std::cout << "\nYou ignore the Pikachu, shooing it away as you remain lying down.\n";
                    std::cout << "The Pikachu looks disappointed and reluctantly leaves, disappearing into the tall grass.\n";
                    std::cout << "You stay where you are for a while longer, contemplating your next move.\n";
                   
                }
            }
        }
    }

    return 0;
}
