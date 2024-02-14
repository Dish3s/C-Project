#include <iostream>
#include <chrono>
#include <thread>
#include "Pokemon.h"
#include "Trainer.h"
#include "Abilities.h"
#include "PokeType.h"
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
    while (true) {
        system("cls");
        std::cout << "You wake up in what seems to be a vast, grassy field, the blades swaying gently in the breeze.";

        if (askYesNoQuestion("\nDo you get up?")) {
            Trainer player("Ash", "Ketchum", "I choose you!", 100, 100, 5);

            //YES
            std::cout << "\nIn the distance you spot a dense forest.\n";
            std::cout << "\nYou decide to explore the forest. As you enter, you hear rustling in the bushes.\n";
            std::cout << "Suddenly, a wild Pokemon appears!\n";

            if (askYesNoQuestion("Do you want to run away?")) {
                //YES
                system("cls");
                std::cout << "\nYou quickly turn around and run back into the open field, leaving the forest behind.\n";
                std::cout << "After catching your breath, you realize you have no means to defend yourself against wild Pokemon.\n";
                std::cout << "\nSo you look around...\n";
                std::this_thread::sleep_for(std::chrono::seconds(2));
                std::cout << "You've been walking for a while through tall grass and trip over a soft creature.\n";
                std::cout << "It's a Pikachu!\n";

                if (askYesNoQuestion("\nWill you interact with the Pikachu?")) {
                    //YES
                    std::cout << "\nYou reach out to the Pikachu, offering your hand in friendship.\n";
                    std::cout << "To your surprise, the Pikachu responds positively, nuzzling your hand with its soft fur.\n";
                    std::cout << "It seems you've made a new friend!\n";
                    std::this_thread::sleep_for(std::chrono::seconds(3));
                    std::cout << "Feeling a sense of companionship, you decide to follow the Pikachu as it leads you through the grassy field.\n";
                    break;
                }
                else {
                    //NO
                    std::cout << "\nYou ignore the Pikachu, shooing it away.\n";
                    std::cout << "The Pikachu looks disappointed and reluctantly leaves, disappearing into the tall grass.\n";
                    std::cout << "Without any guidance you are stuck in an everlasting maze of tall grass...\n";

                    if (askYesNoQuestion("\nDo you wish to play again?")) {
                        continue;
                    }
                    else {
                        return 0;
                    }
                }
            }
            else {
                //NO
                system("cls");
                Pokemon wildPokemon("Wild Rattata Pokemon", "A mysterious wild Pokemon", PokeType::Normal, 20, 30);
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

                if (askYesNoQuestion("\nWill you interact with the Pikachu?")) {
                    //YES
                    system("cls");
                    std::cout << "\nYou reach out to the Pikachu, offering your hand in friendship.\n";
                    std::cout << "To your surprise, the Pikachu responds positively, nuzzling your hand with its soft fur.\n";
                    std::cout << "It seems you've made a new friend!\n";
                    std::this_thread::sleep_for(std::chrono::seconds(3));
                    std::cout << "\nFeeling a sense of companionship, you decide to follow the Pikachu as it leads you through the grassy field.\n";
                    break;
                }
                else {
                    //NO
                    system("cls");
                    std::cout << "\nYou ignore the Pikachu, shooing it away.\n";
                    std::cout << "The Pikachu looks disappointed and reluctantly leaves, disappearing into the tall grass.\n";
                    std::cout << "You stay where you are for a while longer, contemplating your next move with an overwhelming sense of regret.\n";

                    if (askYesNoQuestion("\nDo you wish to play again?")) {
                        continue;
                    }
                    else {
                        return 0;
                    }
                }
            }
            else {
                //NO
                system("cls");
                std::cout << "\nYou stubbornly remain lying down, ignoring any thoughts of getting up.\n";
                std::this_thread::sleep_for(std::chrono::seconds(3));

                Pokemon pikachu("Pikachu", "An electric mouse Pokemon", PokeType::Electric, 30, 50);
                Abilities thunderShock(20, PokeType::Electric, 5);
                pikachu.LearnAbility(thunderShock, 0);

                std::cout << "\nAfter a while of resting your head, you feel a slight nudge on your thigh.\n";
                std::cout << "Curious, you open your eyes to find a small Pikachu nudging you, its cheeks sparking with electricity.\n";
                std::cout << "It seems to want your attention. What will you do?\n";

                if (askYesNoQuestion("\nWill you interact with the Pikachu?")) {
                    //YES
                    std::cout << "\nYou reach out to the Pikachu, offering your hand in friendship.\n";
                    std::cout << "To your surprise, the Pikachu responds positively, nuzzling your hand with its soft fur.\n";
                    std::cout << "It seems you've made a new friend!\n";

                    std::cout << "Feeling a sense of companionship, you decide to follow the Pikachu as it leads you through the grassy field.\n";
                    break;
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

    std::this_thread::sleep_for(std::chrono::seconds(3));
    std::cout << "\nIn the near distance, a town appears.\n";
    std::cout << "As you near the town you see its road filled with young faces.\n";
    std::cout << "You realize you seem to be the center of attention for a reason you cannot figure out.\n";
    std::this_thread::sleep_for(std::chrono::seconds(3));
    std::cout << "You brush it off and notice a nice looking shop. Maybe you might find something important for you little friend.\n";
    

    return 0;
}
