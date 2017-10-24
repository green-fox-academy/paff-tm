#include <stdio.h>

int first_word(char *string, char *first);

int main()
{
    //TODO: write a function, which extracts the first word of a given string.
    //return with the word's length

    char str[] = "Extracting the first word.";
    char first[50] = "";

    printf("%s\n", str);
    printf("There are %d characters in the first word, which is : \"%s\"\n", first_word(str, first), first);

    return 0;
}

int first_word(char *string, char *first)
{
    int num_of_chars = 0;

    while (string[num_of_chars] != ' ') {
        first[num_of_chars] = string[num_of_chars];
        num_of_chars++;
    }

    return num_of_chars;
}
