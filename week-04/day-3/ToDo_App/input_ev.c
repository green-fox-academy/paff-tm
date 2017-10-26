/*  C FILE FOR TODO APPLICATION
 *  ===========================
 *  Input string evaluation
 */

#include <string.h>

#include "define.h"

/*  Divide input_str to an operator as int, and to the attribute as string.
 *  If no error occurs, return 0. If the operator is not correct or missing return -1.
 */
int input_ev(char input_str[80], t_operator *op, char **attr_str)
{
    char *p_operator = NULL;
    char *p_attribute = NULL;

    p_operator = strtok(input_str, " ");
    if (p_operator != NULL) {                   //if we have at least one element in input
                                                //then check which operator is it
        if (strcmp(p_operator, OPSTR_EXIT) == 0) {
            *op = OP_EXIT;
        } else if (strcmp(p_operator, OPSTR_PRINT_USAGE) == 0) {
            *op = OP_PRINT_USAGE;
        } else if (strcmp(p_operator, OPSTR_ADD_TASK) == 0) {
            *op = OP_ADD_TASK;
        } else if (strcmp(p_operator, OPSTR_LIST_TASKS) == 0) {
            *op = OP_LIST_TASKS;
        } else if (strcmp(p_operator, OPSTR_SAVE_FILE) == 0) {
            *op = OP_SAVE_FILE;
        } else if (strcmp(p_operator, OPSTR_OPEN_FILE) == 0) {
            *op = OP_OPEN_FILE;
        } else {
            *op = OP_NOP;
            return -1;
        }
        p_attribute = strtok(NULL, " ");        //set the attr_str
        *attr_str = p_attribute;
        return 0;                               //return no error
    } else {                                    //so there is no operator
        *op = OP_NOP;
        return -1;
    }
}
