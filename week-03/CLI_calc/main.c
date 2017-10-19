#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <math.h>

#define NUM_OF_OPS 14

//TODO: division by remainder
//TODO: error handling at < and log
//TODO: error handling of high numbers (overflow)
//TODO: outsource the operatings into functions
//TODO: handle the spaces inside the operands
//TODO: handling subtraction from negative number

int get_operator(char input_str[], char operand_a[], char operand_b[], char operators[NUM_OF_OPS][6]);
int get_dec_values(char operand_a[], char operand_b[],  double *a, double *b);
int get_hexto_values(char operand_hex[], char operand_base[], double *hex, double *base);
int get_binto_values(char operand_bin[], char operand_base[], double *bin, double *base);
int get_decto_values(char operand_bin[], char operand_base[], double *bin, double *base);
void print_dec_result(double value);
void print_str_result(char value[]);

void clear_screen();
void print_help();
void set_cursor_pos(int x, int y);
short get_cursor_y();

int main()
{
    char input_str[255] = "";       //the input string
    char operators[NUM_OF_OPS][6] = //list of the operators
        {"help",    // 0
         "clear",   // 1
         "exit",    // 2
         "+",       // 3
         "*",       // 4
         "/",       // 5
         "%",       // 6
         "^",       // 7
         "<",       // 8
         "log",     // 9
         "binto",   // 10
         "hexto",   // 11
         "decto",   // 12
         "-"};      // 13 - subtraction must be the last one
    char operand_a[127] = "";       //raw input string of operand a
    char operand_b[127] = "";       //raw input string of operand b

    int op_id = -1;                 //the id of the operator, according to the operators string position

    double a = 0;                   //value of the first operand
    double b = 0;                   //value of the second operand
    double result = 0;              //value of the result
    char result_str[255] = "";      //string of the value for other base number systems

    print_help();
    while (op_id != 2) {    // while operator is not "exit"
        gets(input_str);

        // set the cursor position to the end of the input line
        set_cursor_pos(strlen(input_str) + 1, get_cursor_y() - 1);

        op_id = get_operator(input_str, operand_a, operand_b, operators);
        switch (op_id) {
            case -1:        // no operator, or operand is missing
                break;
            case 0:         // help
                print_help();
                break;
            case 1:         // clear
                clear_screen();
                break;
            case 2:         // exit
                break;
            case 3:         // +
                if (get_dec_values(operand_a, operand_b, &a, &b) == 0){
                    result = a + b;
                    print_dec_result(result);
                }
                break;
            case 4:         // *
                if (get_dec_values(operand_a, operand_b, &a, &b) == 0){
                    result = a * b;
                    print_dec_result(result);
                }
                break;
            case 5:         // /
                if (get_dec_values(operand_a, operand_b, &a, &b) == 0){
                    if (b == 0) {
                        result = a / b;
                        printf("--Mathematical problem: Division by zero.\n");
                    } else {
                        result = (int)(a / b);
                        print_dec_result(result);
                    }
                }
                break;
            case 6:         // %
                if (get_dec_values(operand_a, operand_b, &a, &b) == 0){
                    if (b == 0) {
                        printf("--Mathematical problem: Division by zero.\n");
                    } else {
                        result = a / b;
                        print_dec_result(result);
                    }
                }
                break;
            case 7:         // ^
                if (get_dec_values(operand_a, operand_b, &a, &b) == 0){
                    if (a < 0 && b != (int)b) {
                        printf("--Mathematical problem: base is negative and exponent is not integer.\n");
                    } else if ((a = 0) && (b < 0)){
                        printf("--Mathematical problem: result is infinitive.\n");
                    } else {
                        result = pow(a, b);
                        print_dec_result(result);
                    }
                }
                break;
            case 8:         // <
                if (get_dec_values(operand_a, operand_b, &a, &b) == 0){
                    result = pow(a, 1 / b);
                    print_dec_result(result);
                }
                break;
            case 9:         // log
                if (get_dec_values(operand_a, operand_b, &a, &b) == 0){
                    if (log(a) == 0) {
                        printf("error.\n");
                    } else {
                        result = log(b) / log(a);
                    }
                    print_dec_result(result);
                }
                break;
            case 10:        // binto
                if (get_binto_values(operand_a, operand_b, &a, &b) == 0){
                    ltoa((long int)a, result_str, (int)b);
                    print_str_result(result_str);
                }
                break;
            case 11:        // hexto
                if (get_hexto_values(operand_a, operand_b, &a, &b) == 0){
                    ltoa((long int)a, result_str, (int)b);
                    print_str_result(result_str);
                }
                break;
            case 12:        // decto
                if (get_decto_values(operand_a, operand_b, &a, &b) == 0){
                    ltoa((long int)a, result_str, (int)b);
                    print_str_result(result_str);
                }
                break;
            case 13:        // -
                if (get_dec_values(operand_a, operand_b, &a, &b) == 0){
                    result = a - b;
                    print_dec_result(result);
                }
                break;
            default:        // ?
                break;
        }
    }
    return 0;
}

/*  Gives back the id of the operator, and also separates the input string to operand_a and operand_b.
 *  If no operator was found or operand is missing then returns -1.
 */
