#include <stdio.h>
#include <limits.h>

int main()
{
	int number_array[8] = {48, 59, 2, -8, 55, 56, 78, 12};

	//TODO:
	// Write a C program to find the two largest element in an array using only 1 for loop
	// From <limits.h> use INT_MIN: this is the least integer

	int largest_a = 0;
    int largest_b = 0;

    printf("largest\t2nd largest\n");
	for (int i = 0; i < sizeof(number_array) / sizeof(number_array[0]); i++) {
        if (number_array[i] > largest_b) {
            if (number_array[i] > largest_a) {
                largest_b = largest_a;
                largest_a = number_array[i];
            } else {
                largest_b = number_array[i];
            }
            printf("%d\t%d\n", largest_a, largest_b);
        }
	}
	printf("The two largest numbers are: %d and %d.", largest_a, largest_b);

	return 0;
}
