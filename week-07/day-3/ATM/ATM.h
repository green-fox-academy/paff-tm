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
        void addUser(string _name, string _pin, int _money);
        void withdraw() throw (const char*);


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

        User* pickUser() throw (const char*);
        void getUserData();
};

#endif // ATM_H
