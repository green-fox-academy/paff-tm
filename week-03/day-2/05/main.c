#include <stdio.h>
#include <string.h>
#include <stdint.h>

//TODO: write a function which returns 485 as unsigned integer value
//put your return value in an integer variable in which you should have 229, and print it out
//try to figure out which type casting you should use

unsigned int ret485();

int main()
{
    int return_value = ret485();
    printf("%d", (uint8_t)return_value);

    return 0;
}

unsigned int ret485()
{
    return 485;
}
