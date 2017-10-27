/*  C FILE FOR TODO APPLICATION
 *  ===========================
 *  functions to handle tasks
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "define.h"


/*  Checks if the string contains only digits, so it is an unsigned int.
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

/*  Add a task to todos.
 *  Returns 0 if OK, -1 if reached the number of maximum tasks, -2 if todo is empty
 */
int task_add(t_todo todos[], int *num_of_todos, char *new_todo)
{
    if (*num_of_todos == MAX_NUM_OF_TODOS) {
        return -1;
    } else if (strlen(new_todo) == 0) {
        return -2;
    } else {
        strcpy(todos[*num_of_todos].name, new_todo);
        todos[*num_of_todos].checked = 0;
        (*num_of_todos)++;
        return 0;
    }
}

/*  Remove a task from todos.
 *  Returns 0 if OK, -1 if the attribute is missing, -2 if attribute is not a number,
 *  -3 if the attribute is out of bound.
 */
int task_remove(t_todo todos[], int *num_of_todos, char *rem_str)
{
    int rem;

    if (strlen(rem_str) == 0) {
        return -1;
    } else if (is_uint(rem_str) == 0) {
        return -2;
    } else {
        rem = atoi(rem_str);

        if (rem < 1 || rem > *num_of_todos) {
            return -3;
        }

        for (int i = rem - 1; i < *num_of_todos; i++) {
            todos[i] = todos[i + 1];
        }
        (*num_of_todos)--;

        return 0;
    }
}

/*  Prints out the tasks.
 *
 */
int task_list(t_todo todos[], int num_of_todos)
{
    printf(""
        "List by number\n"
        "====================\n"
        "Num  | Tasks\n");

    for (int i = 0; i < num_of_todos; i++) {
        printf("%2d - [%c] %s\n", i + 1, todos[i].checked?'x':' ', todos[i].name);
    }
    return 0;
}
