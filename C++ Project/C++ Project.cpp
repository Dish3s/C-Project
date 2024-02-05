#include <iostream>
#include "Pokemon.h"

using namespace std;

int main()
{
    string name;
    string answer2;

    cout << "Enter your name: ";
    cin >> name;

    cout << "\nHello " << name << ", how are you today?\n";
    cin >> answer2;
    cout << "\nHere take this.\n";

    Pokemon pikachu = Pokemon ("Pikachu", "Electric Mouse Pokemon", "Electric", "Level 5", "Healthy");
    cout << "Pokemon Name: " << pikachu.GetName() << endl;
    cout << "Description: " << pikachu.GetDescription() << endl;
    cout << "Type: " << pikachu.GetType() << endl;
    cout << "Level: " << pikachu.GetLevel() << endl;
    cout << "Life: " << pikachu.GetLife() << endl;

    return 0;
}
