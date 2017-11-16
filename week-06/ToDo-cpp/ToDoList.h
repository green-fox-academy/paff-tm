#ifndef TODOLIST_H
#define TODOLIST_H

#include <vector>
#include "define.h"
#include "Task.h"

using namespace std;

class ToDoList
{
    public:
        ToDoList();
        ~ToDoList();

        void commandInput();
        bool getExit();
        void addTask(Task *_task);
        void listTasks();
        void printUsage();
        void clear_screen();

    protected:

    private:
        vector <Task> tasks;
        bool exit;

        void input_evaluation(string input_str, t_operator *op, string *attr, string *attr2);

};

#endif // TODOLIST_H
