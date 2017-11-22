#ifndef ATM_H
#define ATM_H
#include <vector>
#include "User.h"

using namespace std;

class ATM
{
    public:
        ATM();
        ~ATM();
        void addUser(string _name, string _pin, int _money = 0, tUser _user_type = CLIENT);
        void withdraw() throw (const char*);
        void fillup();
        void printMenu();

    protected:

    private:
        vector<User> users;
        string name;
        string pin;
        unsigned int m1000;
        unsigned int m2000;
        unsigned int m5000;
        unsigned int m10000;
        unsigned int m20000;
        User *user;

        void pickUser() throw (const char*);
        void takePIN() throw (const char*);
        bool payATMMoney(unsigned int amount);
};

#endif // ATM_H
