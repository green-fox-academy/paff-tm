#ifndef TASK_H
#define TASK_H

#include <string>

using namespace std;

class Task
{
    public:
        Task();
        ~Task();
        //void setDescription(string _desc);
        //string getDescription();

    private:
        string description;
        //bool checked;
        //unsigned int priority ;
};

#endif // TASK_H
