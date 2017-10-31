/*
 * Create a structure to represent a list of numbers. The structure should know how many number it has stored.
 * Store the numbers in an array.
 * Create functions to:
 *    * Add a new number at the end.
 *    * Get a number at a given index.
 *    * Replace a number at a given index if it exists.
 *
 * If the array is too small, create a new one, copy everything into it, add the new element and delete the old array.
 *
 * Test in the main function whether everything works.
 */

#include <stdio.h>

typedef struct {
    int num_of_items;
    int array[];
} my_struct;

int add(my_struct *numbers, int new_number);
int get(my_struct *numbers, int position);
int replace(my_struct *numbers, int new_number, int position);

int main()
{
    my_struct numbers;
    numbers.num_of_items = 0;

    return 0;
}

int add(my_struct *numbers, int new_number)
{

    return 0;
}

int get(my_struct *numbers, int position)
{

    return 0;
}

int replace(my_struct *numbers, int new_number, int position)
{

    return 0;
}
