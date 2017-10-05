#include <stdio.h>

int main() {
	// print the even numbers till 20
    int i = 1;

    printf("FOR loop\n");
    for (int i = 1; i <= 20; i++)
        if (i % 2 == 0)
            printf("%d\n", i);

    printf("DO-WHILE loop\n");

    do {
        if (i % 2 == 0)
            printf("%d\n", i);
        i++;
    } while (i <= 20);

    printf("WHILE loop\n");
    i = 1;
    while (i <= 20) {
        if (i % 2 == 0)
            printf("%d\n", i);
        i++;
    }

    printf("FOR loop, i + 2\n");
    for (int i = 2; i <= 20; i = i + 2)
        printf("%d\n", i);

	return 0;
}
