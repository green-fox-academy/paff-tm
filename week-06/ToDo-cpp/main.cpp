#include <iostream>
#include <string>
#include "define.h"
#include "ToDoList.h"
#include "Task.h"
#include "FileIO.h"

using namespace std;

int main()
{
    FileIO *f = new FileIO;
    ToDoList *l = new ToDoList;

    l->printUsage();

    do {
        l->commandInput();
    } while (l->getExit() == false);

    delete f;
    delete l;

    return 0;
}
