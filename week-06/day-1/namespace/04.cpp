#include <iostream>

// Create your own namespace, called Mark
// store your name as a string
// your age as an integer
// and your favorite number as an integer
//
// Create your own namespace, called Maria
// store your name as a string
// your age as an integer
// and your favorite number as an integer
//
// create a function that can add the two age, and returns it

using namespace std;

namespace Mark {
    string name = "Mark";
    int age = 30;
    int favorite_number = 10;
}

namespace Maria {
    string name = "Maria";
    int age = 23;
    int favorite_number = 33;
}

void getages(int* pMaria, int* pMark)
{
    *pMaria = Maria::age;
    *pMark = Mark::age;
}

int main()
{
    int Maria_age;
    int Mark_age;

    getages(&Maria_age, &Mark_age);

    cout << "Maria's age is: " << Maria_age<< endl;
    cout << "Mark's age is: " << Mark_age << endl;

    return 0;
}
