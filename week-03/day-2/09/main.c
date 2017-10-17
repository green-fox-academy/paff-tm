#include <stdio.h>
#include <stdlib.h>

void binary_adder (char *bin_op_1, char *bin_op_2);

//TODO: write a program which asks for two binary numbers.
//write a function, which prints out the sum of the 2 binary numbers.

int main()
{

    char a[20];
    char b[20];

    printf("Give me a binary number: ");
    scanf("%s", &a);
    printf("Give me another binary number: ");
    scanf("%s", &b);

    binary_adder(a, b);

    return(0);
}

void binary_adder (char *bin_op_1, char *bin_op_2)
{
    int a = 0, b = 0;
    int result_int = 0;
    char result_str[] = "";

    a = strtol(bin_op_1, 0, 2);
    b = strtol(bin_op_2, 0, 2);

    result_int = a + b;

    itoa(result_int, result_str, 2);
    printf("%s", result_str);
}
