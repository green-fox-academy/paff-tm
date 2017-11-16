/*
 *  CPP FILE FOR TODO APPLICATION in C++
 *  ====================================
 *  Class Task
 */

#include <iostream>
#include "Task.h"

using namespace std;

Task::Task()
{
    //ctor
}

Task::~Task()
{
    //dtor
}

void Task::setDescription(string _desc)
{
    description = _desc;
}

string Task::getDescription()
{
    return description;
}
