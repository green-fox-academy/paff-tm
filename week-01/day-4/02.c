#include <stdio.h>
#include <stdlib.h>

/*
write a program to check whether a given number is positive or negative
*/

int main()
{
    int a = -211;

    if (a < 0){
        printf("%d is negative", a);
    } else {
        printf("%d is positive", a);
    }

/*
    if (a % 2 == 0) {
        printf("%d paros\n", a);
    } else {
        printf("%d paratlan\n", a);
    }

    switch (a % 2) {
    case (0):
        printf("%d paros\n", a);
        break;
    default:
        printf("%d paratlan\n", a);
    }
*/
    return 0;
}
