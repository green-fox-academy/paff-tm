/*  C FILE FOR MULTI-OPERATOR CLI CALCULATOR
 *  Contains the functions of command line evaluation
 *  =================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*  Gives back the id of the operator, and also separates the input string to operand_a and operand_b
 *  If no operator was found then returns -1.
 */
int get_operator(char input_str[], char operand_a[], char operand_b[])
{
    int op_id = -1;                 //id of the operator. If there is no operator found, then it will be -1
    char *ptr = NULL;               //pointer to the first character of operator
    char operators[8][6] = //list of the operators
        {"+",       // 0
         "*",       // 1
         "/",       // 2
         "%",       // 3
         "^",       // 4
         "<",       // 5
         "log",     // 6
         "-"};      // 7 - subtraction has to be the last operator!

    //check if the input string contains an operator or command
    for (int i = 0; i < (sizeof(operators) / sizeof(operators[0])); i++) {
        ptr = strstr(input_str, operators[i]);
        if (ptr != NULL) {      //if an operator was found
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

            // get operand_a (characters before the operator)
            strncpy(operand_a, input_str, ptr - input_str);
            operand_a[ptr - input_str] = '\0';
            if (strlen(operand_a) == 0) {
                op_id = -1;
            }

            // get operand_b (characters after the operator)
            strcpy(operand_b, ptr + strlen(operators[op_id]));
            if (strlen(operand_b) == 0) {
                op_id = -1;
            }

            break;
        }
    }

    return op_id;
}

/*  Get the float value of str. If it is a decimal float value,
 *  then returns 0, if not returns -1. Prints error message if there is an error.
 */
int get_value(char str[], double *a)
{
    char decimal_values[] = "0123456789-.";

    //check if str is a decimal number
    if (strspn(str, decimal_values) != strlen(str)) {
        printf("--Input error: operand is not a decimal number.\n");
        return -1;
    }

    // if there is no error, then set the values;
    *a = atof(str);

    return 0;
}

/*  Remove all spaces fro str string.
 *
 */
void remove_spaces(char str[])
{
    int j = 0;
    for (int i = 0; i <= strlen(str); i++) {
        if (str[i] != ' ') {
            str[j] = str[i];
            j++;
        }
    }
}

