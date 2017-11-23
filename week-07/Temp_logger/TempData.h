#ifndef TEMPDATA_H
#define TEMPDATA_H

#include <string>

using namespace std;

class TempData
{
    public:
        TempData(string _line);
        ~TempData();

        string getDate();
        string getTime();
        string getTemperature();

    private:
        string line;
};

#endif // TEMPDATA_H
