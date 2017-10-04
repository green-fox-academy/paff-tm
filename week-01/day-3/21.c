#include <stdio.h>
#include <stdint.h>

int main() {
	uint8_t ab = 123;
	uint8_t credits = 49;
	uint8_t is_bonus = 0;	// This means "false"
	// if credits are at least 50,
	// and is_bonus is false decrement ab by 2
	// if credits are smaller than 50,
	// and is_bonus is false decrement ab by 1
	// if is_bonus is true ab should remain the same

	if (is_bonus == 0){
        if (credits >= 50){
            ab -= 2;
            printf("is_bonus is false ; credits >= 50\n");
        }
        else{
            ab--;
            printf("is_bonus is false ; credits < 50\n");
        }
	}
	else{
        printf("is_bonus is true\n");
	}

	printf("ab = %d\n", ab);

	return 0;
}
