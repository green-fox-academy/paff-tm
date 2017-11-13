#include <iostream>

// Create your own namespace, called Person
// store your name as a string
// your age as an integer
// and your favorite number as an integer
// write them out in main()

using namespace std;

namespace Person {
    string name = "Andris";
    int age = 33;
    int favorite_number = 26;
}

using namespace Person;

int main()
{
    cout << name << endl;
    cout << age << endl;
    cout << favorite_number << endl;

    return 0;
}

