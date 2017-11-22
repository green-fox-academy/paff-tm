#include <iostream>
#include <string>
#include "ATM.h"
#include "User.h"

using namespace std;

int main()
{
    ATM a;

    a.addUser("Joe", "1111", 20500);
    a.addUser("Jack", "2222", 1500);
    a.addUser("Jani", "3333", 1000);
    a.addUser("Tibor", "4444", 200);
    a.addUser("Mustafa", "5555", 200500);

    try {
        a.withdraw();
    } catch(const char *err) {
        cout << "Error: " << err << endl;
    }

    return 0;
}
