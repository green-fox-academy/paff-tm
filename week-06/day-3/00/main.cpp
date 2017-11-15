#include <iostream>

using namespace std;

// Create a Human class which is a base class for
// SuperHuman and AquaHuman
// Create a virtual function in Human class called travelling()
// It should print out different ways to travel
// For example: Human is walking. SuperHuman is flying. AquaHuman is riding with dolphins.

class Human {

};

class SuperHuman: private Human {

};

class AquaHuman: private Human {

};


int main()
{


    return 0;
}
