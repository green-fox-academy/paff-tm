#include <iostream>
//#include <string>
//#include <vector>
#include <conio.h>

#include "SerialPortWrapper.h"
#include "TempLogger.h"
#include "define.h"

using namespace std;

void printHelp();

int main()
{

    TempLogger t;
    char userInput;

    printHelp();
    do {
        try {
            userInput = _getch();
            if (userInput == SHOW) {
                printHelp();
            } else if (userInput == OPEN) {
                t.openPort();
                cout << "Port is opened" << endl;
            } else if (userInput == STARTSTOP) {
                cout << "Starting temperature logging..." << endl;
                t.startStop();
                cout << "Temperature logging has stopped." << endl;
            } else if (userInput == CLOSE) {
                t.closePort();
                cout << "Port is closed" << endl;
            } else if (userInput == LIST) {

            }
        } catch(const char *err) {
            cout << err << endl;
        } catch(...) {
            cout << "ERROR: Unexpected error." << endl;
        }
    } while (userInput != EXIT);

    return 0;
}

void printHelp()
{
    cout << endl <<
    "Temperature Logger Application       " << endl <<
    "==============================       " << endl <<
    "Commands:                            " << endl <<
    "h        Show command list           " << endl <<
    "o        Open port                   " << endl <<
    "s        Start logging / Stop logging" << endl <<
    "c        Close port                  " << endl <<
    "l        List after error handling   " << endl <<
    "e        Exit from the program       " << endl;

}
