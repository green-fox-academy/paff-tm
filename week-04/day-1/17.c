#include <stdio.h>
#define MAX_CHARS 255 // Maximum characters allowed

char max_occur(char str[], int *num_of_occ);

int main()
{
    //TODO: write a function which finds the maximum occurrence of a character in a given string.
    //return with the most frequent character
    //the number of occurrence should be an output parameter

    char str[] = "e is the most frequent element.";
    int num_of_occ = 0;

    printf("%s\n", str);
    printf("'%c' is the most frequent character. \n", max_occur(str, &num_of_occ));
    printf("There are %d peaces in the string.\n",  num_of_occ);

    return 0;
}

char max_occur(char str[], int *num_of_occ)
{
    char chr = ' ';
    int temp_num_of_occ = 0;
    *num_of_occ = 0;

    for (int i = 0; str[i] != '\0'; i++) {          //check every character in the string
        temp_num_of_occ = 0;
        for (int j = 0; str[j] != '\0'; j++) {      //count the occurrence of the 'i'th character
            if (str[i] == str[j]) {
                temp_num_of_occ++;
            }
            if (temp_num_of_occ > *num_of_occ) {    //if it's bigger than we had before,
                *num_of_occ = temp_num_of_occ;      //then this is the occurrence
                chr = str[i];                       //of the most frequent character
            }
        }
    }

    return chr;
}
