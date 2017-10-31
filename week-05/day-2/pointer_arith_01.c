/*
 * Create an array of integers. Make it 10 long at least. Fill it up with numbers - random or toherwise - as You wish.
 * Iterate over this array using a pointer. Print out it's elements.
 */

#include <stdio.h>

int main()
{
    int array[20];
    int *p_array;

    p_array = array;

    for (int i = 0; i < 20; i++) {
        array[i] = rand() % 1000;
    }

    for (int i = 0; i < 20; i++) {
        printf("%d ", *(p_array + i));
    }

    return 0;
}

