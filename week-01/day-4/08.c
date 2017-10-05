#include <stdio.h>
#include <stdlib.h>

/*
create a program which generates numbers from 0 to 100
for each number write if the number is odd or even (don't print out the numbers)
*/

int main()
{
    for (int i = 1; i <= 100; i++) {
        switch (i % 2) {
        case (0):
            printf("odd\n");
            break;
        default:
            printf("even\n");
        }
    }

    return 0;
}
