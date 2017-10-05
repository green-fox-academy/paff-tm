#include <stdio.h>

/*
create a program which converts the fahrenheit to celsius
the output should look like this:
Fahrenheit       Celsius
  0               -17.8
 20                -6.7
 40                 4.4
 60                15.6
...
print out at least 10 lines
*/

int main() {
    float c = 0;

    printf("Farentheit\tCelsius\n");

    for(int i = 0; i <= 15; i++){
        c = (i * 10 - 32) / 1.8 ;
        printf("%d\t\t%.1f\n", i * 10, c);
    }

	return 0;
}
