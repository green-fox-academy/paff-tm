#ifndef USER_H
#define USER_H

#include <string>

using namespace std;

class User
{
    public:
        User();
        ~User();
        string getName();
        bool ckeckPIN(string _pin);

    protected:
        string name;
        string pin;

    private:
};

#endif // USER_H
