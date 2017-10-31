/*
 * Create an array of integers. Make it 16 long. Fill it up with numbers as You wish. Print them out.
 *     * Iterate over it with a pointer so, that You only get to each _second_ element. Print out only these.
 *     * Iterate over it only touching each _fourth_ element. Print out only these.
 *     * Iterate over it only touching each _eighth_ element. Print out only these.
 */

#include <stdio.h>

int main()
{
    int array[16];
    int *p_array;

    p_array = array;

    for (int i = 0; i < 16; i++) {
        array[i] = rand() % 1000;
    }

    printf("The original array: \n");
    for (int i = 0; i < 16; i++) {
        printf("%d ", *(p_array + i));
    }

    printf("\n\nEvery second: \n");
    for (int i = 1; i < 16; i += 2) {
        printf("%d ", *(p_array + i));
    }

    printf("\n\nEvery fourth: \n");
    for (int i = 3; i < 16; i += 4) {
        printf("%d ", *(p_array + i));
    }

    printf("\n\nEvery eighth: \n");
    for (int i = 7; i < 16; i += 8) {
        printf("%d ", *(p_array + i));
    }

    return 0;
}

