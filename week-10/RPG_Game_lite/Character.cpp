#include "Character.h"

Character::Character(t_characterType type, string name, int health = 100, int attack = 100, int defense = 100);
{
    _type = type;
    _name = name;
    _health = health;
    _attack = attack;
    _defense = defense;
}

Character::~Character()
{
    //dtor
}

Character::attacking()
{

}
