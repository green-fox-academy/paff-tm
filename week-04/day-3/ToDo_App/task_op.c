/*  C FILE FOR TODO APPLICATION
 *  ===========================
 *  functions to handle tasks
 */

#include <stdio.h>
#include <string.h>

#include "define.h"

int task_add(t_todo *p_todo, char *new_todo)
{
    strcpy(p_todo->name, new_todo);
    return 0;
}

int task_list(t_todo todos[], int num_of_todos)
{
    printf(""
        "List by number\n"
        "====================\n"
        "Num \t| Tasks\n");

    for (int i = 0; i < num_of_todos; i++) {
        printf("%d \t- %s\n", i + 1, todos[i].name);
    }
    return 0;
}