int get_operator(char input_str[], char operand_a[], char operand_b[], char operators[NUM_OF_OPS][6])
{
    int op_id = -1;             //id of the operator. If there is no operator found, then it will be -1
    char *ptr = NULL;           //pointer to the first character of operator

    operand_a[0] = '\0';        //reset operand_a string
    operand_b[0] = '\0';        //reset operand_b string

    for (int i = 0; i < NUM_OF_OPS; i++) {
        ptr = strstr(input_str, operators[i]);
        if (ptr != NULL) {      //if an operator was found
            op_id = i;

            if (op_id > 2) {    //if the operator is not a command

                // get operand_a (characters before the operator)
                strncpy(operand_a, input_str, ptr - input_str);
                operand_a[ptr - input_str] = '\0';
                if (strlen(operand_a) == 0) {
                    printf("--Input error: first operand is missing.\n");
                    op_id = -1;
                }

                // get operand_b (characters after the operator)
                strcpy(operand_b, ptr + strlen(operators[op_id]));
                if (strlen(operand_b) == 0) {
                    printf("--Input error: second operand is missing.\n");
                    op_id = -1;
                }
            }
            break;
        }
    }

    if (ptr == NULL) {          // if no operator was found
        printf("--Input error: No operator. For help type 'help' and press enter.\n");
    }

    return op_id;
}

/*  Get the decimal float values of operand_a and operand_b. If both are decimal float value,
 *  then returns 0, if not returns -1. Prints error message if there is an error.
 */
 //TODO: handle the spaces in the operands
int get_dec_values(char operand_a[], char operand_b[],  double *a, double *b)
{
    char decimal_values[] = "0123456789-. ";
    //*a = 0.0;
    //*b = 0.0;

    //check if operand_a is a decimal number
    if (strspn(operand_a, decimal_values) != strlen(operand_a)) {
        printf("--Input error: first operand is not a decimal number.\n");
        return -1;
    }

    //check if operand_b is a decimal number
    if (strspn(operand_b, decimal_values) != strlen(operand_b)) {
        printf("--Input error: second operand is not a decimal number.\n");
        return -1;
    }

    // if there is no error, then set the values;
    *a = atof(operand_a);
    *b = atof(operand_b);
    return 0;

}

/* Check if the operand_a is a hexadecimal number and operand_b is a suitable base. If so, than gives back
 * the values in decimal. If both are correct returns 0, if not returns -1. Prints error message if there is an error.
 */
 //TODO: handle the spaces in the operands
int get_hexto_values(char operand_hex[], char operand_base[],  double *hex, double *base)
{
    char hexadecimal_values[] = "0123456789abcdefABCDEF ";
    char *ptr = NULL;

    //*hex = 0;
    //*base = 0;

    //check if operand_hex is a hexadecimal number
    if (strspn(operand_hex, hexadecimal_values) != strlen(operand_hex)) {
        printf("--Input error: first operand is not a hexadecimal number.\n");
        return -1;
    }

    //check if base is a number between 2 and 36
    *base = strtol(operand_base, &ptr, 10);
    if ((*base < 2) || (*base > 36)) {
        printf("--Input error: base should be between 2 and 36.\n");
        return -1;
    }

    *hex = strtol(operand_hex, &ptr, 16);

    return 0;
}

/* Check if the operand_a is a binary number and operand_b is a suitable base. If so, than gives back
 * the values in decimal. If both are correct returns 0, if not returns -1. Prints error message if there is an error.
 */
 //TODO: handle the spaces in the operands
int get_binto_values(char operand_bin[], char operand_base[], double *bin, double *base)
{
    char binary_values[] = "01 ";
    char *ptr = NULL;

    //*bin = 0;
    //*base = 0;

    //check if operand_bin is a binary number
    if (strspn(operand_bin, binary_values) != strlen(operand_bin)) {
        printf("--Input error: first operand is not a binary number.\n");
        return -1;
    }

    //check if base is a number between 2 and 36
    *base = strtol(operand_base, &ptr, 10);
    if ((*base < 2) || (*base > 36)) {
        printf("--Input error: base should be between 2 and 36.\n");
        return -1;
    }

    *bin = strtol(operand_bin, &ptr, 2);

    return 0;
}

/* Check if the operand_a is an unsigned integer number and operand_b is a suitable base. If so, than gives back
 * the values in decimal. If both are correct returns 0, if not returns -1. Prints error message if there is an error.
 */
 //TODO: handle the spaces in the operands
int get_decto_values(char operand_dec[], char operand_base[], double *dec, double *base)
{
    char decimal_values[] = "0123456789 ";
    char *ptr = NULL;

    //*dec = 0;
    //*base = 0;

    //check if operand_bin is a binary number
    if (strspn(operand_dec, decimal_values) != strlen(operand_dec)) {
        printf("--Input error: first operand is not an unsigned integer number.\n");
        return -1;
    }

    //check if base is a number between 2 and 36
    *base = strtol(operand_base, &ptr, 10);
    if ((*base < 2) || (*base > 36)) {
        printf("--Input error: base should be between 2 and 36.\n");
        return -1;
    }

    *dec = strtol(operand_dec, &ptr, 10);

    return 0;
}


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
 *
 */
void print_help()
{
    clear_screen();

    printf("    	CLI Calculator \n"
           "==================================== \n"
           "usage: [number] [operation] [number] \n"
           "Commands: \n"
           " \n"
           " +	summation \n"
           " -	subtraction \n"
           " *	multiplication \n"
           " /	division \n"
           " %	division with remainder \n"
           " ^	squaring \n"
           " <	square root \n"
           " log	logarithm \n"
           " binto	binary to hex or dec \n"
           " hexto	hexadecimal to bin or dec \n"
           " decto	decimal to bin or hex \n"
           " =================================== \n"
           " exit	exiting from the program \n"
           " clear	clear the screen \n"
           " help	print usage \n"
           " =================================== \n"
           " Hit enter to start! \n"
           " =================================== \n");

    getchar();
    fflush(stdin);
    clear_screen();
}

COORD coord = {0,0};
void set_cursor_pos(int x, int y)
{
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

short get_cursor_y()
{
    CONSOLE_SCREEN_BUFFER_INFO csbi;

    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);

    //*x = csbi.dwCursorPosition.X;
    return csbi.dwCursorPosition.Y;
}

