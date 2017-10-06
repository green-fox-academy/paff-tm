#include <stdio.h>

// Armstrong

void main()
{
    int a = 0;
    int aa = 0;
    int aa_pwr = 0;
    int digits = 0;
    int arm_sum = 0;

    printf("Please input a number: ");
    scanf("%d", &a);

// determine the digits of the number
    aa = a;
    do {
        aa /= 10;
        digits++;
    } while (aa > 0);

// check if the given number is an armstrong number
    aa = a;
    for (int i = 1; i <= digits; i++) {
        aa_pwr = aa % 10;                   // aa_pwr will be the last digit of the given number
        for (int j = 1; j < digits; j++)    // aa_pwr will be powered with the last digit of a
            aa_pwr *= aa % 10;
        arm_sum += aa_pwr ;                 // add the power of the last digit to sum
        aa /= 10;                           // cut the last digit
    }

// print the result
    if (arm_sum == a)
        printf("\nThe %d is an Armstrong number\n", a);
    else
        printf("\nThe %d is not an Armstrong number\n", a);
    return 0;
}
