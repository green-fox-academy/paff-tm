#include <stdio.h>
#include <math.h>

// This program should work correctly with the following input: 20, 400

int main()
{
	double number, result, x;
	printf("Please enter a number: ");
	fflush(stdin);
	scanf("%lf", &number);

	printf("Please enter the square of that number: ");
	fflush(stdin);
	scanf("%lf", &result);

	x = pow(number, 2);

	if (x == result)
		printf(":)\n");
	else
		printf(":(\n");

	return 0;
}
