/*
 *  H FILE FOR TODO APPLICATION in C++
 *  ==================================
 *  Class FileIO
 */

#ifndef FILEIO_H
#define FILEIO_H

#include <iostream>
#include <vector>
#include "Task.h"

using namespace std;

class FileIO
{
    public:
        FileIO();
        ~FileIO();
        void saveListToFile(string _filename, vector <Task> *_tasks);
        vector <Task>*  openListFromFile(string _filename);

    protected:

    private:
};

#endif // FILEIO_H
