#include <stdio.h>
#include <stdlib.h>

// create a function to calculate factorial of a number using recursion

int fact(int x);

int main()
{
    int number = 7;

    printf("%d", fact(number));

    return 0;
}

int fact(int x)
{
    if (x < 2)
        return 1;
    else
        return x * fact(x-1);
}
