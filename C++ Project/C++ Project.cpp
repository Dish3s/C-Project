#include <iostream>
#include <chrono>
#include <thread>
#include "Pokemon.h"

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
            //YES
            std::cout << "\nAs you slowly sit up, the warmth of the sun embraces your skin, but it does little to ease the throbbing ache in your head.\n";
            std::this_thread::sleep_for(std::chrono::seconds(2));
            std::cout << "With a grimace, you glance around, trying to make sense of your surroundings.\n";
            std::cout << "The field stretches out endlessly in all directions, with no sign of civilization in sight.\n";
            std::this_thread::sleep_for(std::chrono::seconds(2));
            std::cout << "\nIn the distance, a dense forest looms, its dark silhouette contrasting sharply against the clear blue sky.\n";
            std::cout << "Anxiety creeps in, mingling with the discomfort of your pounding headache, as you contemplate what to do next.\n";

            std::cout << "\nYou decide to explore the forest. As you enter, you hear rustling in the bushes.\n";
            std::cout << "Suddenly, a wild Pokemon appears!\n";

            if (askYesNoQuestion("Do you want to run away?")) {
                //YES
                std::cout << "\nYou quickly turn around and run back into the open field, leaving the forest behind.\n";
                std::cout << "After catching your breath, you realize you have no means to defend yourself against wild Pokemon.\n";
            }
            else {
                //NO
                std::cout << "\nThe Pokemon approaches you cautiously, eyeing you with curiosity.\n";
                std::cout << "You realize you have no Pokemon of your own to battle with, and you're defenseless.\n";
                std::cout << "Feeling uneasy, you slowly back away, hoping the wild Pokemon won't attack.\n";
                std::cout << "\nUnfortunately, the Pokemon sees you as a threat and attacks!\n";
                std::cout << "You try to flee, but it's too late. You're quickly overwhelmed by its power...\n";
                std::cout << "You black out and wake up back in the field where you started, with no memory of what happened.\n";

                std::this_thread::sleep_for(std::chrono::seconds(2));
                //Bool to either continue playing or not
                bool playAgain = askYesNoQuestion("\nDo you want to play again?");
                if (playAgain) {
                    system("cls"); //This deletes the previous text
                    continue; //Continues the while loop
                }
                else {
                    exit(0); //Kills the game
                }
            }
        }
        else {
            //NO
            std::cout << "\nYou decide to stay lying down a little longer, hoping the throbbing ache in your head will subside.\n";
            if (askYesNoQuestion("Will you get up?")) {
                //YES
                std::cout << "\nYou realize that you're lying down in the middle of nowhere, where unknown dangers may appear.\n";

                std::cout << "You gather your strength and stand up. As you do, you notice something glinting in the grass nearby.\n";
                std::cout << "You walk over and discover an old, worn Pokéball. It could be useful to you somehow...\n";

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

                    // Here you would continue the story, describing the town, its features, and potential interactions with other characters.

                }
                else {
                    //NO
                    std::cout << "\nYou ignore the Pikachu, shooing it away as you remain lying down.\n";
                    std::cout << "The Pikachu looks disappointed and reluctantly leaves, disappearing into the tall grass.\n";
                    std::cout << "You stay where you are for a while longer, contemplating your next move.\n";

                    // Depending on the player's choice, you could continue the story with the player eventually deciding to explore the town or continue resting in the field.
                }
            }
            else {
                //NO
                std::cout << "\nYou stubbornly remain lying down, ignoring any thoughts of getting up.\n";
                std::this_thread::sleep_for(std::chrono::seconds(3));
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

                    break;
                    // Here you would continue the story, describing the town, its features, and potential interactions with other characters.

                }
                else {
                    //NO
                    std::cout << "\nYou ignore the Pikachu, shooing it away as you remain lying down.\n";
                    std::cout << "The Pikachu looks disappointed and reluctantly leaves, disappearing into the tall grass.\n";
                    std::cout << "You stay where you are for a while longer, contemplating your next move.\n";

                    break;
                    // Depending on the player's choice, you could continue the story with the player eventually deciding to explore the town or continue resting in the field.
                }
            }
        }
    }


    std::string name;
    std::string answer2;

    std::cout << "\nEnter your name: ";
    std::cin >> name;

    std::cout << "\nHello " << name << ", how are you today?\n";
    std::cin >> answer2;

    return 0;
}
