#include <stdio.h>
#include <string.h>

int main()
{
    //TODO: write a c program which, splits a string to words by space
	//solve the problem with the proper string.h function

    char string[256];
    char *ptr;

    printf("Type in a sentence:\n\n");
    gets(string);

	ptr = strtok(string, " ");
	while (ptr != NULL) {
        printf("%s\n", ptr);
        ptr = strtok(NULL, " ");
	}

    return(0);
}
