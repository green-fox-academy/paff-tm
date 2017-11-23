#include "TempLogger.h"

#include <iostream>
#include <string>
#include <vector>
#include <conio.h>

#include "SerialPortWrapper.h"
#include "TempData.h"
#include "define.h"

using namespace std;

TempLogger::TempLogger()
{
    serial = NULL;
    connected = false;

    vector<string> ports = SerialPortWrapper::listAvailablePorts();
    cout << "Number of found serial ports: " << ports.size() << endl;
    for (unsigned int i = 0; i < ports.size(); i++) {
        cout << "\tPort name: " << ports.at(i) << endl;
    }
}

TempLogger::~TempLogger()
{
    //dtor
}

void TempLogger::openPort()
{
    if (connected) {
        throw "ERROR: Already connected.";
    } else {
        serial = new SerialPortWrapper("COM3", 115200);
        serial->openPort();
        connected = true;
    }
}

void TempLogger::closePort()
{
    if (!connected) {
        throw "ERROR: No open port.";
    } else {
        serial->closePort();
        connected = false;
    }
}

void TempLogger::startStop()
{
    string line;

    if (connected) {
        // clear port until now
        do{
            serial->readLineFromPort(&line);
        } while (line.length() > 0);

        while (1) {
            serial->readLineFromPort(&line);
            if (line.length() > 0){
                cout << line << endl;
                vTemp.push_back(*strToTempData(line));
            }
            if (_kbhit()) {
                if (_getch() == STARTSTOP) {
                    break;
                }
            }
        }
    } else {
        throw "Connect port first.";
    }
}

TempData *TempLogger::strToTempData(string line)
{
    TempData *td = new TempData(line);
    return td;
}

void TempLogger::listData()
{
    for (unsigned int i = 0; i < vTemp.size(); ++i) {
        cout << vTemp.at(i).getLine() << endl;
    }

}
