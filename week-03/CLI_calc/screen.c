/*  C FILE FOR CLI CALCULATOR
 *  Contains the functions of printing
 *  ==================================
 */

#include <stdio.h>
#include <windows.h>

/*  Prints out the result of the decimal operate to the end of the input line
 */
void print_dec_result(double value)
{
    printf("= %g\n", value);
}

/*  Prints out the result as a string to the end of the input line
 */
void print_str_result(char value[])
{
    printf("= %s\n", value);
}

/*  Clears the screen.
 */
void clear_screen()
{
    system("cls");
}

/*  Clears the screen and prints out the help.
 */
void print_help()
{
    clear_screen();

    printf("    	      CLI Calculator \n"
           "========================================== \n"
           "usage: [number] [operation] [number] \n"
           "Commands: \n"
           " \n"
           " +	addition \n"
           " -	subtraction \n"
           " *	multiplication \n"
           " /	division \n"
           " %	modulus \n"
           " ^	exponentiation \n"
           " <	x < y: x base root of y \n"
           " log	x log y: x base logarithm of y \n"
           " binto	binary to other number system \n"
           " hexto	hexadecimal to other number system \n"
           " decto	decimal to other number system \n"
           " ========================================= \n"
           " exit	exiting from the program \n"
           " clear	clear the screen \n"
           " help	print usage \n"
           " ========================================= \n"
           " Hit enter to start! \n"
           " ========================================= \n");

    getchar();
    fflush(stdin);
    clear_screen();
}

/*  Set the cursor position to the position x-y.
 */
COORD coord = {0,0};
void set_cursor_pos(int x, int y)
{
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

/*  Returns the actual x value of the cursor position.
 */
short get_cursor_y()
{
    CONSOLE_SCREEN_BUFFER_INFO csbi;

    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);

    return csbi.dwCursorPosition.Y;
}
