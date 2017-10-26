/*  H FILE FOR TODO APPLICATION
 *  ===========================
 *  functions to handle files
 */

#ifndef FILE_OP_H_INCLUDED
#define FILE_OP_H_INCLUDED

int save_tasks(t_todo todos[], int num_of_todos);
int open_tasks(t_todo todos[], int *num_of_todos);

#endif // FILE_OP_H_INCLUDED
