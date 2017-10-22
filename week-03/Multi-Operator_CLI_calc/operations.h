/*  HEADER FILE FOR MULTI-OPERATOR CLI CALCULATOR
 *  Contains the functions of operations
 *  =============================================
 */

#ifndef OPERATIONS_H_INCLUDED
#define OPERATIONS_H_INCLUDED

int calculate(char input_str[], double *result);
int operation_addition(char operand_a[], char operand_b[], double *result);
int operation_subtraction(char operand_a[], char operand_b[], double *result);
int operation_multiplication(char operand_a[], char operand_b[], double *result);
int operation_division(char operand_a[], char operand_b[], double *result);
int operation_modulo(char operand_a[], char operand_b[], double *result);
int operation_exponentiation(char operand_a[], char operand_b[], double *result);
int operation_rooting(char operand_a[], char operand_b[], double *result);
int operation_log(char operand_a[], char operand_b[], double *result);

#endif // OPERATIONS_H_INCLUDED
