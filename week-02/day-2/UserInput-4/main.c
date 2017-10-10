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

    printf("Input your name (gets): ");
    gets(name2);
    puts(name2);

    return;
}
