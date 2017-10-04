#include <stdio.h>
#include <stdlib.h>

/*
swap the values of the to number
print out first the original values then print out the swaped values
but this time use bitwise operators only
*/

int main()
{
    int x = 32;
    int y = 20;

    printf("original:\nx = %d\ny = %d\n\n", x, y);

    x = x ^ y;
    y = x ^ y;
    x = x ^ y;

    printf("swapped:\nx = %d\ny = %d\n", x, y);

    return(0);

}
