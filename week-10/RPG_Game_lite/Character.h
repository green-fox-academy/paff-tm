#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>
#include "define.h"

using namespace std;

class Character
{
    public:
        Character(t_characterType type, string name, int health, int attack, int defense);
        ~Character();
        void attacking();

    protected:
        string _name;
        int _health;
        int _attack;
        int _defense;
        t_characterType _type;

    private:
};

#endif // CHARACTER_H
