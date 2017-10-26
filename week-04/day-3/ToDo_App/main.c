#include <stdio.h>
#include <stdlib.h>

#include "define.h"
#include "input_ev.h"
#include "task_op.h"
#include "file_op.h"

void print_usage();

int main()
{
    t_todo todos[MAX_NUM_OF_TODOS];     //array of the todos
    int num_of_todos = 0;               //number of the todos

    char input_str[80] = "";            //input string from user
    char *attr;                         //the attribute from the input_str
    t_operator op = OP_NOP;             //the operator from the input_str

    print_usage();

    do {
        gets(input_str);
        input_ev(input_str, &op, &attr);

        switch (op) {
        case OP_NOP:
            printf("Error: Unknown operator\n");
            break;
        case OP_EXIT:

            break;
        case OP_PRINT_USAGE:
            print_usage();
            break;
        case OP_ADD_TASK:
            if (num_of_todos == MAX_NUM_OF_TODOS) {
                printf("Error: Too many todos\n");
            } else {
                task_add(&todos[num_of_todos], attr);
                num_of_todos++;
            }
            break;
        case OP_LIST_TASKS:
            task_list(todos, num_of_todos);
            break;
        case OP_SAVE_FILE:
            if (save_tasks(todos, num_of_todos) == -1) {
                printf("Error: can't open file \"%s\"", FILE_NAME);
            }
            break;
        case OP_OPEN_FILE:
            open_tasks(todos, &num_of_todos);
            break;
        default:

            break;
        }
    } while (op != OP_EXIT);

    return 0;
}

void print_usage()
{
    printf(""
        "Todo application\n"
        "======================================\n"
        "Commands:\n"
        " -a   Adds a new task\n"
        " -wr  Write current todos to file\n"
        " -rd  Read todos from a file\n"
        " -l   Lists all the tasks\n"
        " -e   Empty the list\n"
        " -rm  Removes a task\n"
        " -c   Completes a task\n"
        " -p   Add priority to a task\n"
        " -lp  Lists all the tasks by priority\n"
        " -------------------------------------\n"
        " exit Exit the program without saving\n"
        " help Prints out this help\n\n");
}
