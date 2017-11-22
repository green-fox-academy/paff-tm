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
}
