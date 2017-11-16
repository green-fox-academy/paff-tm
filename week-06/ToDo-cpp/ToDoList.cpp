#include <iostream>
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

void ToDoList::printUsage(){
    cout << "Todo application                    " << endl;
    cout << "====================                " << endl;
    cout << "Commands:                           " << endl;
    cout << "-a   Adds a new task                " << endl;
    cout << "-wr  Write current todos to file    " << endl;
    cout << "-rd  Read todos from a file         " << endl;
    cout << "-l   Lists all the tasks            " << endl;
    cout << "-e   Empty the list                 " << endl;
    cout << "-rm   Removes a task                " << endl;
    cout << "-c   Completes a task               " << endl;
    cout << "-p   Add priority to a task         " << endl;
    cout << "-lp  Lists all the tasks by priority" << endl;
}
