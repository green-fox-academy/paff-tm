#include <stdio.h>
#include <stdlib.h>

/*
write a simple program which can help you decide is it hot enough to turn on the AC or not
for example if temperature 20 or less the output is :
it is too cold for the AC
or, the temperature is between 21-24:
it is up to you to turn on the AC
...
*/

int main()
{
    int temperature;
    int range; // 0: cold - 1: avg - 2: hot
    temperature = 21;


    if (temperature < 21){
        range = 0;
    } else if (temperature > 24){
        range = 2;
    } else {
        range = 1;
    }

    switch (range) {
    case (0):
        printf("it is too cold for the AC\n");
        break;
    case (1):
        printf("it is up to you to turn on the AC\n");
        break;
    case (2):
        printf("it is time to use AC\n");
        break;
    }

    return 0;
}
