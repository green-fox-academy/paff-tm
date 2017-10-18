#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <math.h>

#define NUM_OF_OPS 14

//TODO: handling negative numbers; - operator and - sign is the same...
//

int get_operator(char input_str[], char operand_a[], char operand_b[], char operators[NUM_OF_OPS][6]);
int get_dec_values(char operand_a[], char operand_b[],  double *a, double *b);
int get_hex_values(char operand_hex[], char operand_base[], double *hex, double *base);
void print_dec_result(double value);
void print_str_result(char value[]);

void clear_screen();
void print_help();
void set_cursor_pos(int x, int y);

int main()
{
    char input_str[255] = "";   //the input string
    char operators[NUM_OF_OPS][6] = {"exit", "clear", "help", "+", "-", "*", "/", "%", "^", "<", "log", "binto", "hexto", "decto"};  //list of the operators
    char operand_a[127] = "";   //raw input string of operand a
    char operand_b[127] = "";   //raw input string of operand b

    int op_id = -1;             //the id of the operator, according to the operators string

    double a = 0;               //value of the first operand
    double b = 0;               //value of the second operand
    double result = 0;          //value of the result

    char a_str[127] = "";       //string of the first operand for other base number systems
    char result_str[255] = "";  //string of the value for other base number systems

    print_help();
    while (op_id != 0) {
        gets(input_str);
        op_id = get_operator(input_str, operand_a, operand_b, operators);
        switch (op_id) {
            case -1:    // no operator
                printf(" Input error: No operator. For help type 'help' and press enter.\n");
                break;
            case 0:     // exit
                break;
            case 1:     // clear
                clear_screen();
                break;
            case 2:     // help
                print_help();
                break;
            case 3:     // +
                if (get_dec_values(operand_a, operand_b, &a, &b) == 0){
                    result = a + b;
                    print_dec_result(result);
                }
                break;
            case 4:     // -
                if (get_dec_values(operand_a, operand_b, &a, &b) == 0){
                    result = a - b;
                    print_dec_result(result);
                }
                break;
            case 5:     // *
                if (get_dec_values(operand_a, operand_b, &a, &b) == 0){
                    result = a * b;
                    print_dec_result(result);
                }
                break;
            case 6:     // /
                if (get_dec_values(operand_a, operand_b, &a, &b) == 0){
                    result = (int)(a / b);
                    print_dec_result(result);
                }
                break;
            case 7:     // %
                if (get_dec_values(operand_a, operand_b, &a, &b) == 0){
                    result = a / b;
                    print_dec_result(result);
                }
                break;
            case 8:     // ^
                if (get_dec_values(operand_a, operand_b, &a, &b) == 0){
                    result = pow(a, b);
                    print_dec_result(result);
                }
                break;
            case 9:     // <
                if (get_dec_values(operand_a, operand_b, &a, &b) == 0){
                    result = pow(a, 1 / b);
                    print_dec_result(result);
                }
                break;
            case 10:     //  log
                if (get_dec_values(operand_a, operand_b, &a, &b) == 0){
                    result = log(b) / log(a);
                    print_dec_result(result);
                }
                break;
            case 11:     // binto

                break;
            case 12:     // hexto
                if (get_hex_values(operand_a, operand_b, &a, &b) == 0){
                    ltoa((long int)a, result_str, (int)b);
                    print_str_result(result_str);
                }
                break;
            case 13:     // decto

                break;
            default:     // ?
                break;
        }
    }
    return 0;
}

/*  Gives back the id of the operator, and also separates the input string to operand_a and operand_b.
 *  If no operator was found then returns -1.
 */
int get_operator(char input_str[], char operand_a[], char operand_b[], char operators[NUM_OF_OPS][6])
{
    int op_id = -1;         //id of the operator. If there is no operator found, then it will be -1
    char *ptr = NULL;       //pointer to the first character of operator

    operand_a[0] = '\0';    //reset operand_a string
    operand_b[0] = '\0';    //reset operand_b string

    for (int i = 0; i < NUM_OF_OPS; i++) {
        ptr = strstr(input_str, operators[i]);
        if (ptr != NULL) {  //if an operator was found
            op_id = i;

            // get operand_a (characters before the operator)
            strncpy(operand_a, input_str, ptr - input_str);
            operand_a[ptr - input_str] = '\0';

            // get operand_b (characters after the operator)
            strcpy(operand_b, ptr + strlen(operators[op_id]));
            break;
        }
    }
    return op_id;
}

