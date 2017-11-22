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
