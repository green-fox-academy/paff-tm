#include <iostream>

using namespace std;

// Define several things as a variable then print their values
// Your name as a string
// Your age as an integer
// Your height in meters as a double
// Whether you are married or not as a boolean

int main()
{
    string name = "Andris";
    int age = 33;
    double height = 1.8;
    bool married = true;

    cout << name << endl;
    cout << age << endl;
    cout << height << endl;

    cout << "married: ";
    if (married) {
        cout << "true";
    } else {
        cout << "false";
    }

    return 0;
}
