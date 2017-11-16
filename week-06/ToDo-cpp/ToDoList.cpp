#include <iostream>
#include <string.h>
#include <windows.h>
#include "ToDoList.h"

using namespace std;

ToDoList::ToDoList()
{
    //ctor
}

ToDoList::~ToDoList()
{
    //dtor
}

void ToDoList::commandInput()
{
    string input_str;
    t_operator op;          //the operator from the input_str
    string attr1;           //the 1st attribute from the input_str
    string attr2;           //the 2nd attribute from the input_str
    Task *temp_task;

    getline(cin, input_str);
    input_evaluation(input_str, &op, &attr1, &attr2);

    switch (op) {

    case OP_NOP:

        break;

    case OP_EXIT:
        exit = true;
        break;

    case OP_PRINT_USAGE:
        printUsage();
        break;

    case OP_CLEAR_SCREEN:
        clear_screen();
        break;

    case OP_ADD_TASK:
        temp_task = new Task;
        temp_task->setDescription(attr1);
        addTask(temp_task);
        break;

    case OP_PRIORITY_ADD:

        break;

    case OP_LIST_TASKS:
        listTasks();
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
}

bool ToDoList::getExit()
{
    return exit;
}

void ToDoList::addTask(Task *_task)
{
    tasks.push_back(*_task);
}

void ToDoList::input_evaluation(string input_str, t_operator *op, string *attr1, string *attr2)
{
    string op_str;

    size_t buffer_end;
    size_t buffer_start;

    buffer_end = input_str.find(' ');
    op_str = input_str.substr(0, buffer_end);

    if (op_str == "") {
        *op = OP_NOP;
    } else if (op_str == OPSTR_EXIT) {
        *op = OP_EXIT;
    } else if (op_str == OPSTR_PRINT_USAGE) {
        *op = OP_PRINT_USAGE;
    } else if (op_str == OPSTR_CLEAR_SCREEN) {
        *op = OP_CLEAR_SCREEN;
    } else if (op_str == OPSTR_ADD_TASK) {
        *op = OP_ADD_TASK;
    } else if (op_str == OPSTR_LIST_TASKS) {
        *op = OP_LIST_TASKS;
    } else if (op_str == OPSTR_SAVE_FILE) {
        *op = OP_SAVE_FILE;
    } else if (op_str == OPSTR_OPEN_FILE) {
        *op = OP_OPEN_FILE;
    } else if (op_str == OPSTR_EMPTY) {
        *op = OP_EMPTY;
    } else if (op_str == OPSTR_REMOVE_TASK) {
        *op = OP_REMOVE_TASK;
    } else if (op_str == OPSTR_CHECK_TAKS) {
        *op = OP_CHECK_TASK;
    } else if (op_str == OPSTR_PRIORITY_ADD)  {
        *op = OP_PRIORITY_ADD;
    } else if (op_str == OPSTR_PRIO_LIST) {
        *op = OP_PRIO_LIST;
    } else {
        *op = OP_NOP;
    }

    buffer_start = buffer_end + 1;

    switch (*op) {
    case OP_ADD_TASK:
    case OP_SAVE_FILE:
    case OP_OPEN_FILE:
        buffer_end = input_str.find('"', buffer_start);
        *attr1 = input_str.substr(buffer_start, buffer_end - buffer_start);
        break;

    case OP_REMOVE_TASK:
    case OP_CHECK_TASK:
        buffer_end = input_str.find(' ', buffer_start);
        *attr1 = input_str.substr(buffer_start, buffer_end - buffer_start);
        break;

    case OP_PRIORITY_ADD:
        buffer_end = input_str.find('"', buffer_start);
        *attr1 = input_str.substr(buffer_start, buffer_end - buffer_start);

        buffer_start = buffer_end + 1;
        buffer_end = input_str.find(' ', buffer_start);
        *attr2 = input_str.substr(buffer_start, buffer_end - buffer_start);
        break;

    default:
        break;
    }

}

void ToDoList::listTasks()
{
    for (unsigned int i = 0; i < tasks.size(); ++i) {
        cout << tasks.at(i).getDescription() << endl;
    }
}

void ToDoList::printUsage()
{
    cout << "Todo application                      " << endl;
    cout << "====================                  " << endl;
    cout << "Commands:                             " << endl;
    cout << "-a   Adds a new task                  " << endl;
    cout << "-wr  Write current todos to file      " << endl;
    cout << "-rd  Read todos from a file           " << endl;
    cout << "-l   Lists all the tasks              " << endl;
    cout << "-e   Empty the list                   " << endl;
    cout << "-rm   Removes a task                  " << endl;
    cout << "-c   Completes a task                 " << endl;
    cout << "-p   Add priority to a task           " << endl;
    cout << "-lp  Lists all the tasks by priority  " << endl;
    cout << " -------------------------------------" << endl;
    cout << " exit Exit the program without saving " << endl;
    cout << " help Prints out this help            " << endl;
    cout << " cls  Clear the screen                " << endl << endl;
}

void ToDoList::clear_screen()
{
    system("CLS");
}
