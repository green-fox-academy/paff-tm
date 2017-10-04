#include <stdio.h>
#include <stdint.h>

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

int main() {
    uint8_t x = 0b11001100;
    uint8_t y = 0b01010101;
	uint8_t z;

    printf("x  = "BYTE_TO_BINARY_PATTERN, BYTE_TO_BINARY(x));
    printf(" %d\n", x);
    printf("y  = "BYTE_TO_BINARY_PATTERN, BYTE_TO_BINARY(y));
    printf(" %d\n", y);

	// Be z equal to the bitwise and of x and y
	z = x & y;

	// Check the result with printf
    printf("z1 = "BYTE_TO_BINARY_PATTERN, BYTE_TO_BINARY(z));
    printf(" %d\n", z);

	// Be z equal to the bitwise or of x and y
	z = x | y;

	// Check the result with printf
    printf("z2 = "BYTE_TO_BINARY_PATTERN, BYTE_TO_BINARY(z));
    printf(" %d\n", z);

    return 0;
}
