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
        void fillup(unsigned int _m1000, unsigned int _m2000, unsigned int _m5000, unsigned int _m10000, unsigned int _m20000);
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
        bool checkATMMoney(unsigned int amount);
        void payATMMoney(unsigned int _m1000, unsigned int _m2000, unsigned int _m5000, unsigned int _m10000, unsigned int _m20000);
};

#endif // ATM_H
