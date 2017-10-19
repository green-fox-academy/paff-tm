#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <math.h>

#define NUM_OF_OPS 14

#include "stringev.h"
#include "operations.h"
#include "screen.h"

//TODO: division by remainder
//TODO: error handling at < and log
//TODO: error handling of high numbers (overflow)
//TODO: handle the spaces inside the operands
//TODO: handling subtraction from negative number

/* into stringev.h
int get_operator(char input_str[], char operand_a[], char operand_b[], char operators[NUM_OF_OPS][6]);
int get_dec_values(char operand_a[], char operand_b[],  double *a, double *b);
int get_hexto_values(char operand_hex[], char operand_base[], double *hex, double *base);
int get_binto_values(char operand_bin[], char operand_base[], double *bin, double *base);
int get_decto_values(char operand_bin[], char operand_base[], double *bin, double *base);
*/

/* into operations.h
void operation_addition(char operand_a[], char operand_b[]);
void operation_subtraction(char operand_a[], char operand_b[]);
void operation_multiplicatin(char operand_a[], char operand_b[]);
void operation_division(char operand_a[], char operand_b[]);
void operation_modulo(char operand_a[], char operand_b[]);
void operation_exponentiation(char operand_a[], char operand_b[]);
void operation_rooting(char operand_a[], char operand_b[]);
void operation_log(char operand_a[], char operand_b[]);
void operation_binto(char operand_a[], char operand_b[]);
void operation_hexto(char operand_a[], char operand_b[]);
void operation_decto(char operand_a[], char operand_b[]);
*/

/* into screen.h
void print_dec_result(double value);
void print_str_result(char value[]);
void clear_screen();
void print_help();
void set_cursor_pos(int x, int y);
short get_cursor_y();
*/

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

/*  unused due to outsourcing of the operation functions
    double a = 0;                   //value of the first operand
    double b = 0;                   //value of the second operand
    double result = 0;              //value of the result
    char result_str[255] = "";      //string of the value for other base number systems
*/

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
                operation_addition(operand_a, operand_b);
                break;
            case 4:         // *
                operation_multiplicatin(operand_a, operand_b);
                break;
            case 5:         // /
                operation_division(operand_a, operand_b);
                break;
            case 6:         // %
                operation_modulo(operand_a, operand_b);
                break;
            case 7:         // ^
                operation_exponentiation(operand_a, operand_b);
                break;
            case 8:         // <
                operation_rooting(operand_a, operand_b);
                break;
            case 9:         // log
                operation_log(operand_a, operand_b);
                break;
            case 10:        // binto
                operation_binto(operand_a, operand_b);
                break;
            case 11:        // hexto
                operation_hexto(operand_a, operand_b);
                break;
            case 12:        // decto
                operation_decto(operand_a, operand_b);
                break;
            case 13:        // -
                operation_subtraction(operand_a, operand_b);
                break;
            default:        // ?
                break;
        }
    }
    return 0;
}
