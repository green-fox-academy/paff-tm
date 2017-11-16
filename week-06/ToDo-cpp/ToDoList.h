/*
 *  H FILE FOR TODO APPLICATION in C++
 *  ==================================
 *  Class ToDoList
 */

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
        void takeInput();
        bool getExit();
        void printUsage();

    protected:

    private:
        vector <Task> tasks;
        bool exit;

        void inputEvaluation(string input_str, t_operator *op, string *attr, string *attr2);
        void addTask(Task *_task);
        void listTasks();
        void saveFile(string _filename);
        void openFile(string _filename);
        void clear_screen();

};

#endif // TODOLIST_H
