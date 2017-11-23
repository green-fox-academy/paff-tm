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

    lookupPorts();
}

TempLogger::~TempLogger()
{
    //dtor
}

void TempLogger::openPort(int _port)
{
    if (connected) {
        throw "ERROR: Already connected to a port.";
    } else {
        serial = new SerialPortWrapper(ports.at(_port), 115200);
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
        throw "Can't start logging. Open a port first.";
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

void TempLogger::lookupPorts()
{
    if (connected) {
        throw "ERROR: Already connected to a port.";
    } else {
        ports = SerialPortWrapper::listAvailablePorts();
        cout << "Number of found serial ports: " << ports.size() << endl;
        for (unsigned int i = 0; i < ports.size(); i++) {
            cout << i + 1 << ".\t Port name: " << ports.at(i) << endl;
        }
    }
}
