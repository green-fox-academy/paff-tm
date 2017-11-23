#include "TempLogger.h"

#include <iostream>
#include <string>
#include <vector>

#include "SerialPortWrapper.h"

TempLogger::TempLogger()
{
    serial = NULL;
    connected = false;

    vector<string> ports = SerialPortWrapper::listAvailablePorts();
    cout << "Number of found serial ports: " << ports.size() << endl;
    for (unsigned int i = 0; i < ports.size(); i++) {
        cout << "\tPort name: " << ports.at(i) << endl;
    }

    serial = new SerialPortWrapper("COM3", 115200);
}

TempLogger::~TempLogger()
{
    //dtor
}

void TempLogger::openPort()
{
    serial->openPort();
    connected = true;
}

void TempLogger::closePort()
{
    serial->closePort();
    connected = false;
}

void TempLogger::startStop()
{
    string line;
    if (connected) {
        while(1){
            serial->readLineFromPort(&line);
            if (line.length() > 0){
                cout << line << endl;
            }
        }
    }
}
