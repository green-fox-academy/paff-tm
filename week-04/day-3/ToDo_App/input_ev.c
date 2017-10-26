/*  C FILE FOR TODO APPLICATION
 *  ===========================
 *  Input string evaluation
 */

// TODO: value adding to attribute is not working properly

#include <string.h>

#include "define.h"

/*  Divide input_str to an operator as int, and to the attribute as string.
 *  If no error occurs, return 0. If the operator is not correct or missing return -1.
 */
int input_ev(char input_str[], t_operator *op, char attr_str[])
{
    //set the operator pointer to the first element of input_str
    char *p_operator = strtok(input_str, " ");
    char *p_attribute = strtok(NULL, "\"");

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
        } else {
            *op = OP_NOP;
            return -1;
        }

        //if the operator was identified,
        //than add value to attr_str
        if (p_attribute != NULL){
            strcpy(attr_str, p_attribute);
        } else {
            strcpy(attr_str, "");
        }
        /*
        if (p_attribute == NULL) {
            for (int i = 0, j = 0; p_attribute[i] != '\0'; i++){
                if (p_attribute[i] != '"') {
                    attr_str[j] = p_attribute[i];
                    j++;
                }
            }
        }
        */

        //return no error
        return 0;

    //if  there is no operator
    } else {
        *op = OP_NOP;
        return -1;
    }


}
