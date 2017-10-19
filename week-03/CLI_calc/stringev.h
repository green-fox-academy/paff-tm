/*  HEADER FILE FOR CLI CALCULATOR
 *  Contains the functions of command line evaluation
 *  =================================================
 */

#include <stdlib.h>
#include <string.h>

/*  Gives back the id of the operator, and also separates the input string to operand_a and operand_b after
 *  removing all spaces. If no operator was found or operand is missing then returns -1.
 */
int get_operator(char input_str[], char operand_a[], char operand_b[], char operators[NUM_OF_OPS][6])
{
    int op_id = -1;             //id of the operator. If there is no operator found, then it will be -1
    char *ptr = NULL;           //pointer to the first character of operator

    operand_a[0] = '\0';        //reset operand_a string
    operand_b[0] = '\0';        //reset operand_b string

    //remove all spaces from the input string
    int j = 0;
    for (int i = 0; i <= strlen(input_str); i++) {
        if (input_str[i] != ' ') {
            input_str[j] = input_str[i];
            j++;
        }
    }

    //check if the input string contains an operator or command
    for (int i = 0; i < NUM_OF_OPS; i++) {
        ptr = strstr(input_str, operators[i]);
        if (ptr != NULL) {      //if an operator or command was found
            op_id = i;

            //handle the problem if the first operand is a negative number
            //it the first character is '-' then skip it and continue
            if ((strcmp(operators[op_id], "-") == 0) && (ptr == input_str)) {
                ptr = strstr(ptr + 1, operators[i]);    //search for an other '-' char in the input string
                if (ptr != NULL) {                      //if there is, than it will be the operator
                    op_id = i;
                } else {                                //else it is not a subtraction, continue with next operator
                    continue;
                }
            }

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
int get_dec_values(char operand_a[], char operand_b[],  double *a, double *b)
{
    char decimal_values[] = "0123456789-.";

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
int get_hexto_values(char operand_hex[], char operand_base[],  double *hex, double *base)
{
    char hexadecimal_values[] = "0123456789abcdefABCDEF";
    char *ptr = NULL;

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
int get_binto_values(char operand_bin[], char operand_base[], double *bin, double *base)
{
    char binary_values[] = "01";
    char *ptr = NULL;

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
int get_decto_values(char operand_dec[], char operand_base[], double *dec, double *base)
{
    char decimal_values[] = "0123456789";
    char *ptr = NULL;

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

