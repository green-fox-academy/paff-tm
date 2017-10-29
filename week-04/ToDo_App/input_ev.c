/*  C FILE FOR TODO APPLICATION
 *  ===========================
 *  Input string evaluation
 */

#include <string.h>

#include "define.h"

/*  Divide input_str to an operator as int, and to the attribute as string.
 *  If no error occurs, return 0. If the operator is not correct or missing returns -1.
 */
int input_ev(char input_str[], t_operator *op, char attr_str[], char attr2_str[])
{
    //set the operator pointer to the first element of input_str
    char *p_operator = strtok(input_str, " ");
    char *p_attr = NULL;
    char *p_attr2 = NULL;

    //if we have at least one element in input
    //then check which operator it is
    if (p_operator != NULL) {
        if (strcmp(p_operator, OPSTR_EXIT) == 0) {
            *op = OP_EXIT;
        } else if (strcmp(p_operator, OPSTR_PRINT_USAGE) == 0) {
            *op = OP_PRINT_USAGE;
        } else if (strcmp(p_operator, OPSTR_CLEAR_SCREEN) == 0) {
            *op = OP_CLEAR_SCREEN;
        } else if (strcmp(p_operator, OPSTR_ADD_TASK) == 0) {
            *op = OP_ADD_TASK;
        } else if (strcmp(p_operator, OPSTR_LIST_TASKS) == 0) {
            *op = OP_LIST_TASKS;
        } else if (strcmp(p_operator, OPSTR_SAVE_FILE) == 0) {
            *op = OP_SAVE_FILE;
        } else if (strcmp(p_operator, OPSTR_OPEN_FILE) == 0) {
            *op = OP_OPEN_FILE;
        } else if (strcmp(p_operator, OPSTR_EMPTY) == 0) {
            *op = OP_EMPTY;
        } else if (strcmp(p_operator, OPSTR_REMOVE_TASK) == 0) {
            *op = OP_REMOVE_TASK;
        } else if (strcmp(p_operator, OPSTR_CHECK_TAKS) == 0) {
            *op = OP_CHECK_TASK;
        } else if (strcmp(p_operator, OPSTR_PRIORITY_ADD) == 0) {
            *op = OP_PRIORITY_ADD;
        } else if (strcmp(p_operator, OPSTR_PRIO_LIST) == 0) {
            *op = OP_PRIO_LIST;
        } else {
            *op = OP_NOP;
            return -1;
        }

        switch (*op) {
        case OP_ADD_TASK:
        case OP_SAVE_FILE:
        case OP_OPEN_FILE:
            p_attr = strtok(NULL, "\"");
            break;

        case OP_REMOVE_TASK:
        case OP_CHECK_TASK:
            p_attr = strtok(NULL, " ");
            break;

        case OP_PRIORITY_ADD:
            p_attr = strtok(NULL, "\"");
            p_attr2 = strtok(NULL, " ");
            break;

        default:
            break;
        }

        //if an operator was identified,
        //than add value to attr_str
        if (p_attr != NULL){
            strcpy(attr_str, p_attr);
        } else {
            strcpy(attr_str, "");
        }

        //if a second operator was identified,
        //than add value to attr2_str
        if (p_attr2 != NULL){
            strcpy(attr2_str, p_attr2);
        } else {
            strcpy(attr2_str, "");
        }

        //return no error
        return 0;

    //if  there is no operator
    } else {
        *op = OP_NOP;
        return -1;
    }


}
