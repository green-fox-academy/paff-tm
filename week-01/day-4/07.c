#include <stdio.h>
#include <stdlib.h>

/*
create a simple program which checks if the num is odd or even
*/

int main()
{
    int num;
    num = 12;

    switch (num % 2) {
    case (0):
        printf("odd\n");
        break;
    default:
        printf("not odd\n");
    }

    return 0;
}
