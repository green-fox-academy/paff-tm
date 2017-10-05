#include <stdio.h>

/*
Write a program that prints the numbers from 1 to 100.
But for multiples of three print "Fizz" instead of the number
and for the multiples of five print "Buzz".
For numbers which are multiples of both three and five print "FizzBuzz".
But this time, use switch
*/

int main() {
    int div = 0;

    for (int i = 1; i <= 100; i++){
        div = 0;
        if (i % 3 == 0)
            div = div + 1;
        if (i % 5 == 0)
            div = div + 2;

        switch (div) {
        case (1):
            printf("Fizz");
            break;
        case (2):
            printf("Buzz");
            break;
        case (3):
            printf("FizzBuzz");
            break;
        default:
            printf("%d", i);
        }
        printf("\n");
    }

    return 0;
}
