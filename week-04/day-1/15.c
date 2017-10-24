#include <stdio.h>

void reverse_name(char *name, char *reversed_name);

int main(void)
{
	char name[] = "Gipsz Jakab";
    char reversed[50] = "";

    //write a function which reverse a name's last name and first name. Use a void function. Put your 'return' value in the second parameter.

    reverse_name(name, reversed);
    printf("\"%s\"", reversed);
}

void reverse_name(char *name, char *reversed_name)
{
    char *p_space = name;

    // find the space in string name, and point to it
    while (*p_space != ' ') {
        p_space++;
    }

    //add the chars to dest after the space
    int i = 0;
    while (name[i + (p_space - name) + 1] != '\0') {
        reversed_name[i] = name[i + (p_space - name) + 1];
        i++;
    }

    //add the space to dest
    reversed_name[i++] = ' ';

    //add the chars to dest until the space
    while (name[i - (p_space - name) - 1] != ' ') {
        reversed_name[i] = name[i - (p_space - name) - 1];
        i++;
    }

    reversed_name[i] = '\0';
}
