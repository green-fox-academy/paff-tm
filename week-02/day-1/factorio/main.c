#include <stdio.h>
#include <stdlib.h>
#include "factorio.h"

// create a function called `factorio`
// that returns it's input's factorial with and without recursion
// again the parameters value should be stored in a .h file
//

int factorio_with_recursion(int x);
int factorio_without_recursion(int x);

int main()
{
    printf("The factorial of %d is %d. (calculated with recursion) \n", given_number, factorio_with_recursion(given_number));
    printf("The factorial of %d is %d. (calculated without recursion)\n", given_number, factorio_without_recursion(given_number));
    return 0;
}

int factorio_with_recursion(int x){
    int factorial = 0;
    if (x < 2) {
        factorial = 1;
    } else {
        factorial = x * factorio_with_recursion(x-1);
    }

    return factorial;
}

int factorio_without_recursion(int x){
    int factorial = 1;
    for (int i = 1; i <= x; i++)
        factorial *= i;

    return factorial;
}
