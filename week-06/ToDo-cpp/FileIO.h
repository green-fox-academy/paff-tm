/*
 *  H FILE FOR TODO APPLICATION in C++
 *  ==================================
 *  Class FileIO
 */

#ifndef FILEIO_H
#define FILEIO_H

#include <iostream>
#include "ToDoList.h"

using namespace std;

class FileIO
{
    public:
        FileIO();
        ~FileIO();
        void saveListToFile(string _filename);
        ToDoList* openListFromFile(string _filename);

    protected:

    private:
};

#endif // FILEIO_H
