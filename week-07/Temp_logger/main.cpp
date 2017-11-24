/*             Temperature Logger
 * ============================================
 * Greenfox Academy Pallida Cohort Static Class
 *               András Pásztor
 */

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

            switch (userInput) {
            case EXIT:
            case NULLMENU:
                //do nothing
                break;

            case SHOW:
                printHelp();
                break;

            case OPEN:
                t.lookupPorts();
                cout << "Your selection: ";
                userInput = _getch();
                cout << userInput << endl;
                if (userInput != '0') {
                    t.openPort(userInput - '0' - 1);
                    cout << "Port is opened." << endl;
                }
                userInput = NULLMENU;
                break;

            case STARTSTOP:
                cout << "Starting temperature logging..." << endl;
                t.startStop();
                cout << "Temperature logging has stopped." << endl;
                break;

            case CLOSE:
                t.closePort();
                cout << "Port is closed" << endl;
                break;

            case LIST:
                t.listData();
                break;

            case SAVEFILE:
                t.saveFile();
                break;

            case READFILE:
                t.openFile();
                break;

            case AVERAGE:
                cout << "1. average on a day" << endl;
                cout << "2. average of last days" << endl;
                cout << "3. average of day-to-day" << endl;
                cout << "Your selection: ";
                userInput = _getch();
                cout << userInput << endl;
                if (userInput == '1') {
                    //t.averageTemp();
                }
                if (userInput == '2') {

                    t.averageTemp();
                }
                if (userInput == '3') {
                    //t.averageTemp();
                }
                userInput = NULLMENU;
                break;

            default:
                cout << "ERROR: Invalid command." << endl;
                break;
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
    "f        Store data in a file        " << endl <<
    "r        Read data from a file       " << endl <<
    "a        Avarage temperature by days " << endl <<
    "e        Exit from the program       " << endl;

}
