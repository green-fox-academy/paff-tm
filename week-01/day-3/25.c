#include <stdio.h>
#include <stdlib.h>

/*
write a program to find the largest number of three
*/

int main()
{
    int a = 13;
    int b = 29;
    int c = 7;

    if ((a > b) && (a > c)){
        printf("a");
    } else if ((b > a) && (b > c)) {
        printf("b");
    } else {
        printf("c");
    }

    return 0;
}
