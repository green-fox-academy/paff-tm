#include <iostream>
#include <string>
#include <vector>
#include "ATM.h"
#include "User.h"

using namespace std;

ATM::ATM()
{
    name = "";
    pin = "";
}

ATM::~ATM()
{
    //dtor
}

void ATM::addUser(string _name, string _pin, int _money)
{
    User *newUser = new User(_name, _pin, _money);
    users.push_back(*newUser);
}

void ATM::withdraw()
{
    unsigned int amount;

    User *u = pickUser();
    if (u != 0) {
        cout << "The amount you want to withdraw: ";
        cin >> amount;
        u->withdraw(pin, amount);
    }
}

User* ATM::pickUser()
{
    bool userIsFound = false;

    getUserData();

    unsigned int i = 0;
    while (userIsFound == false && i < users.size()) {
        userIsFound = (users.at(i).getName() == name);
        ++i;
    }
    --i;

    if (userIsFound) {
        if (users.at(i).checkPIN(pin) == true) {
            return &(users.at(i));
        } else {
            cout << "PIN is incorrect." << endl;
            return 0;
        }
    } else {
        cout << "No user was found." << endl;
        return 0;
    }
}

void ATM::getUserData()
{
    cout << "Add your username: ";
    getline(cin, name);
    cout << "Add your PIN: ";
    getline(cin, pin);
}
