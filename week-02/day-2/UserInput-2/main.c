#include <stdio.h>

int main() {
    char buffer[255];   // Buffer variable for user input

    //TODO:
    // Get the user's name with gets
    printf("Input your name: ");
    gets(buffer);

    //TODO:
    // Print it out with puts
    printf("Your name is: ");
    puts(buffer);

    //TODO:
    // Get the user's pet name with getch
    printf("Input your name: ");
    int i = 0;
    do {
        buffer[i] = getchar();
        i++;
    } while ((buffer[i-1] != '\n') && (i < 256));
    buffer[i - 1] = '\0';
    //TODO:
    // Print it out
    printf("Your name is: %s", buffer);

    return 0;
}
