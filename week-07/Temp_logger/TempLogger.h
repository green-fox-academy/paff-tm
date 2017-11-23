#ifndef TEMPLOGGER_H
#define TEMPLOGGER_H

#include <string>
#include <vector>

#include "SerialPortWrapper.h"

using namespace std;

class TempLogger
{
    public:
        TempLogger();
        ~TempLogger();
        void openPort();
        void closePort();
        void startStop();

    private:
        SerialPortWrapper *serial;
        bool connected;
};

#endif // TEMPLOGGER_H
