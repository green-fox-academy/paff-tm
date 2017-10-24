#include <stdio.h>

int my_strlen(char *string);

int main()
{
	char my_string[50] = "Hello world!";

	//TODO: implement your own strlen function.

    printf("%s\n", my_string);
	printf("%d\n", my_strlen(my_string));

	return 0;
}

int my_strlen(char *string)
{
    int length = 0;
    while (string[length] != '\0') {
        length++;
    }
    return length;
}
