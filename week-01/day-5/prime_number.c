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

void main()
{
    int from = -3;
    int to = 10;
    int is_prime = 1;
    int prime_count = 0;
    int j = 0;

    for (int i = from; i <= to; i++) {
        if (i > 1) {
            if (i == 2){
                is_prime = 1;
            } else if (i > 2) {
                j = 2;
                is_prime = 1;
                do {
                    if (i % j == 0){
                        is_prime = 0;
                    }
                    j++;
                } while ((is_prime == 1) && (j < i));
            }
            if (is_prime == 1){
                printf("%d, ", i);
                prime_count++;
            }
        }
    }
    printf("this is %d prime numbers", prime_count);

    return 0;
}
