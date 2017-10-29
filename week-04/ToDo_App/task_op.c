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
 *  Returns 0 if OK, -1 if reached the number of maximum tasks, -2 if description is empty
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
        todos[*num_of_todos].priority = 0;
        (*num_of_todos)++;
        return 0;
    }
}

/*  Add a task to todos with priority.
 *  Returns 0 if OK, -1 if reached the number of maximum tasks, -2 if description is empty
 *  -3 if priority is not a number, -4 if priority is less than 0
 *  If no priority was identified in input string, then the priority will be 0;
 */
int task_priority_add(t_todo todos[], int *num_of_todos, char *new_todo, char *prio_str)
{
    int prio = 0;

        if (*num_of_todos == MAX_NUM_OF_TODOS) {
            return -1;

        } else if (strlen(new_todo) == 0) {
            return -2;

        } else if (is_uint(prio_str) == 0) {
            return -3;

        } else {
            prio = atoi(prio_str);
            if (prio < 0) {
                return -4;
            }

            strcpy(todos[*num_of_todos].name, new_todo);
            todos[*num_of_todos].checked = 0;
            todos[*num_of_todos].priority = prio;
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

/*  Checks out a task from todos.
 *  Returns 0 if OK, -1 if the attribute is missing, -2 if attribute is not a number,
 *  -3 if the attribute is out of bound, -4 if the task is already checked
 */
int task_check(t_todo todos[], int num_of_todos, char *chk_str)
{
    int chk;

    if (strlen(chk_str) == 0) {
        return -1;

    } else if (is_uint(chk_str) == 0) {
        return -2;

    } else {
        chk = atoi(chk_str);

        if (chk < 1 || chk > num_of_todos) {
            return -3;
        } else if (todos[chk].checked == 1) {
            return -4;
        } else {
            todos[chk - 1].checked = 1;
            return 0;
        }
    }
}

/*  Prints out one todo item.
 *  Function for task_list function
 */
void print_todo_item(t_todo *p_todo, int item_num)
{
    printf("%2d - [%c] %s", item_num + 1, p_todo->checked?'x':' ', p_todo->name);
    if (p_todo->priority != 0)
        printf(" - %d\n", p_todo->priority);
    else
        printf("\n");

}

/*  Prints out the tasks.
 *  if is_priolist is true (1) then prints in priority order, else in order of the array
 */
int task_list(t_todo todos[], int num_of_todos, int is_priolist)
{
    printf(""
        "List by number\n"
        "====================\n"
        "Num  | Tasks | Prio\n");

    // if wants to print in order of priority
    if (is_priolist) {
        int actual_prio = -1;

        //looking for the highest priority value
        for (int i = 0; i < num_of_todos; i++) {
            if (todos[i].priority > actual_prio) {
                actual_prio = todos[i].priority;
            }
        }

        while (actual_prio >= 0) {
            for (int i = 0; i < num_of_todos; i++) {
                if (todos[i].priority == actual_prio) {
                    print_todo_item(&todos[i], i);
                }
            }
            actual_prio--;
        }

    // else print in order of array
    } else {
        for (int i = 0; i < num_of_todos; i++) {
            print_todo_item(&todos[i], i);
        }
    }

    return 0;
}

