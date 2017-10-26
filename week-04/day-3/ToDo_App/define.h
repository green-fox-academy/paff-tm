/*  H FILE FOR TODO APPLICATION
 *  ===========================
 *  define variable types
 */

#ifndef DEFINE_H_INCLUDED
#define DEFINE_H_INCLUDED

#define MAX_NUM_OF_TODOS 10
#define FILE_NAME "todos.td"

#define OPSTR_EXIT "exit"
#define OPSTR_PRINT_USAGE "help"
#define OPSTR_CLEAR_SCREEN "cls"
#define OPSTR_ADD_TASK "-a"
#define OPSTR_LIST_TASKS "-l"
#define OPSTR_SAVE_FILE "-wr"
#define OPSTR_OPEN_FILE "-rd"

typedef struct {
    char name[80];
} t_todo;

typedef enum {
    OP_NOP,
    OP_EXIT,
    OP_CLEAR_SCREEN,
    OP_PRINT_USAGE,
    OP_ADD_TASK,
    OP_LIST_TASKS,
    OP_SAVE_FILE,
    OP_OPEN_FILE
} t_operator;

#endif // DEFINE_H_INCLUDED
