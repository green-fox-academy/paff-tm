#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
//#include <conio.h> for getch() or _getch()

#include "define.h"
#include "input_ev.h"
#include "task_op.h"
#include "file_op.h"

void print_usage();
void clear_screen();

int main()
{
   // printf("%d", sizeof(t_todo));

    t_todo todos[MAX_NUM_OF_TODOS];     //array of the todos
    int num_of_todos = 0;               //number of the todos

    char input_str[80] = "";            //input string from user
    char attr[80] = "";                 //the attribute from the input_str
    t_operator op = OP_NOP;             //the operator from the input_str

    print_usage();

    do {
        gets(input_str);
        input_ev(input_str, &op, attr);

        switch (op) {

        case OP_NOP:
            printf("Error: Unknown operator\n");
            break;

        case OP_EXIT:
            break;

        case OP_PRINT_USAGE:
            print_usage();
            break;

        case OP_CLEAR_SCREEN:
            clear_screen();
            break;

        case OP_ADD_TASK:
            switch (task_add(todos, &num_of_todos, attr)) {
            case 0:
                break;
            case -1:
                printf("Unable to add: Too many todos\n");
                break;
            case -2:
                printf("Unable to add: No task is provided\n");
                break;
            default:
                printf("Unable to add: Unknown error\n");
            }
            break;

        case OP_LIST_TASKS:
            task_list(todos, num_of_todos, 0);
            break;

        case OP_PRIO_LIST:
            task_list(todos, num_of_todos, 1);
            break;

        case OP_SAVE_FILE:
            if (save_tasks(todos, num_of_todos, attr) == -1) {
                printf("Error: Can't open file \"%s\"\n", attr);
            }
            break;

        case OP_OPEN_FILE:
            if (open_tasks(todos, &num_of_todos, attr) == -1) {
                 printf("Error: Can't open file \"%s\"\n", attr);
            }
            break;

        case OP_EMPTY:
            fflush(stdin);
            printf("Area you sure to empty all todos? (y/n)\n");
            if (getchar() == 'y') {
                num_of_todos = 0;
                printf("No todos for today! :)\n");
            } else {
                printf("No todos were deleted\n");
            }
            fflush(stdin);
            break;

        case OP_REMOVE_TASK:
            switch (task_remove(todos, &num_of_todos, attr)) {
            case 0:
                break;
            case -1:
                printf("Unable to remove: No index is provided\n");
                break;
            case -2:
                printf("Unable to remove: Index is not a number\n");
                break;
            case -3:
                printf("Unable to remove: Index is out of bound\n");
                break;
            default:
                printf("Unable to remove: Unknown error\n");
            }
            break;

         case OP_CHECK_TASK:
            switch (task_check(todos, num_of_todos, attr)) {
            case 0:
                break;
            case -1:
                printf("Unable to check: No index is provided\n");
                break;
            case -2:
                printf("Unable to check: Index is not a number\n");
                break;
            case -3:
                printf("Unable to check: Index is out of bound\n");
                break;
            case -4:
                printf("Unable to check: Already checked\n");
                break;
            default:
                printf("Unable to check: Unknown error\n");
            }
            break;

        case OP_PRIORITY_ADD:
            switch (task_priority_add(todos, &num_of_todos, attr)) {
            case 0:
                break;
            case -1:
                printf("Unable to add: Too many todos\n");
                break;
            case -2:
                printf("Unable to add: No task is provided\n");
                break;
            default:
                printf("Unable to add: Unknown error\n");
            }
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
        " help Prints out this help\n"
        " cls  Clear the screen\n\n");
}

void clear_screen()
{
    system("cls");
}
