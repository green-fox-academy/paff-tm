/*               CLI CALCULATOR
 * ============================================
 * Greenfox Academy Pallida Cohort Static Class
 *               András Pásztor
*/

//TODO: error handling at < and log
//TODO: error handling of high numbers (overflow)
//TODO: handling subtraction from negative number

#include <stdio.h>

#define NUM_OF_OPS 14               //the numbers of the operators

#include "stringev.h"
#include "operations.h"
#include "screen.h"

int main()
{
    int op_id = -1;                 //the id of the operator, according to the operators string position
    char input_str[255] = "";       //the input string
    char operand_a[127] = "";       //raw input string of operand a
    char operand_b[127] = "";       //raw input string of operand b
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
