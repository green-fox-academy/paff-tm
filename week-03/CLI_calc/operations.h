/*  HEADER FILE FOR CLI CALCULATOR
 *  Contains the functions of operations
 *  ====================================
 */

#include <math.h>

void operation_addition(char operand_a[], char operand_b[])
{
    double a, b, result;

    if (get_dec_values(operand_a, operand_b, &a, &b) == 0){
        result = a + b;
        print_dec_result(result);
    }
}

void operation_subtraction(char operand_a[], char operand_b[])
{
    double a, b, result;

    if (get_dec_values(operand_a, operand_b, &a, &b) == 0){
        result = a - b;
        print_dec_result(result);
    }
}

void operation_multiplicatin(char operand_a[], char operand_b[])
{
    double a, b, result;

    if (get_dec_values(operand_a, operand_b, &a, &b) == 0){
        result = a * b;
        print_dec_result(result);
    }
}

void operation_division(char operand_a[], char operand_b[])
{
    double a, b, result;

    if (get_dec_values(operand_a, operand_b, &a, &b) == 0){
        if (b == 0) {
            printf("--Mathematical problem: Division by zero.\n");
        } else {
            result = trunc(a / b);
            print_dec_result(result);
        }
    }
}

void operation_modulo(char operand_a[], char operand_b[])
{
    double a, b, result;

    if (get_dec_values(operand_a, operand_b, &a, &b) == 0){
        if (b == 0) {
            printf("--Mathematical problem: Division by zero.\n");
        } else {
            result = fmod(a, b);
            print_dec_result(result);
        }
    }
}

void operation_exponentiation(char operand_a[], char operand_b[])
{
    double a, b, result;

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
}

void operation_rooting(char operand_a[], char operand_b[])
{
    double a, b, result;

    if (get_dec_values(operand_a, operand_b, &a, &b) == 0){
        if (b < 0) {
            printf("--Mathematical problem: root of a negative number.\n");
        } else if (a == 0) {
            printf("--Mathematical problem: root base is zero.\n");
        } else {
            result = pow(b, 1 / a);
            print_dec_result(result);
        }
    }
}

void operation_log(char operand_a[], char operand_b[])
{
    double a, b, result;

    if (get_dec_values(operand_a, operand_b, &a, &b) == 0){
        if (a == 0) {
            printf("--Mathematical problem: 0 base logarithm.\n");
        } else if (a == 1){
            printf("--Mathematical problem: 1 base logarithm.\n");
        } else if (a < 0){
            printf("--Mathematical problem: negative base logarithm.\n");
        } else if (b == 0){
            printf("--Mathematical problem: logarithm of 0.\n");
        } else if (b < 0){
            printf("--Mathematical problem: logarithm of negative value.\n");
        } else {
            result = log(b) / log(a);
            print_dec_result(result);
        }
    }
}

void operation_binto(char operand_a[], char operand_b[])
{
    double a, b;
    char result_str[255] = "";

    if (get_binto_values(operand_a, operand_b, &a, &b) == 0){
        ltoa((long int)a, result_str, (int)b);
        print_str_result(result_str);
    }
}

void operation_hexto(char operand_a[], char operand_b[])
{
    double a, b;
    char result_str[255] = "";

    if (get_hexto_values(operand_a, operand_b, &a, &b) == 0){
        ltoa((long int)a, result_str, (int)b);
        print_str_result(result_str);
    }
}

void operation_decto(char operand_a[], char operand_b[])
{
    double a, b;
    char result_str[255] = "";

    if (get_decto_values(operand_a, operand_b, &a, &b) == 0){
        ltoa((long int)a, result_str, (int)b);
        print_str_result(result_str);
    }
}
