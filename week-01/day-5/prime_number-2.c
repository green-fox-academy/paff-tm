#include <stdio.h>

/*
Create a program which prints out oll the prime numbers
aslo add a feature where you can tell the from - to limits
for example :
from = 11;
to = 34;
output :
13, 17, 19, 23, 29, 31 , this is 6 prime numbers
*/

int main()
{
    int from = -3;
    int to = 13;
    int divider_count = 0;
    int prime_count = 0;
    int j = 0;

    for (int i = from; i <= to; i++) {
        if (i > 1) {
            j = 2;
            divider_count = 1;
            do {
                if (i % j == 0){
                    divider_count++;
                }
                j++;
            } while ((divider_count < 3) && (j <= i));
            if (divider_count == 2){
                printf("%d, ", i);
                prime_count++;
            }
        }
    }
    if (prime_count > 0)
        printf("this is %d prime numbers", prime_count);
    else
        printf("There is no prime number", prime_count);
    return 0;
}
