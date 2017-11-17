/*
 *  CPP FILE FOR TODO APPLICATION in C++
 *  ====================================
 *  Class FileIO
 */

#include <iostream>
#include <fstream>
#include "FileIO.h"

using namespace std;

FileIO::FileIO()
{
    //ctor
}

FileIO::~FileIO()
{
    //dtor
}

void FileIO::saveListToFile(string _filename, vector <Task> *_tasks)
{
    char buffer[_filename.length() + 1];
    copy(_filename.begin(), _filename.end(), buffer);
    buffer[_filename.size()] = '\0';

    ofstream outfile;
    outfile.open(buffer, ios::out);

    for (unsigned int i = 0; i < _tasks->size(); ++i) {
        outfile << _tasks->at(i).getAllData() << endl;
    }

    outfile.close();
}

vector <Task>* FileIO::openListFromFile(string _filename)
{

    return 0;
}
