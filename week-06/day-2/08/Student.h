#ifndef STUDENT_H
#define STUDENT_H

#include <vector>

using namespace std;

class Student
{
    public:
        Student();
        ~Student();
        void add_grade(unsigned int grade);
        float get_average();

    private:
        vector <int> *grades;
};

#endif // STUDENT_H
