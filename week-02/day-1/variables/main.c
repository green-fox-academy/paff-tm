#include <stdio.h>

/*
Write a program where you have five functions
first the program should ask for an integer, then
these functions should do various mathematical operations on a given integer
last but not least there should be a variable which counts how many operations
have been done on the given integer
*/

int value = 0;
int counter = 0;

void doubling();
void add3();

int main()
    {
        scanf("%d", &value);

        doubling();
        add3();

        printf("The result is: %d\n", value);
        printf("The number of operations on %d is: %d", value, counter);
        return 0;
    }

void doubling() {
    value *= 2;
    counter++;
    return;
}

void add3() {
    value += 3;
    counter++;
    return;
}

