#include <iostream>

// Use your costume namespace from the last exercise
// Create a function, which takes the age as a parameter
// and returns the year when you were born

using namespace std;

namespace Person {
    string name = "Andris";
    int age = 33;
    int favorite_number = 26;
}

using namespace Person;

int getAge()
{
    cin >> age;
    return age;
}

int main()
{
    cout << "Add your age: ";
    cout << "You was born in: " << 2017 - getAge() << endl;

    return 0;
}
