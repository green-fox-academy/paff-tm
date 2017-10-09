#include <stdio.h>
#include <stdlib.h>
#include "double.h"

// create a function called `doubling` that doubles it's input parameter
// again the parameters value should be stored in a .h file

int doubling(int x);

int main()
{
    printf("The double of %d is %d.\n", value, doubling(value));
    return 0;
}

int doubling(int x) {
    return x * 2;
}
