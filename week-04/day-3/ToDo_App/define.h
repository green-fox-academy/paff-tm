/*  H FILE FOR TODO APPLICATION
 *  ===========================
 *  define variable types
 */

#ifndef DEFINE_H_INCLUDED
#define DEFINE_H_INCLUDED

#define MAX_NUM_OF_TODOS 10

#define OPSTR_EXIT "exit"
#define OPSTR_PRINT_USAGE "help"
#define OPSTR_CLEAR_SCREEN "cls"
#define OPSTR_ADD_TASK "-a"
#define OPSTR_LIST_TASKS "-l"
#define OPSTR_SAVE_FILE "-wr"
#define OPSTR_OPEN_FILE "-rd"
#define OPSTR_EMPTY "-e"
#define OPSTR_REMOVE_TASK "-r"

typedef struct {
    char name[80];
    char checked;
} t_todo;

typedef enum {
    OP_NOP,
    OP_EXIT,
    OP_CLEAR_SCREEN,
    OP_PRINT_USAGE,
    OP_ADD_TASK,
    OP_LIST_TASKS,
    OP_SAVE_FILE,
    OP_OPEN_FILE,
    OP_EMPTY,
    OP_REMOVE_TASK
} t_operator;

#endif // DEFINE_H_INCLUDED
