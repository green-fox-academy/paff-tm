#include <iostream>

using namespace std;

// store your personal data in Variables
// string name, int age, int slice_of_pizza_you_can_eat
// allocate memory dynamically for these variables
// create a sentense using these variables
// free the allocated memory

int main() {
    string *name;
    name = new string("Andris");

    int *age;
    age = new int(33);

    int *slice_of_pizza_you_can_eat;
    slice_of_pizza_you_can_eat = new int(4);

    cout <<  *name << " is " << *age << " years old and can eat " << *slice_of_pizza_you_can_eat << " pizza slices." << endl;

    delete name;
    delete age;
    delete slice_of_pizza_you_can_eat;

    return 0;
}
