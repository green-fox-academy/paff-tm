#ifndef USER_H
#define USER_H

#include <string>

using namespace std;

class User
{
    public:
        User();
        User(string _name, string _pin, int money);
        ~User();
        string getName();
        bool checkPIN(string _pin);

    protected:
        string name;
        string pin;
        int money;

    private:
};

#endif // USER_H
