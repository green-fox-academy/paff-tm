#ifndef TEMPDATA_H
#define TEMPDATA_H

#include <string>

using namespace std;

class TempData
{
    public:
        TempData();
        ~TempData();

    private:
        string date;
        string time;
        int temp;
};

#endif // TEMPDATA_H
