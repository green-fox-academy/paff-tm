/*  H FILE FOR TODO APPLICATION
 *  ===========================
 *  define variable types
 */

#ifndef DEFINE_H_INCLUDED
#define DEFINE_H_INCLUDED

#define OPSTR_EXIT "exit"
#define OPSTR_PRINT_USAGE "help"
#define OPSTR_ADD_TASK "-a"
#define OPSTR_LIST_TASKS "-l"

typedef struct {
    char name[80];
} t_todo;

typedef enum {
    OP_NOP,
    OP_EXIT,
    OP_PRINT_USAGE,
    OP_ADD_TASK,
    OP_LIST_TASKS
} t_operator;

#endif // DEFINE_H_INCLUDED
