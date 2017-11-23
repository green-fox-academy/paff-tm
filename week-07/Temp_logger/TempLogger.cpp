#include "TempLogger.h"

#include <iostream>
#include <string>
#include <vector>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

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
        TempData *td;

        // clear port until now
        do{
            serial->readLineFromPort(&line);
        } while (line.length() > 0);

        while (1) {
            serial->readLineFromPort(&line);
            if (line.length() > 0){
                cout << line << endl;
                td = strToTempData(line);
                if (td != NULL) {
                    vTemp.push_back(*td);
                }
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

TempData *TempLogger::strToTempData(string _line)
{
    char *str = strdup(_line.c_str());
    tm time = {0};
    int temperature;

    tempToken(str, (char *)".", &(time.tm_year));
    tempToken(NULL, (char *)".", &(time.tm_mon));
    tempToken(NULL, (char *)" ", &(time.tm_mday));

    tempToken(NULL, (char *)":", &(time.tm_hour));
    tempToken(NULL, (char *)":", &(time.tm_min));
    tempToken(NULL, (char *)" ", &(time.tm_sec));

    tempToken(NULL, (char *)" ", &temperature);

    if (!isValidTempData(&time, temperature)) {
        return NULL;
    }

    TempData *td = new TempData(time, temperature);
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

bool TempLogger::tempToken(char *_str, char *_tokchr, int *_result)
{
    char temp_str[80];
    char *p_str = strtok(_str, _tokchr);

    if (p_str == NULL){
        return false;
    }

    strcpy(temp_str, p_str);
    *_result = atoi(temp_str);

    return true;
}

bool TempLogger::isValidTempData(tm *_time, int _temperature)
{
    //check time
    if ((_time->tm_year > 1950 &&
        isBetween(_time->tm_mon, 1, 12) &&
        isBetween(_time->tm_mday, 1, 31) &&
        isBetween(_time->tm_hour, 0, 23) &&
        isBetween(_time->tm_min, 0, 59) &&
        isBetween(_time->tm_sec, 0, 59))
         == false) {
        return false;
    }

    return true;
}

bool TempLogger::isBetween(int _x, int _min, int _max)
{
    if (_x >= _min && _x <= _max) {
        return true;
    } else {
        return false;
    }
}
