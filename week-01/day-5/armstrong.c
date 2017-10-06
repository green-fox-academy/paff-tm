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
    printf("%d is the digits of the given number\n", digits);

// check if the given number is an armstrong number
    aa = a;
    for (int i = 1; i <= digits; i++) {
        aa_pwr = aa % 10;                   // aa_pwr is the last digit of the given number
        printf("induló digit: %d\n",aa_pwr);
        for (int j = 0; j < digits; j++)    // aa_pwr will be powered aa
            aa_pwr *= aa_pwr;
        printf("hatványos aa: %d\n",aa_pwr);
        arm_sum += aa_pwr ;                 // add the power of the last digit to sum
        aa /= 10;                           // cut the last digit
    }
    printf("%d is the sum of the powers of the digits\n", arm_sum);

    if (arm_sum == a)
        printf("The %d is an Armstrong number\n", a);
    else
        printf("The %d is not an Armstrong number\n", a);
    return 0;
}
