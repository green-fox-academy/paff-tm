#include <iostream>
#include <cstdlib>
#include <ctime>

#include "Student.h"

using namespace std;

int main()
{
    // Create a student Class
    // that has a method `add_grade`, that takes a grade from 1 to 5
    // an other method `get_average`, that returns the average of the
    // grades

    Student pupil;

    srand(time(0));
    for (int i = 0; i < 10; ++i) {
        pupil.add_grade(rand() % 5 + 1);
    }

    cout << pupil.get_average() << endl;

    return 0;
}
