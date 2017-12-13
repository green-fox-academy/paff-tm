#include <iostream>
#include <string>
#include <time.h>
#include <stdlib.h>
#include <vector>

#include "Character.h"

using namespace std;

void printResult(int i);
void printRoundResult(int i, Character *attacker, Character *defender);
void switchPlayers(Character **attacker, Character **defender);

Character *player = new Character(PLAYER, "Lali");
Character *monster = new Character(MONSTER, "Gizmo");

int main() {
    //RPG Game lite
    //Create a Character class with the following preferences:
    //name
    //character type (player/monster)
    //health point value
    //attack value
    //defense value
    //attacking method which takes a character class and decreases its health
    //value with (current character class attack - input character class defense),
    //if the output is minus, then our health is decreased
    //set the attacking method to have 50% chanse to count our attack value twice,
    //(2xcurrent attack - input defense) before calculating the final health points.

    //create 2 instances of the character class and fill their base stats from their constructor
    //make them attack each other with the attack method from the character class
    //after each round print both the attacker, and the attacked character health
    //make them fight each other until one of them has a health point lower or equal 0
    //print the winner and offer a new game

    //dont forget to use private variables, and get/set methods, and also place out_of_range
    //character class into a seperate file

    srand(time(0));

    int i = 0;
    string input;
    Character *attacker = player;
    Character *defender = monster;

    do {
        ++i;
        attacker->attacking(defender);
        printRoundResult(i, attacker, defender);
        cin >> input;
        switchPlayers(&attacker, &defender);
    } while(input != CMD_EXIT && player->isAlive() && monster->isAlive());

    printResult(i);

    delete player;
    delete monster;

    return 0;
}

void printResult(int i)
{
    cout << "After " << i << " rounds the winner is: " << endl;
    if (player->isAlive())
        cout << "\t" << player->getName() << endl;
    else
        cout << "\t" << monster->getName() << endl;
}

void printRoundResult(int i, Character *attacker, Character *defender)
{
    cout << i << ". round:" << endl;
    cout << "\t" << attacker->getName() << " has attacked " << defender->getName() << "." << endl;
    cout << "\t" << player->getName() << "'s health is:\t" << player->getHealth() << "\%" << endl;
    cout << "\t" << monster->getName() << "'s health is:\t" << monster->getHealth() << "\%" << endl;
}

void switchPlayers(Character **attacker, Character **defender)
{
    Character *temp;

    temp = *attacker;
    *attacker = *defender;
    *defender = temp;
}
