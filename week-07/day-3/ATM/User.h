#ifndef USER_H
#define USER_H

#include <string>

using namespace std;

enum tUser {ADMIN, CLIENT};

class User
{
    public:
        User();
        User(string _name, string _pin, int _money);
        User(string _name, string _pin, int _money, tUser _user_type);
        ~User();
        string getName();

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
