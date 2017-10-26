#include <stdio.h>
#include <stdlib.h>

#include "define.h"
#include "input_ev.h"


int main()
{
    t_todo todo[10] = {0};      //array of the todos
    int numbers_of_todos = 0;   //number of the todos

    char input_str[80] = "";    //input string from user
    char attr[80] = "";         //the attribute from the input_str
    t_operator op = OP_NOP;     //the operator from the input_str

    do {
        gets(input_str);
        input_ev(input_str, &op, &attr);

        switch (op) {
        case OP_EXIT:

            break;
        case OP_PRINT_USAGE:

            break;
        case OP_ADD_TASK:

            break;
        case OP_LIST_TASKS:

            break;
        default:

            break;
        }
    } while (0);

    return 0;
}
