#include <stdio.h>

void int_to_bin_digit(int in, int count)
{
	int mask = 1U << (count - 1);
	int i;
	for (i = 0; i < count; i++) {
		int result = (in & mask) ? 1 : 0;
		printf("%d", result);
		in = in << 1;
	}
}

int main()
{
	int_to_bin_digit(-1000, 32);
	return 0;
}
