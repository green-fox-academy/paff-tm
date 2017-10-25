#include <stdio.h>

typedef struct complex
{
    float real;
    float imag;
} complex;


//TODO: create 3 functions, which calculates the sum, subtraction and multiplication of a complex number.
// you can read about complex number's operations here: https://www.mathsisfun.com/numbers/complex-numbers.html

complex comp_add(complex a, complex b);
complex comp_sub(complex a, complex b);
complex comp_mul(complex a, complex b);

int main()
{
    complex n1, n2;
    n1.real = 3; //5;
    n1.imag = 2; //7.2;

    n2.real = 1; //6;
    n2.imag = 7; //8.1;

    printf("nr1: (%g + %gi); nr2 (%g + %gi)\n", n1.real, n1.imag, n2.real, n2.imag);

    printf("result of addition:       (%g + %gi)\n", comp_add(n1, n2).real, comp_add(n1, n2).imag);
    printf("result of subtraction:    (%g + %gi)\n", comp_sub(n1, n2).real, comp_sub(n1, n2).imag);
    printf("result of multiplication: (%g + %gi)\n", comp_mul(n1, n2).real, comp_mul(n1, n2).imag);

    return 0;
}

complex comp_add(complex a, complex b)
{
    complex result;

    result.real = a.real + b.real;
    result.imag = a.imag + b.real;

    return result;
}

complex comp_sub(complex a, complex b)
{
    complex result;

    result.real = a.real - b.real;
    result.imag = a.imag - b.real;

    return result;
}

complex comp_mul(complex a, complex b)
{
    complex result;

    result.real = a.real * b.real - a.imag * b.imag;
    result.imag = a.real * b.imag + a.imag * b.real;

    return result;
}
