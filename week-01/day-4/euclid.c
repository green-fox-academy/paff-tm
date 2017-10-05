#include <stdio.h>
#include <stdlib.h>

/*
find the greatest common divisor of the two given variables
use Euclid's algorithm, if you don't know it look it up on the internet
*/

int main()
{
    int x = 32;
    int y = 20;

    int a = x;
    int b = y;
    int c = x % y;

    // a = b * i + c
    while (c > 0) {
        printf("%d = %d * i + %d\n", a, b, c);
        a = b;
        b = c;
        c = a % b;
    }

    printf("%d es %d legnagybb kozos osztoja: %d", x, y, b);

    return 0;
}
