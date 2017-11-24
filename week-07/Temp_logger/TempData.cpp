#include "TempData.h"

#include <stdlib.h>
#include <sstream>

using namespace std;

/*TempData::TempData(string _line)
{
    line = _line;
}*/

TempData::TempData(tm _time, int _temperature)
{
    time = _time;
    temperature = _temperature;
}

TempData::~TempData()
{
    //dtor
}

string TempData::getLineStr()
{
    char str_temp[10];
    itoa(getTemperature(), str_temp, 10);
    return getDateStr() + " " + getTimeStr() + " " + str_temp;
}

string TempData::getDateStr()
{
    stringstream strstr;
    strstr << time.tm_year << "." << time.tm_mon << "." << time.tm_mday;
    return strstr.str();
}

string TempData::getTimeStr()
{
    stringstream strstr;
    strstr << time.tm_hour << ":" << time.tm_min << ":" << time.tm_sec;
    return strstr.str();
}

int TempData::getTemperature()
{
    return temperature;
}

tm TempData::getTM()
{
    return time;
}
