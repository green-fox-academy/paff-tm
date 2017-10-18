#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

#define NUM_OF_OPS 14

int get_operator(char input_str[], char operand_a[], char operand_b[], char operators[NUM_OF_OPS][6]);
int get_dec_values(char operand_a[], char operand_b[],  float *a, float *b);
void print_dec_result(float value);
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

    float a = 0;                //value of the first operand
    float b = 0;                //value of the second operand
    float result = 0;           //value of the result

    char a_str[127] = "";       //string of the first operand for other base number systems
    char result_str[127] = "";  //string of the value for other base number systems

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

                result = a - b;
                print_dec_result(result);
                break;
            case 5:     // *

                result = a * b;
                print_dec_result(result);
                break;
            case 6:     // /

                result = a / b;
                print_dec_result(result);
                break;
            case 7:     // %

                //result = a % b;
                print_dec_result(result);
                break;
            case 8:     // ^
                printf("%d, %d, %d", a, b, op_id);
                break;
            case 9:     // <
                ;
                break;
            case 10:     //  log

                break;
            case 11:     //  binto

                break;
            case 12:     // hexto
                printf("%d, %d, %d", a, b, op_id);
                break;
            case 13:     // decto
                printf("%d, %d, %d", a, b, op_id);
                break;
            default:     // ?
                break;
            }
    }
    return 0;
}

/*  Get the decimal float value of operand_str. If it is a decimal float value,
 *  then returns 0, if not returns -1.
 */
int get_dec_values(char operand_a[], char operand_b[],  float *a, float *b)
{
    int is_number = 1;  //1 if the operand is a decimal number, 0 if it contains other characters
    *a = 0.0;
    *b = 0.0;

    //check if operand_a is a decimal number
    for (int i = 0; i < strlen(operand_a); i++){
        if ((operand_a[i] < '0' || operand_a[i] > '9') && operand_a[i] != '-' && operand_a[i] != '.' && operand_a[i] != ' ') {
            is_number = 0;
            break;
        }
    }
    if (is_number == 0) {
        printf(" Input error: first operand is not a decimal number.\n");
        return -1;
    } else {

        //check if operand_b is a decimal number
        is_number = 1;
        for (int i = 0; i < strlen(operand_b); i++){
            if ((operand_b[i] < '0' || operand_b[i] > '9') && operand_b[i] != '-' && operand_b[i] != '.' && operand_a[i] != ' ') {
                is_number = 0;
                break;
            }
        }
        if (is_number == 0) {
            printf(" Input error: second operand is not a decimal number.\n");
            return -1;
        } else {
            // if there is no error, then set the values;
            *a = atof(operand_a);
            *b = atof(operand_b);
            return 0;
        }
    }
}

/*  Prints out the result of the decimal operate to the end of the input line
 */
//TODO: positioning the output
void print_dec_result(float value)
{
    printf(" %f\n", value);
}

/*  Prints out the result as a string to the end of the input line
 */
//TODO: positioning the output
void print_str_result(char value[])
{
    puts(value);
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

/*  Clears the screen.
 *
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

