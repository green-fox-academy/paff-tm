#include <stdio.h>
#include <stdlib.h>
#include "greet.h"

// define a variable and assign the value `Greenfox` to it in a .h file
// create a function called `greet` that greets it's input parameter
// define more names to greet, call the function multiple times

void greet(char str[]);

int main()
{
    greet(text1);
    greet(text2);
    return 0;
}

void greet(char str[]) {
    printf("Hello %s!\n", str);
}
