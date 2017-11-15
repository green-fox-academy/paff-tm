#include <iostream>

using namespace std;

// Create a Human class which is a base class for
// SuperHuman and AquaHuman
// Create a virtual function in Human class called travelling()
// It should print out different ways to travel
// For example: Human is walking. SuperHuman is flying. AquaHuman is riding with dolphins.

class Human {
    virtual void travelling(){
        cout << "I'm walkin' in the rain..." << endl;
    };
};

class SuperHuman: private Human {
    virtual void travelling(){
        cout << "I believe I can fly...!" << endl;
    };
};

class AquaHuman: private Human {
    virtual void travelling(){
        cout << "I can swim!" << endl;
    };
};


int main()
{


    return 0;
}
