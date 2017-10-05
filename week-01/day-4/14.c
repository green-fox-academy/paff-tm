
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
    float f = 0;

    printf("Celsius\tFarentheit\n");

    for(int i = 0; i <= 15; i++){
        f = (i * 10) * 1.8 + 32;
        printf("%d\t%.1f\n", i * 10, f);
    }

	return 0;
}
