#include <stdlib.h>

#include "Character.h"

using namespace std;

Character::Character(t_characterType type, string name)
{
    _type = type;
    _name = name;
    _health = HEALTH;
    if (type == PLAYER) {
        _attack = PLAYER_ATTACK;
        _defense = PLAYER_DEFENSE;
    } else if (type == MONSTER) {
         _attack = MONSTER_ATTACK;
        _defense = MONSTER_DEFENSE;
    }
}

Character::~Character()
{
    //dtor
}

int Character::attacking(Character *attacked_character)
{
    int actual_attack = _attack * (rand() % 2 + 1);
    _health -= attacked_character->attacked(actual_attack);

    return actual_attack;
}

int Character::attacked(int attack)
{
    int att_def_diff = attack - _defense;

    if (att_def_diff > 0) {
        _health -= att_def_diff;
        return 0;
    } else {
        return -att_def_diff;
    }
}

int Character::getHealth()
{
    return _health;
}

bool Character::isAlive()
{
    return (_health > 0);
}

string Character::getName()
{
    return _name;
}
