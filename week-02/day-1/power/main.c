#include <stdio.h>
#include <stdlib.h>

// create a function which returns the power of a base number

int pow(int base, int power);

int main()
{
    int base = 2;
    int power = 7;

    printf("%d", pow(base, power));

    return 0;
}

int pow(int base, int power)
{
    if (power == 1){
        return base;
    } else {
        return base * pow(base, power - 1);
    }
}
