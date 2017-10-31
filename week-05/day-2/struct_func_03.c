/*
 * Take the previous exercise and add a function which sorts the elements in an ascending order.
 *
 * Test it in the main function and print the results.
 */

#include <stdio.h>

typedef struct {
    int num_of_items;
    int *array;
} my_struct;

int add(my_struct *numbers, int new_number);
int get(my_struct *numbers, int *number, int position);
int replace(my_struct *numbers, int new_number, int position);
int sort_asc(my_struct *numbers);

int main()
{
    my_struct numbers;
    numbers.num_of_items = 0;
    numbers.array = NULL;

    //add numbers to the array
    for (int i = 1; i < 1000; i++) {
        if (add(&numbers, i) != 0) {
            printf("Error: problem with adding new number");
            break;
        }
    }

    if (replace(&numbers, 666, 2) != 0) {
        printf("Error: index is out of bound\n");
    }

    //print the array
    int number;
    for (int i = 0; i < numbers.num_of_items; i++) {
        if (get(&numbers, &number, i) != 0){
            printf("Error: index is out of bound\n");
            break;
        } else {
             printf("%d ", number);
        }
    }

    return 0;
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
   CIKLUS i = n TÕL 2 IG {
       CIKLUS j = 1 TÕL i-1 IG {
           HA TOMB[j] > TOMB[j+1] AKKOR {
               CSERÉLD FEL ÕKET: TOMB[j], TOMB[j+1]
           }
       }
   }

    for (i = numbers->num_of_

    return 0;
}