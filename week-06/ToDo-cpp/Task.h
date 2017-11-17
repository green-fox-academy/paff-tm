/*
 *  H FILE FOR TODO APPLICATION in C++
 *  ==================================
 *  Class Task
 */

#ifndef TASK_H
#define TASK_H

#include <string>

using namespace std;

class Task
{
    public:
        Task();
        ~Task();
        void setDescription(string _desc);
        string getDescription();
        void setAllData(string _desc);
        string getAllData();

    private:
        string description;
        //bool checked;
        //unsigned int priority ;
};

#endif // TASK_H
