#include <stdio.h>
#include <stdlib.h>

int main()
{
    char input1[256];
    char input2[256];
    int is_anagram = 1;
    int letter_is = 0;

    printf("Check if the two given words are anagram.\n");
    printf("Add the first word: ");
    gets(input1);
    printf("Add the second word: ");
    gets(input2);

    if (strlen(input1) == strlen(input2)) {
        for (int i = 0; i < strlen(input1); i++){
            letter_is = 0;
            for (int j = 0; j < strlen(input2); j++) {
                if (input1[i] == input2[j]) {
                    letter_is = 1;
                    break;
                }
            }
            if (letter_is == 0) {
                is_anagram = 0;
                break;
            }
        }
    }

    if (is_anagram)
        printf("These are anagrams!\n");
    else
        printf("These are not anagrams!\n");

    return 0;
}
