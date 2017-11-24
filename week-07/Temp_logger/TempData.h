/*
 *  H FILE FOR TEMPERATURE LOGGER
 *  =============================
 *  Class TempData
 */

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

        string getLineStr();
        string getDateStr();
        string getTimeStr();
        int getTemperature();
        tm getTM();

    private:
        //string line;
        tm time;
        int temperature;
};

#endif // TEMPDATA_H
