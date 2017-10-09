#include <stdio.h>
#include <stdlib.h>
#include "sum.h"

// Write a function called `sum` that sum all the numbers
// until the given parameter which you store in a .h file

int sum(int to_nr);

int main()
{
    printf("The sum of the numbers until %d is %d.", given_parameter, sum(given_parameter));

    return 0;
}

int sum(int to_nr) {
    int sum_to = 0;
    for (int i = 1; i <= to_nr; i++)
        sum_to += i;
    return sum_to;
}
