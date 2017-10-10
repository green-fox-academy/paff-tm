#include <stdio.h>
#include <string.h>

void func ();

int main()
{
    //write a void function which asks for a number with scanf and print it out with printf, then
    //asks for a name with gets, and print it out with puts
    //you will notice something is wrong
    //try to solve the problem

    func();

    return 0;
}

void func() {
    char name[255];
    char name2[255];
    printf("Input your name (scanf): ");
    scanf("%s", name);

    printf("%s\n", name);
    // print name char-by-char
    for (int i = 0; i <= strlen(name); i++)
        printf("\n%c\t%d\n", name[i], name[i]);

    gets(name2); // read stdin;
    // print name2 char-by-char
    printf("\nname2:\n");
    for (int i = 0; i <= strlen(name2); i++)
        printf("\n%c\t%d\n", name2[i], name2[i]);

    printf("Input your name (gets): ");

    gets(name2);
    puts(name2);

    return;
}
