#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void search_palind(char input[], char output[]);

int main()
{
    char str_input[128] = "";
    char str_palind[256] = "";

    printf("Search palindroms in the given string.\n");
    printf("Input the string: ");
    gets(str_input);

    search_palind(str_input, str_palind);
    printf("Here are the palindroms in your input: %s", str_palind);

    return 0;
}

void search_palind(char input[], char output[])
{
    char palind[256];
    char temp[256] = "";
    int l = 0; //l as length of the polidrome counted from central of the polindrome
    int t = 0;

    for (int c = 1; c < strlen(input) - 1; c++) { //c as central position of palindrome
        l = 0;
        while ((l <= c) && (l < strlen(input) - c) && (input[c - l] == input[c + l])) {
            l++;
        }
        l--;
        if (l > 0) {
            //copy the polidrome to the output sting
            if (strlen(output) > 0)
                strcat(output, ", \"");
            else
                strcat(output, "\"");
            t = 0;
            for (int i = c - l; i <= c + l; i++) {
                temp[t] = input[i];
                t++;
            }
            temp[t] = '\0';
            strcat(output, temp);
            strcat(output, "\"");
        }
    }

    return;
}
