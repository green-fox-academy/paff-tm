/*  HEADER FILE FOR CLI CALCULATOR
 *  Contains the functions of command line evaluation
 *  =================================================
 */

#ifndef STRINGEV_H_INCLUDED
#define STRINGEV_H_INCLUDED

int get_operator(char input_str[], char operand_a[], char operand_b[]);
int get_dec_values(char operand_a[], char operand_b[],  double *a, double *b);
int get_hexto_values(char operand_hex[], char operand_base[],  double *hex, double *base);
int get_binto_values(char operand_bin[], char operand_base[], double *bin, double *base);
int get_decto_values(char operand_dec[], char operand_base[], double *dec, double *base);

#endif // STRINGEV_H_INCLUDED
