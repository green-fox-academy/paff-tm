#include <iostream>
#include <string>

using namespace std;

class Student {
private:

public:
    Student() {

    }

    ~Student() {
        cout << "The student has died..." << endl;
    }

};

int main()
{
    // Create a student Class
    // that has a method `add_grade`, that takes a grade from 1 to 5
    // an other method `get_average`, that returns the average of the
    // grades

    Student pupil;

    return 0;
}
