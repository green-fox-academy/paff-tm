#include <iostream>
#include <string>

using namespace std;

// Write a program that prints a few details to the terminal window about you
// It should print each detail to a new line.
//  - Your name
//  - Your age
//  - Do you like coffee? (as a boolen variable)
//
//  Example output:
//  John Doe
//  31
//  Likes coffee: true

int main()
{
    string name = "Andras";
    int age = 33;
    bool likeCoffee = true;

    cout << name << endl;
    cout << age << endl;

    cout << "Likes Coffee: ";
    if (likeCoffee) {
        cout << "true";
    } else {
        cout << "false";
    }
    cout << endl;


    return 0;
}
