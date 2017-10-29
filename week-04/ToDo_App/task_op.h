/*  H FILE FOR TODO APPLICATION
 *  ===========================
 *  functions to handle tasks
 */

#ifndef TASK_OP_H_INCLUDED
#define TASK_OP_H_INCLUDED



/* this function is not neccessarry since task_priority_add can handle task without priority
int task_add(t_todo todos[], int *num_of_todos, char *new_todo);
*/
int is_uint(char *num_str);
int task_priority_add(t_todo todos[], int *num_of_todos, char *new_todo, char *prio_str);
int task_remove(t_todo todos[], int *num_of_todos, char *rem_str);
int task_check(t_todo todos[], int num_of_todos, char *rem_str);
int task_list(t_todo todos[], int num_of_todos, int is_priolist);

#endif // TASK_OP_H_INCLUDED
