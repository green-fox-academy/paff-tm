#include "User.h"

User::User()
{
    //ctor
}

User::~User()
{
    //dtor
}

string User::getUsername()
{
    return name;
}

bool User::ckeckPIN(int _pin)
{
    if (_pin == pin) {
        return true;
    } else {
        return false;
    }
}
