/*
 *  H FILE FOR TODO APPLICATION in C++
 *  ==================================
 *  Define data types and constants
 */

#ifndef DEFINE_H_INCLUDED
#define DEFINE_H_INCLUDED

#define OPSTR_EXIT "exit"
#define OPSTR_PRINT_USAGE "help"
#define OPSTR_CLEAR_SCREEN "cls"
#define OPSTR_ADD_TASK "-a"
#define OPSTR_LIST_TASKS "-l"
#define OPSTR_SAVE_FILE "-wr"
#define OPSTR_OPEN_FILE "-rd"
#define OPSTR_EMPTY "-e"
#define OPSTR_REMOVE_TASK "-r"
#define OPSTR_CHECK_TAKS "-c"
#define OPSTR_PRIORITY_ADD "-p"
#define OPSTR_PRIO_LIST "-lp"

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
    OP_REMOVE_TASK,
    OP_CHECK_TASK,
    OP_PRIORITY_ADD,
    OP_PRIO_LIST
} t_operator;


#endif // DEFINE_H_INCLUDED
