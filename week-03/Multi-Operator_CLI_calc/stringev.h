/*  HEADER FILE FOR MULTI-OPERATOR CLI CALCULATOR
 *  Contains the functions of command line evaluation
 *  =================================================
 */

#ifndef STRINGEV_H_INCLUDED
#define STRINGEV_H_INCLUDED

int get_operator(char input_str[], char operand_a[], char operand_b[]);
int get_value(char str[], double *a);
void remove_spaces(char str[]);

#endif // STRINGEV_H_INCLUDED
