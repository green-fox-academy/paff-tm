#include <iostream>
#include <vector>
#include <numeric>
#include "Student.h"

using namespace std;

Student::Student() {
    grades = new vector <int>;
}

Student::~Student() {
    cout << "The student has died..." << endl;
    delete grades;
}

void Student::add_grade(unsigned int grade) {
    if (grade > 0 && grade < 6) {
        grades->push_back(grade);
    }
}

float Student::get_average() {
    if (grades->size() == 0) {
        return 0;
    }

    return (float)accumulate(grades->begin(), grades->begin() + grades->size(), 0) / grades->size();
}
