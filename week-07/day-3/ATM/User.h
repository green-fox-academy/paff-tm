#ifndef USER_H
#define USER_H

#include <string>

using namespace std;

class User
{
    public:
        User();
        ~User();
        string getUsername();
        bool ckeckPIN(int _pin);

    protected:
        string name;
        int pin;

    private:
};

#endif // USER_H
