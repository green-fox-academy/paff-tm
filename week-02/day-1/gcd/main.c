#include <stdio.h>
#include <stdlib.h>

// create a function to find the greatest common divisor of two numbers (a and b)
// again the parameters value should be stored in a .h file
// use recursion

int gcd(int a, int b);

int main()
{
    int a = 20;
    int b = 12;

    printf("The greatest common divisor of %d and %d is %d", a, b, gcd(a,b));

    return 0;
}

int gcd(int a, int b)
{
    if (a % b == 0) {
        return b;
    } else {
        return gcd(b, a % b);
    }
}
