#include <stdio.h>
#include <stdlib.h>

//how much odd numbers are between 179 & 371
//you should be able to change the limits, like from 10 to 234
//and the program should print out the odd numbers between those two numbers
//example from 11 to 27 the program should print out:
// 13, 15, 17, 19, 21, 23, 25 this is 7 odd number between 11 and 27

int main()
{
    int a = 179;
    int b = 371;
    int odd = 0;

    if (a < b) {
        for (int i = a; i <= b; i++) {
            if (i % 2 == 1) {
                odd++;
                printf("%d, ", i);
            }
        }
        printf("this is %d odd numbers between %d and %d", odd, a, b);
    } else {
        printf("Second number must be greater than the first!\n");
    }

	return 0;
}
