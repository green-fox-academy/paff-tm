#ifndef RPM_LOGGER_H
#define RPM_LOGGER_H

#include "SerialPortWrapper.h"

class RPM_logger
{
    public:
        RPM_logger();
        ~RPM_logger();
        void openPort(int _port);
        void closePort();
        void lookupPorts();
        void saveFile();
        void startStop();

    protected:

    private:
        bool connected;
        SerialPortWrapper *serial;
        vector<string> ports;
        vector<string> data;
};

#endif // RPM_LOGGER_H
