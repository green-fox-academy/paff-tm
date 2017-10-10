#include <stdio.h>

// differences between getch and getchar

int main() {
    char buffer[255] = "";   // Buffer variable for user input
    char buffer2[255] = "";
    int i = 0;

    printf("getch\nInput your name: ");
    do {
        buffer[i] = getch();
        printf("%c", buffer[i]);  //getch needs this to see what is typed
        i++;
    } while ((buffer[i-1] != '\r') && (i < 256));
    buffer[i - 1] = '\0';  // close the string

    printf("\nYour name is: %s", buffer);
    printf("\nLength of yout name is: %d", strlen(buffer));
//with getch I need to wait an \r value as enter
//backspace is stored in string;


    printf("\n\ngetchar\n");
    i = 0;
    printf("Input your name: ");
    do {
        buffer2[i] = getchar();
        printf("x");
        i++;
    } while ((buffer2[i-1] != '\n') && (i < 256));


    buffer2[i - 1] = '\0';  // close the string
    printf("\nYour name is: %s", buffer2);
    printf("\nLength of yout name is: %d", strlen(buffer2));
//with getchar I need to wait an \n value as enter
//backspace doesn't count it really deletes the character


    printf("\nYour name added with getch char-by-char (length: %d)", strlen(buffer));
    for (int j = 0; j < strlen(buffer); j++) {
        printf("%c", buffer[j]);
        getch();    // press any key to step over
    }

    printf("\nYour name added with getchar char-by-char (length: %d)", strlen(buffer2));
    for (int j = 0; j < strlen(buffer2); j++) {
        printf("%c", buffer2[j]);
        getch();    // press any key to step over
    }

    return 0;
}
