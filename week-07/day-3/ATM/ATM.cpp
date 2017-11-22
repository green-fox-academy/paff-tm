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
    m1000 = 0;
    m2000 = 0;
    m5000 = 0;
    m10000 = 0;
    m20000 = 0;
    user = 0;
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

    pickUser();

    if (user != 0) {
        takePIN();
        cout << "The amount you want to withdraw: ";
        cin >> amount;
        if (amount % 1000 == 0) {
            if (checkATMMoney(amount)) {
                user->withdraw(pin, amount);
            } else {
                throw "ATM has no money for that amount.";
            }
        } else {
            throw "The amount must be dividable with 1000.";
        }
    }
}

void ATM::pickUser() throw (const char*)
{
    bool userIsFound = false;

    cout << "Add your username: ";
    getline(cin, name);

    int i = 0;
    while (userIsFound == false && (unsigned int)i < users.size()) {
        userIsFound = (users.at(i).getName() == name);
        ++i;
    }
    --i;

    if (userIsFound) {
        user = &(users.at(i));
    } else {
        throw "No user was found.";
    }
}

void ATM::takePIN() throw (const char*)
{
    cout << "Add your PIN: ";
    getline(cin, pin);
    user->checkPIN(pin);
}

void ATM::fillup(unsigned int _m1000, unsigned int _m2000, unsigned int _m5000, unsigned int _m10000, unsigned int _m20000)
{
    pickUser();
    takePIN();

    if (user->getUserType() == ADMIN) {
        m1000 += _m1000;
        m2000 += _m2000;
        m5000 += _m5000;
        m10000 += _m10000;
        m20000 += _m20000;

        cout << "ATM has:" << endl;
        cout << " 1000:" << m1000 << endl;
        cout << " 2000:" << m2000 << endl;
        cout << " 5000:" << m5000 << endl;
        cout << "10000:" << m10000 << endl;
        cout << "20000:" << m20000 << endl;

    } else {
        throw "You're not an admin.";
    }
}
bool ATM::checkATMMoney(unsigned int amount)
{
    bool havemoney = false;
    unsigned int i;

    i = 0;
    while (amount >= 20000 && i < m20000) {
        amount -= 20000;
        ++i;
    }
    i = 0;
    while (amount >= 10000 && i < m10000) {
        amount -= 10000;
        ++i;
    }
    i = 0;
    while (amount >= 5000 && i < m5000) {
        amount -= 5000;
        ++i;
    }
    i = 0;
    while (amount >= 2000 && i < m2000) {
        amount -= 2000;
        ++i;
    }
    i = 0;
    while (amount >= 1000 && i <m1000) {
        amount -= 1000;
        ++i;
    }

    if (amount == 0)
        havemoney = true;

    return havemoney;
}

void ATM::payATMMoney(unsigned int _m1000, unsigned int _m2000, unsigned int _m5000, unsigned int _m10000, unsigned int _m20000)
{


}

void ATM::printMenu()
{
    cout << "1     Withdraw money" << endl;
    cout << "2     Fillup ATM" << endl;
    cout << "exit  Exit the program" << endl;
}
