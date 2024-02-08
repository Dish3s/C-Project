#include "PokeType.h"

class Abilities {
private:
    int damageAmount;
    PokeType attackType;
    int numUses;

public:
    Abilities(int damageAmount, PokeType attackType, int numUses);

    void use();
    void rest();
};
