#include "TempData.h"

#include <stdlib.h>

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

string TempData::getLine()
{
    char str_temp[10];
    itoa(getTemperature(), str_temp, 10);
    return getDate() + " " + getTime() + " " + str_temp;
}

string TempData::getDate()
{

    return "";
}

string TempData::getTime()
{
    return "";
}

int TempData::getTemperature()
{
    return temperature;
}
