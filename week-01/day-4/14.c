
/*
modify the previous program to print the table reverse order
for example:
Fahrenheit       Celsius
300               148.9
280               137.8
260               126.7
240               115.6
...
print out at least 10 lines
*/

int main() {
    float c = 0;

    printf("Farentheit\tCelsius\n");

    for(int i = 300; i >= 0; i = i - 20){
        c = (i - 32) / 1.8 ;
        printf("%d\t\t%.1f\n", i, c);
    }

	return 0;
}
