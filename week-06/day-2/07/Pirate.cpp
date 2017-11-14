#include <iostream>
#include "Pirate.h"

using namespace std;

Pirate::Pirate() {
    drinked_rum = 0;
}

Pirate::~Pirate() {
    if (drinked_rum > 4) {
        cout << "I died drunk, yeah...! " << endl;;
    } else {
        cout << "Hey, I was still thirsty... Arrr..." << endl;
    }
}

void Pirate::drink_rum() {
    drinked_rum++;
}

void Pirate::hows_goin_mate() {
    if (drinked_rum > 4) {
        cout << "Arrrr!" << endl;
    } else {
        cout << "Nothin\'" << endl;
    }
}
