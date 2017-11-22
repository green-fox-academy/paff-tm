#include "User.h"

User::User()
{
    //ctor
}

User::~User()
{
    //dtor
}

string User::getName()
{
    return name;
}

bool User::ckeckPIN(string _pin)
{
    if (_pin == pin) {
        return true;
    } else {
        return false;
    }
}
