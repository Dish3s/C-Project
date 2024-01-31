#include <iostream>

using namespace std;

int main()
{
    cout << "What is your name?\n";
    string answer1;
    string answer2;
    cin>>answer1;
    cout << "\nHello " << answer1 << ", how are you today?\n";
    cin >> answer2;
    cout << "\nThe value " << answer1 << " is stored in" << &answer1 << "\n";
    cout << "\nThe value " << answer2 << " is stored in" << &answer2 << "\n";
}

