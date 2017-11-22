#ifndef USER_H
#define USER_H
#include <string>
#include "User.h"

using namespace std;

enum tUser {NA, ADMIN, CLIENT};

class User
{
    public:
        User();
        User(string _name, string _pin, int _money = 0, tUser _user_type = CLIENT);
        ~User();
        string getName();

        tUser getUserType(string _pin);
        int getBalance(string _pin);
        void withdraw(string _pin, unsigned int _amount) throw (const char*);

    protected:
        string name;
        string pin;
        int money;
        tUser user_type;

        bool checkPIN(string _pin);

    private:
};

#endif // USER_H
