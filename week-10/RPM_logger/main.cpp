#include <iostream>
#include "RPM_logger.h"

#define PORT    0

using namespace std;

int main()
{
    RPM_logger rl;
    rl.openPort(0);

    rl.startStop();

    rl.closePort();
    return 0;
}

