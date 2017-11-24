#include <iostream>
//#include <string>
//#include <vector>
#include <conio.h>
#include <cstdio>
#include <stdexcept>

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
            cout << "command: ";
            userInput = _getch();
            cout << userInput << endl;

            if (userInput == EXIT) {
                //do nothing
            } else if (userInput == SHOW) {
                printHelp();
            } else if (userInput == OPEN) {
                t.lookupPorts();
                cout << "Your selection: ";
                userInput = _getch();
                cout << userInput << endl;
                if (userInput != '0') {
                    t.openPort(userInput - '0' - 1);
                    cout << "Port is opened" << endl;
                }
            } else if (userInput == STARTSTOP) {
                cout << "Starting temperature logging..." << endl;
                t.startStop();
                cout << "Temperature logging has stopped." << endl;
            } else if (userInput == CLOSE) {
                t.closePort();
                cout << "Port is closed" << endl;
            } else if (userInput == LIST) {
                t.listData();
            } else if (userInput == SAVEFILE) {
                t.saveFile();
            } else if (userInput == READFILE) {
                t.openFile();
            } else {
                cout << "ERROR: Invalid command." << endl;
            }
        } catch(const char *err) {
            cout << err << endl;
        //} catch(runtime_error &err) {
        //    cout << err.what() << endl;
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
