#ifndef TODOLIST_H
#define TODOLIST_H

#include <vector>
#include "Task.h"

using namespace std;

class ToDoList
{
    public:
        ToDoList();
        ~ToDoList();

    protected:

    private:
        vector <Task> Tasks;


};

#endif // TODOLIST_H
