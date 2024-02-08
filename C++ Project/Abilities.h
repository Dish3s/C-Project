#include "PokeType.h"

class Ability {
private:
    int damageAmount;
    PokeType attackType;
    int numUses;

public:
    Ability(int damageAmount, PokeType attackType, int numUses);

    void use();
    void rest();
};
