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

void ATM::withdraw() throw (const char*)
{
    unsigned int amount;

    User *u = pickUser();
    if (u != 0) {
        cout << "The amount you want to withdraw: ";
        cin >> amount;
        if (amount % 1000 == 0) {
            u->withdraw(pin, amount);
        } else {
            throw "The amount must be dividable with 1000.";
        }
    }
}

User* ATM::pickUser() throw (const char*)
{
    bool userIsFound = false;

    getUserData();

    int i = 0;
    while (userIsFound == false && (unsigned int)i < users.size()) {
        userIsFound = (users.at(i).getName() == name);
        ++i;
    }
    --i;

    if (userIsFound) {
        return &(users.at(i));
    } else {
        throw "No user was found.";
    }
}

void ATM::getUserData()
{
    cout << "Add your username: ";
    getline(cin, name);
    cout << "Add your PIN: ";
    getline(cin, pin);
}
