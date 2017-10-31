/*
 * Take an array of characters, for example this: "In the year 2525, If man is still alive... In the Year 3535, In the Year 4545"
 * Create a function that takes an array of characters as an input, and a single character.
 * It should return all the indexes when teh character appears in an array of integers. Where the first number of the array
 * is how many occurrences of the character there are.
 *
 * Create a main function where You can test this function.
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int *find_char_indexes(char *str, char c);

int main()
{
    char str[] = "In the year 2525, If man is still alive... In the Year 3535, In the Year 4545";
    int *char_indexes;
    char c = 'I';

    char_indexes = find_char_indexes(str, c);

    printf("%s\nThe appearance of %c is %d\n", str, c, char_indexes[0]);
    for (int i = 0; i < char_indexes[0]; i++) {
        printf("%d\n", char_indexes[i + 1]);
    }

    return 0;
}

int *find_char_indexes(char *str, char c)
{
    static int *indexes;
    int num_of_app = 0;

    //counts the appearances of the c character in str
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] == c) {
            num_of_app++;
        }
    }

    indexes = (int*)malloc((num_of_app + 1) * sizeof(int));
    indexes[0] = 0;

    for (int i = 0; i < strlen(str); i++) {
        if (str[i] == c) {
            indexes[0]++;
            indexes[indexes[0]] =  i;
        }
    }

    return indexes;
}
