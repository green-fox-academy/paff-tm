#include <stdio.h>
int main()
{
    //write a program which loads up fully a 50-sized integer array starting from 200 in descending order
    //but your array should contain elements which are divisible by 5 and 17
    //print out the array

    int my_array[50];
    int j = 200;

    for (int i = (sizeof(my_array) / sizeof(my_array[0])); i > 0; i--) {
        while (j % 5 != 0 || j % 17 != 0){
            j++;
        }
        my_array[i] = j;
        j++;
    }

    for (int i = 0; i < (sizeof(my_array) / sizeof(my_array[0])); i++) {
        printf("%d, ", my_array[i]);
    }

    return 0;
}
