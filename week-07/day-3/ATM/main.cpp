/*  K�rd�sek:
 *  hibakezel�s? Ha van throw akkor kell-e ut�n b�rmi felt�telt �rni? pl: ATM::withdraw()-ban?
 *  Kell-e a method m�g� throw-t �rni?? An�lk�l is m�k�dik. pl: ATM::fillup()
 *  TODO: TakePin-t integr�lni pickUser-be
*/


#include <iostream>
#include <string>
#include "ATM.h"
#include "User.h"

using namespace std;

int main()
{
    ATM a;
    string input = "";

    a.addUser("Joe", "1111", 20500, ADMIN);
    a.addUser("Jack", "2222", 1500);
    a.addUser("Jani", "3333", 1000);
    a.addUser("Tibor", "4444", 200);
    a.addUser("Mustafa", "5555", 200500);

    do {
        a.printMenu();
        try {
            getline(cin, input);
            if (input == "1") {
                a.withdraw();
            } else if (input == "2") {
                a.fillup();
            } else {

            }
        } catch(const char *err) {
            cout << "Error: " << err << endl;
        }
    } while (input != "exit");

    return 0;
}
