#include <stdio.h>

int assort_odd_elements(int *array, int size);

int main(void)
{
	int num_array[] = {8, 7, 9, 20, 3, 81, 79, 66};
	int size_of_array = assort_odd_elements(num_array, 8);

    //TODO: write a function which filters out the odd elements of an integer array
    //do it in the original array
    //your return value should be the real size of the filtered array
    //print out the filtered array's elements

    for (int i = 0; i < size_of_array; i++) {
        printf("%d\n", num_array[i]);
    }

    return 0;
}

int assort_odd_elements(int *array, int size)
{
    int even_count = 0;
    int i = 0;

    while (even_count < size) {
        if (array[i] % 2 == 1) {        // if it is odd then "delete" it
            for (int j = i; (j + 1) < size; j++) {
                array[j] = array[j + 1];
            }
            size--;
        } else {
            even_count++;
            i++;
        }
    }

    return even_count;
}
