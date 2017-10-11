#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int num_of_elements (int array[]);
void print_array (int array[]);

int main()
{
    int nr_of_items = 0;
    do {
        printf("Please add the highest number to check if it is a prime: ");
        scanf("%d", &nr_of_items);
    } while (nr_of_items < 1);

    int is_prime[nr_of_items]; // 1 if the n + 2 is prime, -1 if not prime

    //fill is_prime with 0s
    for (int i = 0; i < nr_of_items; i++)
        is_prime[i] = 0;

    //print_array(is_prime);

    for (int i = 0; i < nr_of_items; i++) {
        if (is_prime[i] == 0) {
                is_prime[i] = 1;
        }
        for (int j = i + (i + 2); j < nr_of_items; j = j + (i + 2)){
            is_prime[j] = -1;
        }
    }

    //print the prime numbers
    for (int i = 0; i < nr_of_items; i++) {
        if (is_prime[i] == 1) {
            printf("%d ", i + 2);
        }
    }

    return 0;
}

int num_of_elements (int array[])
{
    return (sizeof(array) / sizeof(array[0]));
}

void print_array (int array[])
{
    printf("%d ", sizeof(array));
    printf("%d ", sizeof(array[0]));

    for (int i = 0; i < sizeof(array) / sizeof(array[0]); i++)
        printf("%d ", array[i]);
}
