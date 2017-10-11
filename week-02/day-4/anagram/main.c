#include <stdio.h>
#include <stdlib.h>

int letter_count(char letter, char string[]);

int main()
{
    char input1[256];
    char input2[256];
    int is_anagram = 1;

    // input the two words
    printf("Check if the two given words are anagram.\n");
    printf("Add the first word: ");
    gets(input1);
    printf("Add the second word: ");
    gets(input2);


    if (strlen(input1) == strlen(input2)) {
        //check letter-by-letter if there are the same number of the i-th letter in both words
        for (int i = 0; i < strlen(input1); i++) {
            if (letter_count(input1[i], input1) != letter_count(input1[i], input2)) {
                is_anagram = 0;
                break;
            }
        }
    } else {
        is_anagram = 0;
    }

    if (is_anagram)
        printf("These are anagrams!\n");
    else
        printf("These are not anagrams!\n");

    return 0;
}

int letter_count(char letter, char string[])
{
    int count = 0;
    for (int i = 0; i < strlen(string); i++) {
        if (string[i] == letter) {
            count++;
        }
    }
    return count;
}
