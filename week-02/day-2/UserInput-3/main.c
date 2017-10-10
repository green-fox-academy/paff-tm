#include <stdio.h>

int char_to_ascii();

int main()
{
    //as you know, a character is represented as a numeric value(ASCII value) in the memory
    //write a function which asks for one charcter and prints out the character in character format then in ASCII too
    printf("Type in one character then press enter: ");

    char_to_ascii();

    return 0;
}

int char_to_ascii(){
    char x = getch();
    printf("%c, %d", x, x);
}
