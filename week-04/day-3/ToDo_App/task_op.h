/*  H FILE FOR TODO APPLICATION
 *  ===========================
 *  functions to handle tasks
 */

#ifndef TASK_OP_H_INCLUDED
#define TASK_OP_H_INCLUDED

int is_uint(char *num_str);
int task_add(t_todo todos[], int *num_of_todos, char *new_todo);
int task_remove(t_todo todos[], int *num_of_todos, char *rem_str);
int task_list(t_todo todos[], int num_of_todos);

#endif // TASK_OP_H_INCLUDED
