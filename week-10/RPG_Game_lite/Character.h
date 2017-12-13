#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>
#include "define.h"

using namespace std;

class Character
{
    public:
        Character(t_characterType type, string name);
        ~Character();
        int attacking(Character *attacked_character);
        int attacked(int attack);
        string getName();
        int getHealth();
        bool isAlive();
        void reset();

    protected:
        string _name;
        int _health;
        int _attack;
        int _defense;
        t_characterType _type;

    private:
};

#endif // CHARACTER_H
