#include <stdio.h>

int main()
{
    // TODO: write a program wich asks for a number, that will be the real size of the array (50 elements are allocated, that's the maximum size)
    int arr[50];
    int nr_of_numbers;

    printf("How many numbers do you want to input (1-50): ");
    do {
        scanf("%d", &nr_of_numbers);
        if ((nr_of_numbers < 1) || (nr_of_numbers > sizeof(arr) / sizeof(arr[0]))) {
            printf("Your number is not in the range!\nGive an other value: ");
        } else {
            break;
        }
    } while (1);
    // Then load up the array with integer values

    for (int i = 0; i < nr_of_numbers; i++) {
        printf("%d. number: ", i + 1);
        scanf("%d", &arr[i]);
        //printf("\n");
    }

	// print out the array
    for (int i = 0; i < nr_of_numbers; i++) {
        printf("%d, ", arr[i]);
    }

    // Then ask for a number, that will be the position, where you want the element to be deleted
    // handle the problem when trying to delete from invalid positions (e.g. negative number)
    int del_pos = 0;
    printf("Whitch position you want to delete: ");
    do {
        scanf("%d", &del_pos);
        if ((del_pos < 1) || (del_pos > nr_of_numbers)) {
            printf("Your given position is not in the range!\nGive an other position to delete: ");
        } else {
            break;
        }
    } while (1);

    for (int i = del_pos - 1; i < nr_of_numbers - 1; i++)
        arr[i] = arr[i + 1];
    nr_of_numbers--;

    // print out the the array after the deleting
    for (int i = 0; i < nr_of_numbers; i++) {
        printf("%d, ", arr[i]);
    }
    printf(" are the numbers in array\n");
    return 0;
}
