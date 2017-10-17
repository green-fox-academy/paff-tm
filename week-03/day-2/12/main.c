#include <stdio.h>
#include <string.h>
int main ()
{
	char string[55] ="This is a string for testing";
	char *p;

	//TODO: write a program, which lists all position where character 'i' is found

	printf("The string where we looking for the character \'%c\' is:\n%s\n", 'i', string);
	for (int i = 0; i < strlen(string); i++)
        printf("%d", (i + 1) % 10);
    printf("\n\n");

	printf("The character \'i\' is at the positions:\n");
	p =	strstr(string, "i");
	while (p != NULL) {
        p++;
        printf("%d\n", p - string);
        p =	strstr(p, "i");
	}
	return 0;
}
