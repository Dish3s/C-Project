#include <string>
#include "Pokemon.h"

class Trainer {
private:
    std::string firstName;
    std::string lastName;
    std::string catchphrase;
    int money;
    int lifePoints;
    Pokemon pokemonTeam[6];
    int numPokeballs;

public:
    // Constructor
    Trainer(std::string firstName, std::string lastName, std::string catchphrase, int money, int lifePoints, int numPokeballs);

    // Methods
    void introduce();
    void challenge(Trainer& opponent);
    void capturePokemon(Pokemon wildPokemon);
    void sendPokemon(int index);
    void changePokemon(int index, Pokemon newPokemon);
    void useAbility(int index, Pokemon& target);
    void earnMoney(int amount);
    void earnPokeballs(int amount);
};

