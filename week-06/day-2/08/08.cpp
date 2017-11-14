#include <iostream>
#include <vector>
#include <numeric>
#include <cstdlib>
#include <ctime>

using namespace std;

class Student {
private:
    vector <int> *grades;

public:
    Student() {
        grades = new vector <int>;
    }

    ~Student() {
        cout << "The student has died..." << endl;
        delete grades;
    }

    void add_grade(unsigned int grade) {
        if (grade > 0 && grade < 6) {
            grades->push_back(grade);
        }
    }

    float get_average() {
        int sum;
        if (grades->size() == 0) {
            return 0;
        } else {
            sum = accumulate(grades->begin(), grades->begin() + grades->size(), 0);
        }
        return (float)sum / grades->size();
    }

};

int main()
{
    // Create a student Class
    // that has a method `add_grade`, that takes a grade from 1 to 5
    // an other method `get_average`, that returns the average of the
    // grades

    srand(time(0));

    Student pupil;

    for (int i = 0; i < 10; ++i) {
        pupil.add_grade(rand() % 5 + 1);
    }

    cout << pupil.get_average() << endl;

    return 0;
}
