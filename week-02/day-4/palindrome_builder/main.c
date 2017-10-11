#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void make_palind(char input[], char output[]);

int main()
{
    char str_input[128] = "";
    char str_palind[256] = "";

    printf("Make a palindrom from the given word.\n");
    printf("Add the word: ");
    gets(str_input);

    make_palind(str_input, str_palind);
    printf("Here is a palindrom of your input: %s", str_palind);

    return 0;
}

void make_palind(char input[], char output[])
{
    strcpy(output, input);
    int i = 0;
    while (i < strlen(input)) {
        output[strlen(input) + i] = input[strlen(input) - i - 1];
        i++;
    }
    output[strlen(input) + i] = '\0';
}
