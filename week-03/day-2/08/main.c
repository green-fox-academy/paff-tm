#include <stdio.h>
#include <stdlib.h>


void transform (char str[], int original_base, int new_base);

//TODO: write a program, which transforms a number from a number system to another.
//use the stdlib.h functions, and take care of error handling (see the reference)
//the transform() function should print out the result.

int main()
{
    char str[20];
    int original_base;
    int new_base;

    printf("Give me a number to transform it in an other system: ");
    scanf("%s", str);
    printf("Give me the original base: ");
    scanf("%d", &original_base);
    printf("Give me the number of the new base: ");
    scanf("%d", &new_base);

    transform(str, original_base, new_base);

    return(0);
}

void transform (char str[], int original_base, int new_base)
{
    char str_new_number[20] = "";
    long int value = 0;

    value = strtol(str, 0, original_base);
    printf("number in base %d: %d\n", original_base, value);

    ltoa(value, str_new_number, new_base);
    printf("number in base %d: %s\n", new_base, str_new_number);
}
