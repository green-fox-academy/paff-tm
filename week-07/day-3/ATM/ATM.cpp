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

void ATM::addUser(string _name, string _pin, int _money, tUser _user_type)
{
    User *newUser = new User(_name, _pin, _money, _user_type);
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

void ATM::fillup(unsigned int _m1000, unsigned int _m2000, unsigned int _m5000, unsigned int _m10000, unsigned int _m20000)
{
    User *u = pickUser();
    if (u->getUserType(pin) == ADMIN) {
        m1000 += _m1000;
        m2000 += _m2000;
        m5000 += _m5000;
        m10000 += _m10000;
        m20000 += _m20000;
    }
}
