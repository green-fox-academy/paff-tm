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
    ofstream outfile;
    outfile.open(_filename.c_str(), ios::out);

    for (unsigned int i = 0; i < _tasks->size(); ++i) {
        outfile << _tasks->at(i).getAllData() << endl;
    }

    outfile.close();
}

vector <Task>* FileIO::openListFromFile(string _filename)
{
    ifstream infile;
    infile.open(_filename.c_str(), ios::in);

//    unsigned int i = 0;
//    while (!infile.eof()) {
//        infile >> tasks->at(i).setAllData();
//        ++i;
//    }

    infile.close();
    return 0;
}
