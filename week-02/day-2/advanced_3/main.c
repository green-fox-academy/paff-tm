#include <stdio.h>

int main()
{
    int arr[20];
    int freq[20];

    // TODO: write a program wich asks for a number, that will be the real size of the
    // array (20 elements are allocated, that's the maximum size)
    // Then load up the array with integer values
    // Finally print all unique elements in array

    int real_size_of_array = 0;
    do {
        printf("Add the size of the array (1-20): ");
        scanf("%d", &real_size_of_array);
        if ((real_size_of_array > 0) && (real_size_of_array < sizeof(arr) / sizeof(arr[0]))){
            break;
        }
    } while (1);

 // fill up integer values
    for (int i = 0; i < real_size_of_array; i++) {
        arr[i] = rand()%1000;
    }

 // print all item of array
     for (int i = 0; i < real_size_of_array; i++) {
        printf("%d\n", arr[i]);
    }

    return 0;
}
