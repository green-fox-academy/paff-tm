/*
 * Take the previous exercise and add a function which sorts the elements in an ascending order.
 *
 * Test it in the main function and print the results.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int num_of_items;
    int *array;
} my_struct;

void print_array(my_struct *numbers);
int add(my_struct *numbers, int new_number);
int get(my_struct *numbers, int *number, int position);
int replace(my_struct *numbers, int new_number, int position);
int sort_asc(my_struct *numbers);

int main()
{
    my_struct numbers;
    numbers.num_of_items = 0;
    numbers.array = NULL;
    int random = 0;
    time_t t;

    srand((unsigned) time(&t));

    //add numbers to the array
    for (int i = 1; i < 100; i++) {
        if (add(&numbers, random = rand() % 1000) != 0) {
            printf("Error: problem with adding new number");
            break;
        }
    }

    if (replace(&numbers, 666, 2) != 0) {
        printf("Error: index is out of bound\n");
    }

    printf("Original numbers:\n");
    print_array(&numbers);

    sort_asc(&numbers);

    printf("\n\nSorted numbers:\n");
    print_array(&numbers);


    return 0;
}

void print_array(my_struct *numbers)
{
    int number;
    for (int i = 0; i < numbers->num_of_items; i++) {
        get(numbers, &number, i);
        printf("%d ", number);
    }
}

int add(my_struct *numbers, int new_number)
{
    //create a new - bigger - array
    int *new_array;
    new_array = (int*) malloc(sizeof(int) * (numbers->num_of_items + 1));

    if (new_array == NULL) {
        return -1;
    }

    //copy the values to the new array
    for (int i = 0; i < numbers->num_of_items; i++) {
        new_array[i] = numbers->array[i];
    }

    //set the pointer to the new array
    free(numbers->array);
    numbers->array = new_array;

    //add the new number, and increase the numbers
    numbers->array[numbers->num_of_items] = new_number;
    numbers->num_of_items++;
    return 0;
}

int get(my_struct *numbers, int *number, int position)
{
    if (position >= 0 && position < numbers->num_of_items) {
        *number = (numbers->array)[position];
        return 0;
    } else {
        return -1;
    }
}

int replace(my_struct *numbers, int new_number, int position)
{
    if (position > 0 && position < numbers->num_of_items) {
        numbers->array[position] = new_number;
        return 0;
    } else {
        return -1;
    }
}

int sort_asc(my_struct *numbers)
{
    int temp = 0;
    for (int i = numbers->num_of_items; i > 1; i--)
        for (int j = 0; j < i - 1; j++)
            if (numbers->array[j] > numbers->array[j + 1]) {
                temp = numbers->array[j];
                numbers->array[j] = numbers->array[j + 1];
                numbers->array[j + 1] = temp;
            }
    return 0;
}
