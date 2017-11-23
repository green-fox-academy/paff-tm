#ifndef TEMPDATA_H
#define TEMPDATA_H

#include <string>
#include <ctime>

using namespace std;

class TempData
{
    public:
        //TempData(string _line);
        TempData(tm _time, int _temperature);
        ~TempData();

        string getLine();
        string getDate();
        string getTime();
        int getTemperature();

    private:
        //string line;
        tm time;
        int temperature;
};

#endif // TEMPDATA_H
