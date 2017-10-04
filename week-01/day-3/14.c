#include <stdio.h>
#include <stdint.h>

int main() {
    uint8_t number = 254;
	uint8_t result;

	result = number + 23;
	// Check the result with printf
	printf("result_8 = %d\n", result);

 	// What happened?! -> overflow
	// Try again with different datatype
	uint16_t result_16 = number + 23;

	// Check the result with printf
	printf("result_16 = %d\n", result_16);

	// What happened and why?
	//----------------------------------------

	int8_t number_negative = number;

	// Check the result with printf
	printf("number_negative = %d\n", number_negative);

	// What happened and why? -> netagive int 11111110 = -2
    return 0;
}