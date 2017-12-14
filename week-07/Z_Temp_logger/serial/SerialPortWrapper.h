#ifndef SERIALPORTWRAPPER_H_
#define SERIALPORTWRAPPER_H_

#include <string>
#include <vector>

using namespace std;

/**
 * Helper class to connect the PC to serial port.
 */
class SerialPortWrapper {
    public:
        /**
         * This static method helps to list the available serial ports' human readable names.
         * Helpful in case you don't have an idea what is the name of your port you'd like to
         * connect.
         * 
         * returns a vector<string> with the port names
         * throws const char* exception if the query for the available names was unsuccessful
         */
        static vector<string> listAvailablePorts();

        /**
         * Expects the string name of the serial port and the baud rate to use for communication
         * (use 115200 for now).
         * 
         * throws const char* exception if the query for the available names was unsuccessful
         * or there's no port with the specified name.
         */
        SerialPortWrapper(string portName, int baudRate);

        /**
         * Opens the port with the parameters specified in the constructor.
         * 
         * throws const char* exception if the operation was not successful.
         */
        void openPort();

        /**
         * Reads a line from the input into the specified string. If there's no data on the input,
         * the method returns and the string will be empty.
         */
        void readLineFromPort(string *line);

        /**
         * Closes the opened port.
         */
        void closePort();

    private:
        string _portName;
        int _baudRate;
        int _portIdx;
};

#endif // SERIALPORTWRAPPER_H_