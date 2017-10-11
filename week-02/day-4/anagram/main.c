#include <stdio.h>
#include <stdlib.h>

int letter_count(char input1[256], char input2[256]);

int main()
{
    char input1[256];
    char input2[256];
    int is_anagram = 1;
    int letter_count1 = 0;
    int letter_count2 = 0;

    printf("Check if the two given words are anagram.\n");
    printf("Add the first word: ");
    gets(input1);
    printf("Add the second word: ");
    gets(input2);

    if (strlen(input1) == strlen(input2)) {
        for (int i = 0; i < strlen(input1); i++) {
            // counts the input1 ith letters in input1
            letter_count1 = 0;
            for (int j = 0; j < strlen(input1); j++) {
                if (input1[j] == input1[i]) {
                    letter_count1++;
                }
            }
            // counts the input1 ith letters in input2
            letter_count2 = 0;
            for (int j = 0; j < strlen(input2); j++) {
                if (input2[j] == input1[i]) {
                    letter_count2++;
                }
            }
            if (letter_count1 != letter_count2) {
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

int letter_count(char input1[256], char input2[256])
{

}
