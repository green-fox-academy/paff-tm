#include <iostream>
#include "SerialPortWrapper.h"

#define PORT    0

using namespace std;

void openPort();
void closePort();

SerialPortWrapper *serial;
vector<string> ports;

int main()
{
    openPort();

    cout << "Hello world!" << endl;

    closePort();
    return 0;
}

void openPort()
{
    ports = SerialPortWrapper::listAvailablePorts();
    cout << "Number of found serial ports: " << ports.size() << endl;
    for (unsigned int i = 0; i < ports.size(); i++) {
        cout << i + 1 << ".\t Port name: " << ports.at(i) << endl;
    }

    serial = new SerialPortWrapper(ports.at(0), 115200);
    serial->openPort();
}

void closePort()
{
    serial->closePort();
}
