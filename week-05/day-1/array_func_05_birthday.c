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

int *find_birthday(char *input_str);

int main()
{
    char str[] = "2319834571976548721b1992456t831977451963782";
    int *dates;

    dates = find_birthday(str);

    for (int i = 1; i < dates[0] + 1; i++) {
        printf("%d \n", dates[i]);
    }

    return 0;
}

int *find_birthday(char *input_str)
{
    int i = 0;
    char s[5];
    int year = 0;
    char *p = NULL;
    static int dates[50];

    dates[0] = 0;

    while (input_str[i] != '\0') {
        if (isdigit(input_str[i]) != 0) {
            p = input_str + i;
            strncpy(s, p, 4);
            year = atoi(s);
            if (year > 1918 && year < 2018) {
                dates[dates[0] + 1] = year;
                dates[0]++;
            }
        }
        i++;
    }

    return dates;
}
