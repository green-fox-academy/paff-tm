/*  C FILE FOR TODO APPLICATION
 *  ===========================
 *  functions to handle tasks
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "define.h"


/*  Checks is the string contains only digits, so it is an unsigned int.
 *  If it is, returns 1; if it is not, returns 0;
 */
int is_uint(char *num_str)
{
    char decimal_values[] = "0123456789";

    if (strspn(num_str, decimal_values) < strlen(num_str)) {
        return 0;
    } else {
        return 1;
    }
}

int task_add(t_todo *p_todo, char *new_todo)
{
    strcpy(p_todo->name, new_todo);
    return 0;
}

/*  Remove a task from todos.
 *  Returns 0 if OK, -1 if the attribute is out of scope, -2 if attribute is not correct.
 */
int task_remove(t_todo todos[], int num_of_todos, char *rem_str)
{
    int rem;

    if (strlen(rem_str) == 0) {
        return -1;
    } else if (is_uint(rem_str) == 0) {
        return -2;
    } else {
        rem = atoi(rem_str);

        if (rem < 1 || rem > num_of_todos) {
            return -3;
        }

        for (int i = rem - 1; i < num_of_todos; i++) {
            todos[i] = todos[i + 1];
        }

        return 0;
    }
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
