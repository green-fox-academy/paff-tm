#include <stdio.h>
#include <stdlib.h>
#include "printer.h"

// Create a function called `printer`
// which prints the input parameters
// can have multiple number of arguments
// store your variables in a .h file

void printer(int a, int b, int c);

int main()
{
    printer(printable_num_1, printable_num_2, printable_num_3);
    return 0;
}

void printer(int a, int b, int c) {
    printf("%d, %d, %d", a, b, c);
}
