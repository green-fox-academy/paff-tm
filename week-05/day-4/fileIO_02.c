/*
 * Read the file You created for the first exercise again.
 * Reverse the order of lines and write it out in a new file.
 */

#include <stdio.h>
#include <string.h>

int main()
{
    FILE *fp = NULL;
    FILE *new_fp = NULL;
    char buffer[256] = "";

    int f_pos = 0;
    char c = '\0';


    fp = fopen("poem.txt", "r");
    new_fp = fopen("poem_rev.txt", "w");
    if (fp == NULL || new_fp == NULL) {
        printf("Error with opening file.");
    } else {

        //line will be the offset to the end of file fp
        fseek(fp, 0, SEEK_END);
        f_pos = ftell(fp);

        while (f_pos > 0) {
            do {
                do {
                    f_pos--;
                    fseek(fp, f_pos, SEEK_SET);
                    c = fgetc(fp);
                } while (c == '\n');
            } while (c != '\n' && f_pos > 0);
            fgets(buffer, 255, fp);
            printf("%s", buffer);
            fputs(buffer, new_fp);
        }
    }

    fclose(fp);
    fclose(new_fp);

    return 0;
}
