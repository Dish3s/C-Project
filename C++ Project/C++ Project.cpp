#include <iostream>

using namespace std;

void EarnMoney(int* wallet, int wage) {
    *wallet += wage;
    *wallet -= wage / 4;
}
void EarnMoneyByRef(int& wallet, int wage) {
    wallet += wage;
    wallet -= wage / 4;
}

int main()
{
    string name;
    string answer2;

    int money = 0;
    int* bankAccount = &money;

    cout << "What is your name?\n";
    cin>>name;
    cout << "\nHello " << name << ", how are you today?\n";
    cin >> answer2;
    cout << "\nHere take this.\n";

    EarnMoney(bankAccount, 10000);
    EarnMoneyByRef(money, 100);
    EarnMoneyByRef(*bankAccount, 100);
    cout << "\nThank you for the 10000, now I have " << money << "\n";

    cout << "\nThe value " << name << " is stored in" << &name << "\n";
    cout << "The value " << answer2 << " is stored in" << &answer2 << "\n";
    cout << "You can find my money at this address : " << bankAccount << "\n";
    cout << "You can find my bank at this address : " << &bankAccount << "\n";

}

