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
        if ((real_size_of_array > 0) && (real_size_of_array <= sizeof(arr) / sizeof(arr[0]))){
            break;
        }
    } while (1);

 // fill up integer values
    for (int i = 0; i < real_size_of_array; i++) {
        arr[i] = rand()%10;
    }

    int num_of_unique_elements = 0;
    int unique = 1;
    for (int i = 0; i < real_size_of_array; i++) {
        unique = 1;
        for (int j = 0; (j < num_of_unique_elements) && unique == 1; j++) {
            if (arr[i] == freq[j]) {
                unique = 0;
            }
        }
        if (unique == 1) {
            freq[num_of_unique_elements] = arr[i];
            num_of_unique_elements++;
        }
    }

 // print all item of array
    printf("  All numbers\t%c Uniqe numbers\n", 179);
    for (int i = 0; i < real_size_of_array; i++) {
        if (i < num_of_unique_elements)
            printf("\t%d\t%c\t%d\n", arr[i], 179, freq[i]);
        else
            printf("\t%d\t%c\n", arr[i], 179);
    }

// print all items of array
/*
    printf("The unique numbers are:\n");
    for (int i = 0; i < num_of_unique_elements; i++) {
        printf("%d\n", freq[i]);
    }
*/
    return 0;
}
