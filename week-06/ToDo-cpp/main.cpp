#include <iostream>
#include "define.h"
#include "ToDoList.h"
#include "Task.h"
#include "FileIO.h"

using namespace std;

int main()
{
    string input_str;
    char op;
    FileIO *f = new FileIO;
    ToDoList *l = new ToDoList;

    l->printUsage();

/*
    do {

        cin >> input_str;
        //input_ev(input_str, &op, attr, attr2);

        switch (op) {

        case OP_NOP:

            break;

        case OP_EXIT:
            break;

        case OP_PRINT_USAGE:

            break;

        case OP_CLEAR_SCREEN:

            break;

        case OP_ADD_TASK:

            break;

        case OP_PRIORITY_ADD:

            break;

        case OP_LIST_TASKS:

            break;

        case OP_PRIO_LIST:

            break;

        case OP_SAVE_FILE:

            break;

        case OP_OPEN_FILE:

            break;

        case OP_EMPTY:

            break;

        case OP_REMOVE_TASK:

            break;

        case OP_CHECK_TASK:

            break;

        default:
            break;
        }
    } while (op != OP_EXIT);

*/

    delete f;
    delete l;

    return 0;
}
