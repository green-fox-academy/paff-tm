#include <iostream>
#include <string>
#include "User.h"

User::User()
{
    //ctor
}


User::User(string _name, string _pin, int _money)
{
    name = _name;
    pin = _pin;
    money = _money;
    user_type = CLIENT;
}


User::User(string _name, string _pin, int _money, tUser _user_type = CLIENT)
{
    name = _name;
    pin = _pin;
    money = _money;
    user_type = _user_type;
}

User::~User()
{
    //dtor
}

string User::getName()
{
    return name;
}

bool User::checkPIN(string _pin)
{
    if (_pin == pin) {
        return true;
    } else {
        return false;
    }
}

int User::getBalance(string _pin)
{
    if (checkPIN(_pin)) {
        return money;
    }
}

void User::withdraw(string _pin, unsigned int _amount)
{
    if (checkPIN(_pin)) {
        money -= _amount;
        cout << "You've got " << _amount << "Ft." << endl;
        cout << "Reamain " << money << "Ft on your balance." << endl;
    }
}
