/*
 * Take the file You created in the previous exercise.
 * Read it again and write some statistics about it:
 *    * How many lines
 *    * How many characters (with and without spaces)
 *    * How many verses does it have
 */

#include <stdio.h>
#include <string.h>

int main()
{
    FILE *fp = NULL;
    char buffer[256] = "";
    int count_lines = 0;
    int count_chars = 0;
    int count_verses = 0;

    fp = fopen("poem.txt", "r");
    if (fp == NULL) {
        printf("Error with opening the file.");
    } else {

        while (fgets(buffer, 255, (FILE*)fp) != NULL) {
            printf("%s", buffer);
            count_lines++;
            count_chars += strlen(buffer);
            if (strlen(buffer) == 1) {
                count_verses++;
            }
        }

        printf("\n\n");
        printf("lines: \t\t%d\n"
               "characters \t%d\n"
               "verses \t\t%d\n",
               count_lines, count_chars, count_verses);

        fclose(fp);
    }
    return 0;
}
