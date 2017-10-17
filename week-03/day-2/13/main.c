#include <stdio.h>
#include <string.h>

int main ()
{
	char str[] = "This is a sample string";
    char *first, *last;
    char chr = 's';

	//TODO: write a program which prints out the distance between the first and last occurance of character 's'

    printf("The string where we're looking for the distance between the first and last occurance of character \'%c\' is:\n%s\n", chr, str);
	for (int i = 0; i < strlen(str); i++)
        printf("%d", (i + 1) % 10);
    printf("\n\n");

    first = strchr(str, chr);
    last = strrchr(str, chr);

    if (first != NULL) {
        printf("The distance is: %d\n", last - first);
    } else {
        printf("There is no such character.\n");
    }

    return 0;
}
