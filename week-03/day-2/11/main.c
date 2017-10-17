#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void print_help();

int main()
{
	char command[256] = "";
	char cmds[5][10] = {"register", "login", "logout", "h", "x"};
    char logged_in = 0;
    char registered = 0;

    //TODO: write a register-login-logout program
    //if you type in register print out "Registration..." or "You are already registered." if you are registered.
	//you are able to log in, if you are already registered, otherwise not. In that case print out "You are not registered.".
    //if you type in login print out "Logging in..." or "Already logged in." if are logged in.
    //if you type in logout print out "Logging out..." or "Already logged out." if are logged out.

    while (1) {
        printf("Type a command: ");
        scanf("%s", command);
        fflush(stdin);
        if (strcmp(command, cmds[0]) == 0) {        // register
            system("cls");
            if (registered) {
                printf("You're already registered.\n");
            } else {
                printf("Registration...\n");
                registered = 1;
            }

        } else if (strcmp(command, cmds[1]) == 0) { // login
            system("cls");
            if (registered) {
                if (logged_in) {
                    printf("Already logged in.\n");
                } else {
                    printf("Logging in...\n");
                    logged_in = 1;
                }
            } else {
                printf("You are not registered.\n");
            }

        } else if (strcmp(command, cmds[2]) == 0) { // logout
            system("cls");
            if (logged_in) {
                printf("Logging out...\n");
                logged_in = 0;
            } else {
                printf("Already logged out.\n");
            }

        } else if (strcmp(command, cmds[3]) == 0) { // help
            print_help();

        } else if (strcmp(command, cmds[4]) == 0) { // exit
            break;

        } else {
            printf("Wrong command. For help, write \"h\"\n");
        }
    }
}

void print_help()
{
    system("cls");
    printf("Available commands:\n\n");
    printf("register\tregister\n");
    printf("login\t\tlogging in\n");
    printf("logout\t\tlogging out\n");
    printf("x\t\texit\n");
    printf("h\t\thelp\n");
    printf("\n");
}

