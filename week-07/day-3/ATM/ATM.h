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
        void withdraw();


    protected:

    private:
        vector<User> users;
        bool checkUser();
};

#endif // ATM_H
