#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int search_palind(char input[], char output[]);

int main()
{
    char str_input[128] = "";   // input sting
    char str_palind[256] = "";  // list if the palindromes

    printf("Search palindroms in the given string.\n");
    printf("Input the string: ");
    gets(str_input);

    if (search_palind(str_input, str_palind) == 0) {
        printf("Here are the palindroms in your input: %s", str_palind);
    } else {
        printf("Your given string is too short");
    }

    return 0;
}

/*  Search the palindromes in the input string, and gives back them in output string
 *  Return 1 if the input is too short (less than 3 characters), else return 0;
 */
int search_palind(char input[], char output[])
{
    int pal_len = 0;    // length of the palindrome counted from central of the palindrome
    int pal_cen = 0;    // central position of palindrome in the input string
    int even = 0;       // if it is true, than the palindrome has even characters
    char temp[256] = "";// temp string for palindrome
    int t = 0;          // temp for 'temp' string

    // initialize the beginning of output
    output[0] = '[';
    output[1] = '\0';

    if (strlen(input) < 3) {
        return 1;
    }
    for (pal_cen = 1; pal_cen < strlen(input) - 1; pal_cen++) {
        // check the length of the palindrome at the pal_cen position
        // if pal_len == 0 then there is no palindrome at that position
        // first check palindromes with odd characters
        even = 0;
        pal_len = 0;
        while ((pal_len < pal_cen) && ((pal_len + 1) < (strlen(input) - pal_cen)) && (input[pal_cen - pal_len - 1] == input[pal_cen + pal_len + 1])) {
            pal_len++;
        }
        // if there was no palindrome with odd characters,
        // then check if there are the same characters in the middle -> even characters in the word
        if (pal_len == 0) {
            if (input[pal_cen] == input[pal_cen + 1])
                even = 1;
            // check again the palindrome with even characters
            while ((pal_len < pal_cen) && ((pal_len + 1 + even) < (strlen(input) - pal_cen)) && (input[pal_cen - pal_len - 1] == input[pal_cen + pal_len + 1 + even])) {
                pal_len++;
            }
        }

        //copy the palindrome to the output sting, if there is a palindrome (if pal_len = 0 there is no palindrome)
        while (pal_len > 0) {
            // add the opening " before the palindrome, and a ',' if it is not the first
            if (strlen(output) > 1)
                strcat(output, ", ");
            strcat(output, "\"");

            // copy the palindrome to temp string
            t = 0;
            for (int i = pal_cen - pal_len; i <= pal_cen + pal_len + even; i++) {
                temp[t] = input[i];
                t++;
            }
            temp[t] = '\0';

            //copy the temp string to output string
            strcat(output, temp);
            // add the closing " to output
            strcat(output, "\"");
            // at a longer palindrome, there are more, (shorter) palindromes in it, so at the next round add a shorter one to output
            pal_len--;
        }
    }
    // add the closing ']' to output
    strcat(output, "]");

    return 0;
}