/*  C FILE FOR MULTI-OPERATOR CLI CALCULATOR
 *  Contains the functions of operations
 *  ========================================
 */

#include <stdio.h>
#include <string.h>
#include <math.h>

#include "stringev.h"

/*  Return 0 if OK. If there is an error, return -1.
 *
 */
int calculate(char input_str[], double *result)
{
    int op_id = -1;                 //the id of the operator, according to the operators string position
    char operand_a[50] = "";        //input string of operand a
    char operand_b[50] = "";        //input string of operand b
    //double temp_result = 0;         // the result of the calculation

    op_id = get_operator(input_str, operand_a, operand_b);

    switch (op_id) {
        case -1:
            if (get_value(input_str, result) == 0) {
                return 0;
            } else {
                return -1;
            }
        case 0:         // +
            if (operation_addition(operand_a, operand_b, result) == 0) {
                return 0;
            } else {
                return -1;
            }
        case 1:         // *
            if (operation_multiplication(operand_a, operand_b, result) == 0) {
                return 0;
            } else {
                return -1;
            }
        case 2:         // /
            if (operation_division(operand_a, operand_b, result) == 0) {
                return 0;
            } else {
                return -1;
            }
/*
        case 3:         // %
            if (operation_modulo(operand_a, operand_b, result) == 0) {
                return 0;
            } else {
                return -1;
            }

        case 4:         // ^
            if (operation_exponentiation(operand_a, operand_b, result) == 0) {
                return 0;
            } else {
                return -1;
            }
        case 5:         // <
            if (operation_rooting(operand_a, operand_b, result) == 0) {
                return 0;
            } else {
                return -1;
            }
        case 6:         // log
            if (operation_log(operand_a, operand_b, result) == 0) {
                return 0;
            } else {
                return -1;
            }
*/
        case 3:        // -
            if (operation_subtraction(operand_a, operand_b, result) == 0) {
                return 0;
            } else {
                return -1;
            }
        default:        // ?
            return -1;
        }
}

int operation_addition(char operand_a[], char operand_b[], double *result)
{
    double a, b;

    if (calculate(operand_a, &a) == 0) {
        if (calculate(operand_b, &b) == 0) {
            *result = (a + b);
            return 0;
        }
    } else {
        return -1;
    }
}

int operation_subtraction(char operand_a[], char operand_b[], double *result)
{
    double a, b;

    if (calculate(operand_a, &a) == 0) {
        if (calculate(operand_b, &b) == 0) {
            *result = (a - b);
            return 0;
        }
    } else {
        return -1;
    }
}

int operation_multiplication(char operand_a[], char operand_b[], double *result)
{
    double a, b;

    if (calculate(operand_a, &a) == 0) {
        if (calculate(operand_b, &b) == 0) {
            *result = (a * b);
            return 0;
        }
    } else {
        return -1;
    }
}

int operation_division(char operand_a[], char operand_b[], double *result)
{
    double a, b;

    if (calculate(operand_a, &a) == 0) {
        if (calculate(operand_b, &b) == 0) {
            if (b == 0) {
                printf("--Mathematical problem: Division by zero.\n");
                return -1;
            } else {
                *result = trunc(a / b);
                return 0;
            }
        }
    } else {
        return -1;
    }
}

int operation_modulo(char operand_a[], char operand_b[], double *result)
{
    double a, b;

    if (calculate(operand_a, &a) == 0) {
        if (calculate(operand_b, &b) == 0) {
            if (b == 0) {
                printf("--Mathematical problem: Division by zero.\n");
                return -1;
            } else {
                *result = fmod(a, b);
                return 0;
            }
        }
    } else {
        return -1;
    }
}

int operation_exponentiation(char operand_a[], char operand_b[], double *result)
{
    double a, b;

    if (calculate(operand_a, &a) == 0) {
        if (calculate(operand_b, &b) == 0) {
            if ((a < 0) && (b != (int)b)) {
                printf("--Mathematical problem: base is negative and exponent is not integer.\n");
                return -1;
            } else if ((a == 0) && (b < 0)){
                printf("--Mathematical problem: result is infinitive.\n");
                return -1;
            } else {
                *result = pow(a, b);
                return 0;
            }
        }
    } else {
        return -1;
    }
}

int operation_rooting(char operand_a[], char operand_b[], double *result)
{
    double a, b;

    if (calculate(operand_a, &a) == 0) {
        if (calculate(operand_b, &b) == 0) {
            if (b < 0) {
                printf("--Mathematical problem: root of a negative number.\n");
                return -1;
            } else if (a == 0) {
                printf("--Mathematical problem: root base is zero.\n");
                return -1;
            } else {
                *result = pow(b, 1 / a);
                return 0;
            }
        }
    } else {
        return -1;
    }
}

int operation_log(char operand_a[], char operand_b[], double *result)
{
    double a, b;

    if (calculate(operand_a, &a) == 0) {
        if (calculate(operand_b, &b) == 0) {
            if (a == 0) {
                printf("--Mathematical problem: 0 base logarithm.\n");
                return -1;
            } else if (a == 1){
                printf("--Mathematical problem: 1 base logarithm.\n");
                return -1;
            } else if (a < 0){
                printf("--Mathematical problem: negative base logarithm.\n");
                return -1;
            } else if (b == 0){
                printf("--Mathematical problem: logarithm of 0.\n");
                return -1;
            } else if (b < 0){
                printf("--Mathematical problem: logarithm of negative value.\n");
                return -1;
            } else {
                *result = (log(b) / log(a));
                return 0;
            }
        }
    } else {
        return -1;
    }
}
