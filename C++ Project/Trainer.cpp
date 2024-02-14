#include <iostream>
#include "PokeType.h"
#include "Abilities.h"
#include "Pokemon.h"
#include "Trainer.h"

Trainer::Trainer(std::string first, std::string last, std::string phrase, int startingMoney, int startingLife, int startingPokeballs)
    : firstName(first), lastName(last), catchphrase(phrase), money(startingMoney), lifePoints(startingLife), pokeballs(startingPokeballs) {}

void Trainer::introduce() const {
    std::cout << "Hello, I'm Trainer " << firstName << " " << lastName << ". " << catchphrase << "!\n";
}

void Trainer::startBattle(Trainer& opponent) {
    std::cout << firstName << " challenges Trainer " << opponent.firstName << " to a Pokemon battle!\n";

    while (true) {
        std::cout << "\n------------------------\n";
        std::cout << firstName << "'s Team:\n";
        for (size_t i = 0; i < team.size(); ++i) {
            std::cout << i + 1 << ". " << team[i].getName() << " (Life: " << team[i].getLife() << ")\n";
        }

        std::cout << "\n" << opponent.firstName << "'s Team:\n";
        const std::vector<Pokemon>& opponentTeam = opponent.getTeam();
        for (size_t i = 0; i < opponentTeam.size(); ++i) {
            std::cout << i + 1 << ". " << opponentTeam[i].getName() << " (Life: " << opponentTeam[i].getLife() << ")\n";
        }
        std::cout << "------------------------\n";

        int playerChoice;
        std::cout << "Choose a Pokemon to send into battle (1-" << team.size() << "): ";
        std::cin >> playerChoice;

        if (playerChoice >= 1 && playerChoice <= team.size()) {
            Pokemon& playerPokemon = team[playerChoice - 1];
            std::cout << firstName << " sends out " << playerPokemon.getName() << "!\n";

            int opponentChoice = rand() % opponentTeam.size();
            Pokemon& opponentPokemon = opponentTeam[opponentChoice];
            std::cout << opponent.firstName << " sends out " << opponentPokemon.getName() << "!\n";

            playerPokemon.useAbility(0); 
            opponentPokemon.useAbility(0);

            std::cout << "------------------------\n";
            std::cout << playerPokemon.getName() << "'s Life: " << playerPokemon.getLife() << "\n";
            std::cout << opponentPokemon.getName() << "'s Life: " << opponentPokemon.getLife() << "\n";
            std::cout << "------------------------\n";


            if (playerPokemon.getLife() <= 0) {
                std::cout << firstName << "'s " << playerPokemon.getName() << " fainted!\n";
                break;
            }

            if (opponentPokemon.getLife() <= 0) {
                std::cout << opponent.firstName << "'s " << opponentPokemon.getName() << " fainted!\n";
                break;
            }

            std::cout << "Press Enter to continue...";
            std::cin.ignore();
            std::cin.get();
        }
        else {
            std::cout << "Invalid choice. Please choose a Pokemon in the valid range.\n";
        }
    }

    std::cout << "The battle between " << firstName << " and " << opponent.firstName << " has ended!\n";
}

void Trainer::captureWildPokemon(const Pokemon& wildPokemon) {
    std::cout << firstName << " encounters a wild " << wildPokemon.getName() << "!\n";

    while (true) {
        std::cout << "\n------------------------\n";
        std::cout << firstName << "'s Team:\n";
        for (size_t i = 0; i < team.size(); ++i) {
            std::cout << i + 1 << ". " << team[i].getName() << " (Life: " << team[i].getLife() << ")\n";
        }

        std::cout << "\nWild " << wildPokemon.getName() << " (Life: " << wildPokemon.getLife() << ")\n";
        std::cout << "------------------------\n";

        int playerChoice;
        std::cout << "Choose a Pokemon to send into battle (1-" << team.size() << "): ";
        std::cin >> playerChoice;

        if (playerChoice >= 1 && playerChoice <= team.size()) {
            Pokemon& playerPokemon = team[playerChoice - 1];
            std::cout << firstName << " sends out " << playerPokemon.getName() << "!\n";

            playerPokemon.useAbility(0);
            wildPokemon.useAbility(0);

            // Display the result of the round
            std::cout << "------------------------\n";
            std::cout << playerPokemon.getName() << "'s Life: " << playerPokemon.getLife() << "\n";
            std::cout << "Wild " << wildPokemon.getName() << "'s Life: " << wildPokemon.getLife() << "\n";
            std::cout << "------------------------\n";

            // Check if any Pokemon fainted
            if (playerPokemon.getLife() <= 0) {
                std::cout << firstName << "'s " << playerPokemon.getName() << " fainted!\n";
                break;
            }

            if (wildPokemon.getLife() <= 0) {
                std::cout << "Wild " << wildPokemon.getName() << " fainted!\n";
                break;
            }

            std::cout << "Press Enter to continue...";
            std::cin.ignore();
            std::cin.get();
        }
        else {
            std::cout << "Invalid choice. Please choose a Pokemon in the valid range.\n";
        }
    }

    std::cout << "The battle with the wild " << wildPokemon.getName() << " has ended!\n";
}

void Trainer::sendPokemon(int index) {
    if (index >= 0 && index < team.size()) {
        std::cout << firstName << " sends out " << team[index].getName() << "!\n";
    }
    else {
        std::cout << "Invalid Pokemon index.\n";
    }
}

void Trainer::useAbility(const Pokemon& attacker, const Pokemon& target, const std::string& ability) {
    std::cout << attacker.getName() << " uses " << ability << " on " << target.getName() << "!\n";
}

void Trainer::earnMoney(int amount) {
    money += amount;
    std::cout << firstName << " earned " << amount << " money!\n";
}

void Trainer::earnPokeballs(int amount) {
    pokeballs += amount;
    std::cout << firstName << " obtained " << amount << " new Pokeballs!\n";
}

std::string Trainer::getFirstName() const {
    return firstName;
}

const std::vector<Pokemon>& Trainer::getTeam() const {
    return team;
}

void Trainer::restTeam() {
    for (auto& pokemon : team) {
        pokemon.restAbilities();
    }
}

void Trainer::addPokemonToTeam(const Pokemon& newPokemon) {
    if (team.size() < 6) {
        team.push_back(newPokemon);
        std::cout << firstName << " added " << newPokemon.getName() << " to the team!\n";
    }
    else {
        std::cout << firstName << " cannot have more than 6 Pokemon in the team.\n";
    }
}
