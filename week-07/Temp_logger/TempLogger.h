#ifndef TEMPLOGGER_H
#define TEMPLOGGER_H

#include <string>
#include <vector>

#include "SerialPortWrapper.h"
#include "TempData.h"

using namespace std;

class TempLogger
{
    public:
        TempLogger();
        ~TempLogger();
        void openPort(int _port);
        void closePort();
        void startStop();
        void listData();
        void lookupPorts();

    private:
        SerialPortWrapper *serial;
        bool connected;
        vector <TempData> vTemp;
        vector<string> ports;

        TempData *strToTempData(string _line);
        bool tempToken(char *_str, char *_tokchr, int *_result);
        bool isValidTempData(tm *_time, int _temperature);
        bool isBetween(int _x, int _min, int _max);
};

#endif // TEMPLOGGER_H
