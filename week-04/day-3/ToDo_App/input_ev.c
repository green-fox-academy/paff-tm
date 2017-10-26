/*  C FILE FOR TODO APPLICATION
 *  ===========================
 *  Input string evaluation
 */

#include <string.h>
#include "define.h"

/*  Divide input_str to an operator as int, and to the attribute as string.
 *  If no error occurs, return 0. Is the operator is not correct or missing return 1.
 *
 */
int input_ev(char input_str[80], int *op, char attr_str[80])
{
    char *p_operator = NULL;
    char *p_attribute = NULL;

    p_operator = strtok(input_str, " ");
    if (p_operator != NULL) {                       //if we have at least one element in input
                                            //then check which operator is it
        if (strcmp(p_operator, OPSTR_EXIT) == 0) {
            *op = OP_EXIT;
        } else if (strcmp(p_operator, OPSTR_PRINT_USAGE) == 0) {
            *op = OP_PRINT_USAGE;
        } else if (strcmp(p_operator, OPSTR_ADD_TASK) == 0) {
            *op = OP_ADD_TASK;
        } else if (strcmp(p_operator, OPSTR_LIST_TASKS) == 0) {
            *op = OP_LIST_TASKS;
        }
        p_attribute = strtok(NULL, " ");           //set the attr_str
    }

    return 0;
}
