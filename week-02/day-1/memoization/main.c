#include <stdio.h>
#include <stdlib.h>
#include "memoization.h"

// create a function which returns a Fibonacci number like in the example code
// this time do it with memoization
// again the parameters value should be stored in a .h file

#define MAX_NUM 65

int memo[MAX_NUM];
int nr_of_memoed_values = 0;

int fibonacci_memo(int number);

int main()
{
    if (fib_num > MAX_NUM) {
        printf("Your number is too high!");
    } else {
        printf("%d: %d\n", fib_num, fibonacci_memo(fib_num));
    }

    return 0;
}

int fibonacci_memo(int number)
{
    if (number < 1) {
        return 0;
    } else if (number < 3){
        return 1;
    } else {
        if (number <= nr_of_memoed_values) {
            return memo[number];
        } else {
            memo[number] = fibonacci_memo(number - 1) + fibonacci_memo(number - 2);
            nr_of_memoed_values++;
            return memo[number];
        }
    }
}
