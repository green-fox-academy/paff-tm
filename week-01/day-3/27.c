#include <stdio.h>
#include <stdlib.h>

/*
swap the values of the to number
print out first the original values then print out the swaped values
but this time use bitwise operators only
*/

#define BYTE_TO_BINARY_PATTERN "%c%c%c%c%c%c%c%c"
#define BYTE_TO_BINARY(byte)  \
  (byte & 0x80 ? '1' : '0'), \
  (byte & 0x40 ? '1' : '0'), \
  (byte & 0x20 ? '1' : '0'), \
  (byte & 0x10 ? '1' : '0'), \
  (byte & 0x08 ? '1' : '0'), \
  (byte & 0x04 ? '1' : '0'), \
  (byte & 0x02 ? '1' : '0'), \
  (byte & 0x01 ? '1' : '0')


int main()
{
    int x = 32;
    int y = 20;

    printf("original:\n", x, y);
    printf("x = %d = "BYTE_TO_BINARY_PATTERN"\n", x, BYTE_TO_BINARY(x));
    printf("y = %d = "BYTE_TO_BINARY_PATTERN"\n\n", y,  BYTE_TO_BINARY(y));

    printf("x = x ^ y\n");
    x = x ^ y;
    printf("x = %d = "BYTE_TO_BINARY_PATTERN"\n", x, BYTE_TO_BINARY(x));
    printf("y = %d = "BYTE_TO_BINARY_PATTERN"\n\n", y,  BYTE_TO_BINARY(y));

    printf("y = x ^ y\n");
    y = x ^ y;
    printf("x = %d = "BYTE_TO_BINARY_PATTERN"\n", x, BYTE_TO_BINARY(x));
    printf("y = %d = "BYTE_TO_BINARY_PATTERN"\n\n", y,  BYTE_TO_BINARY(y));

    printf("x = x ^ y\n");
    x = x ^ y;
    printf("x = %d = "BYTE_TO_BINARY_PATTERN"\n", x, BYTE_TO_BINARY(x));
    printf("y = %d = "BYTE_TO_BINARY_PATTERN"\n\n", y,  BYTE_TO_BINARY(y));

    printf("Tadaaa...!\n");

    return(0);

}
