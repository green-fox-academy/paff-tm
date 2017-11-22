#include <iostream>
#include <string>
#include <vector>
#include "ATM.h"
#include "User.h"

using namespace std;

ATM::ATM()
{
    //ctor
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

bool ATM::checkUser()
{
    bool userIsFound = false;

    string name;
    string pin;
    cout << "Add your username: " << endl;
    getline(cin, name);
    cout << "Add your PIN: " << endl;
    getline(cin, pin);

    unsigned int i = 0;
    while (userIsFound == false && i < users.size()) {
        userIsFound = (users.at(i).getName() == name);
        ++i;
    }

    if (userIsFound) {
        if (users.at(i).checkPIN(pin) == true) {
            return true;
        } else {
            cout << "PIN is incorrect." << endl;
            return false;
        }
    } else {
        cout << "No user was found." << endl;
        return false;
    }
}
