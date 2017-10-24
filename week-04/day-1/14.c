#include <stdio.h>

void string_copy(char *dest, char *source);

int main()
{
    char my_string[] = "to be copied";
    char dest[50] = "";

   //TODO: write a function, which copies a string to the 'dest' array, then print out in string format.

    string_copy(dest, my_string);
    printf("dest: \"%s\" ", dest);

    return 0;
}

void string_copy(char *dest, char *source)
{
    int i = 0;
    while (source[i] != '\0') {
        dest[i] = source[i];
        i++;
    }
    dest[i] = '\0';
}