/*  Get the decimal float values of operand_a and operand_b. If both are decimal float value,
 *  then returns 0, if not returns -1. Prints error message if there is an error.
 */
 //TODO: handle the spaces in the operands
int get_dec_values(char operand_a[], char operand_b[],  double *a, double *b)
{
    *a = 0.0;
    *b = 0.0;

    //check if operand_a is a decimal number
    if (strlen(operand_a) > 0) {
        for (int i = 0; i < strlen(operand_a); i++){
            if ((operand_a[i] < '0' || operand_a[i] > '9') && operand_a[i] != '-' && operand_a[i] != '.' && operand_a[i] != ' ') {
                printf(" Input error: first operand is not a decimal number.\n");
                return -1;
            }
        }
    } else {
        printf(" Input error: first operand is missing.\n");
        return -1;
    }

    //check if operand_b is a decimal number
    if (strlen(operand_b) > 0) {
        for (int i = 0; i < strlen(operand_b); i++){
            if ((operand_b[i] < '0' || operand_b[i] > '9') && operand_b[i] != '-' && operand_b[i] != '.' && operand_b[i] != ' ') {
                printf(" Input error: second operand is not a decimal number.\n");
                return -1;
            }
        }
    } else {
        printf(" Input error: second operand is missing.\n");
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
int get_hex_values(char operand_hex[], char operand_base[],  double *hex, double *base)
{
    char *ptr = NULL;

    //check if operand_hex is a hexadecimal number
    if (strlen(operand_hex) > 0) {
        for (int i = 0; i < strlen(operand_hex); i++){
            if ((operand_hex[i] < '0' || operand_hex[i] > '9') && (operand_hex[i] < 'a' || operand_hex[i] > 'f') && (operand_hex[i] < 'A' || operand_hex[i] > 'F') && operand_hex[i] != ' ') {
                printf(" Input error: first operand is not a hexadecimal number.\n");
                return -1;
            }
        }
        *hex = strtol(operand_hex, &ptr, 16);
    } else {
        printf(" Input error: first operand is missing.\n");
        return -1;
    }


    //check if base is a number between 2 and 36

    *base = strtol(operand_base, &ptr, 10);
    if (ptr == operand_base) {
        printf(" Input error: base is not a number.\n");
        return -1;
    } else {
        if ((*base < 2) || (*base > 36)) {
            printf(" Input error: base should be between 2 and 36.\n");
            return -1;
        }
    }
    return 0;
}

/*  Prints out the result of the decimal operate to the end of the input line
 */
//TODO: positioning the output
void print_dec_result(double value)
{
    printf(" = %g\n", value);
}

/*  Prints out the result as a string to the end of the input line
 */
//TODO: positioning the output
void print_str_result(char value[])
{
    printf(" = %s\n", value);
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

    printf("    	CLI Calculator \n");
    printf("==================================== \n");
    printf("usage: [number] [operation] [number] \n");
    printf("Commands: \n");
    printf(" \n");
    printf(" +	summation \n");
    printf(" -	subtraction \n");
    printf(" *	multiplication \n");
    printf(" /	division \n");
    printf(" %	division with remainder \n");
    printf(" ^	squaring \n");
    printf(" <	square root \n");
    printf(" log	logarithm \n");
    printf(" binto	binary to hex or dec \n");
    printf(" hexto	hexadecimal to bin or dec \n");
    printf(" decto	decimal to bin or hex \n");
    printf(" ==================================== \n");
    printf(" exit	exiting from the program \n");
    printf(" clear	clear the screen \n");
    printf(" help	print usage \n");
    printf(" ==================================== \n");
    printf(" Hit enter to start! \n");
    printf(" ==================================== \n");

    getchar();
    fflush(stdin);
}


COORD coord = {0,0};
void set_cursor_pos(int x, int y)
{
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

