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
    std::cout << "You wake up in what seems to be a vast, grassy field, the blades swaying gently in the breeze.";

    if (askYesNoQuestion("\nDo you get up?")) {
        std::cout << "\nAs you slowly sit up, the warmth of the sun embraces your skin, but it does little to ease the throbbing ache in your head.\n";
        std::this_thread::sleep_for(std::chrono::seconds(2));
        std::cout << "With a grimace, you glance around, trying to make sense of your surroundings.\n";
        std::cout << "The field stretches out endlessly in all directions, with no sign of civilization in sight.\n";
        std::this_thread::sleep_for(std::chrono::seconds(4));
        std::cout << "In the distance, a dense forest looms, its dark silhouette contrasting sharply against the clear blue sky.\n";
        std::cout << "Anxiety creeps in, mingling with the discomfort of your pounding headache, as you contemplate what to do next.\n";
    }
    else {
        std::cout << "\nYou decide to stay lying down a little longer, hoping the throbbing ache in your head will subside.\n";
        std::this_thread::sleep_for(std::chrono::seconds(2));
        if (askYesNoQuestion("Are you sure you don't want to get up?")) {
            std::cout << "\nYou realize that you're lying down in the middle of nowhere waiting for what? Who?\n";
        }
        else {
            std::cout << "\nYou stubbornly remain lying down, ignoring any thoughts of getting up.\n";
        }
    }

    std::string name;
    std::string answer2;

    std::cout << "\nEnter your name: ";
    std::cin >> name;

    std::cout << "\nHello " << name << ", how are you today?\n";
    std::cin >> answer2;

    std::cout << "\nHere, take this.\n";

    Pokemon pikachu("Pikachu", "Electric Mouse Pokemon", "Electric", "Level 1", "Healthy");
    std::cout << "Pokemon Name: " << pikachu.GetName() << std::endl;
    std::cout << "Description: " << pikachu.GetDescription() << std::endl;
    std::cout << "Type: " << pikachu.GetType() << std::endl;
    std::cout << "Level: " << pikachu.GetLevel() << std::endl;
    std::cout << "Life: " << pikachu.GetLife() << std::endl;

    return 0;
}
