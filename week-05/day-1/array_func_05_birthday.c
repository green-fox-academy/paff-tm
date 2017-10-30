/*
 * Take this array of characters: "2319834571976548721b1992456t831977451963782"
 * Create a function that takes an array of characters as the input. (Test it with the one above).
 * It should return an array of integers. Each representing a valid birthdate year extracted from
 * the string of characters.
 *
 * Create a main function to test this and print out the birthyears in a new line each.
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int find_birthday(char *input_str, int dates[], int *num_of_dates);

int main()
{
    char str[] = "2319834571976548721b1992456t831977451963782";
    int dates[50];
    int num_of_dates =0;

    find_birthday(str, dates, &num_of_dates);

    for (int i = 0; i < num_of_dates; i++) {
        printf("%d \n", dates[i]);
    }

    return 0;
}

int find_birthday(char input_str[], int dates[], int *num_of_dates)
{
    int i = 0;
    char s[5];
    int d = 0;
    char *p = NULL;

    *num_of_dates = 0;

    while (input_str[i] != '\0') {
        if (isdigit((int)input_str[i]) != 0) {
            p = input_str + i;
            strncpy(s, p, 4);
            d = atoi(s);
            if (d > 1918 && d < 2018) {
                dates[*num_of_dates] = d;
                (*num_of_dates)++;
            }
        }
        i++;
    }

    return 0;
}
