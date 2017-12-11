#include <iostream>
#include <fstream>
#include <vector>
#include <conio.h>

#include "RPM_logger.h"
#include "SerialPortWrapper.h"

RPM_logger::RPM_logger()
{
    serial = NULL;
    connected = false;

    lookupPorts();
}

RPM_logger::~RPM_logger()
{
    saveFile();
}

void RPM_logger::openPort(int _port)
{
    if (connected) {
        throw "ERROR: Already connected to a port.";
    } else {
        serial = new SerialPortWrapper(ports.at(_port), 115200);
        serial->openPort();
        connected = true;
    }
}

void RPM_logger::closePort()
{
    if (!connected) {
        throw "ERROR: No open port.";
    } else {
        serial->closePort();
        connected = false;
    }
}

void RPM_logger::lookupPorts()
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

void RPM_logger::saveFile()
{
    ofstream ofile;
    ofile.open("RPMlog.csv");
    for (unsigned int i = 0; i < data.size(); ++i) {
        ofile << data.at(i) << endl;
    }
    ofile.close();
}

void RPM_logger::startStop()
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
                /*
                td = strToTempData(line);
                if (td != NULL) {
                    data.push_back(*td);
                }
                */
                data.push_back(line);
            }
            if (_kbhit()) {
                /*
                if (_getch() == STARTSTOP) {
                    break;
                }
                */
                break;
            }
        }
    } else {
        throw "Can't start logging. Open a port first.";
    }
}
