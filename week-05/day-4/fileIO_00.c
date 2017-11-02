/*
 * Create a text file with You favourite poem in it. If You don't have one, just take one.
 *
 * Read the poem from the file and print it on the console.
 */

#include <stdio.h>

int main()
{
    FILE *fp = NULL;
    char buffer[256] = "";

    fp = fopen("poem.txt", "r");
    if (fp == NULL) {
        printf("Error with opening the file.");
    } else {

        while (fgets(buffer, 255, (FILE*)fp) != NULL) {
            printf("%s", buffer);
        }

        printf("\n\n");
        fclose(fp);
    }
    return 0;
}
