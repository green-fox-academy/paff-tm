#include <stdio.h>
#include <stdint.h>

int main() {
	uint8_t a = 0b00100111;

	a = 40;

	printf("a binarisan= ");

	printf("%c", (a & 0b10000000 ? '1' : '0'));
	printf("%c", (a & 0b01000000 ? '1' : '0'));
	printf("%c", (a & 0b00100000 ? '1' : '0'));
	printf("%c", (a & 0b00010000 ? '1' : '0'));
	printf("%c", (a & 0b00001000 ? '1' : '0'));
	printf("%c", (a & 0b00000100 ? '1' : '0'));
	printf("%c", (a & 0b00000010 ? '1' : '0'));
	printf("%c", (a & 0b00000001 ? '1' : '0'));
	printf("\n");

	return 0;
}
