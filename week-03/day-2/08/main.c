#include <stdio.h>
#include <stdlib.h>


void transform (char str[], int original_base, int new_base);

//TODO: write a program, which transforms a number from a number system to another.
//use the stdlib.h functions, and take care of error handling (see the reference)
//the transform() function should print out the result.

int main()
{
    char str[32]; //= "-2147483649";
    int original_base;
    int new_base;


    printf("Give me a number to transform it in an other system: ");
    scanf("%s", str);

    // get the original base of the given number
    while (1) {
        printf("Give me the original base: ");
        scanf("%d", &original_base);
        if (original_base < 2 || original_base > 36)
            printf("The value should be between 2 and 36. Give it again: ");
        else
            break;
    }

    // get the new base as a number between 2 and 36
    printf("Give me the number of the new base: ");
    while (1) {
        scanf("%d", &new_base);
        if (new_base < 2 || new_base > 36)
            printf("The value should be between 2 and 36. Give it again: ");
        else
            break;
    }

    transform(str, original_base, new_base);

    return(0);
}

void transform (char str[], int original_base, int new_base)
{
    char str_new_number[32] = "";
    long int value = 0;
    char *ptr = 0;

    value = strtol(str, &ptr, original_base);
    if (ptr != str) {
        printf("number in base 10: %d\n", value);
        ltoa(value, str_new_number, new_base);
        printf("number in base %d: %s\n", new_base, str_new_number);
    } else {
        printf("Error: The given string can't be converted to integer.\n");
    }
}
