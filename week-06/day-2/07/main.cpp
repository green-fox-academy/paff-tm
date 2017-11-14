#include <iostream>
#include <string>

#include "Pirate.h"

using namespace std;

int main()
{
    // create a pirate class
    // it should have 2 methods
    // drink_rum()
    // hows_goin_mate()
    // if the drink_rum was called at least 5 times:
    // hows_goin_mate should return "Arrrr!"
    // "Nothin'" otherwise

    Pirate pirate;

    for (int i = 0; i < 6; ++i) {
        pirate.drink_rum();
        cout << i + 1 << ". shot: ";
        pirate.hows_goin_mate();
    }

    return 0;
}
