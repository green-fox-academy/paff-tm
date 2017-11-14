#include <iostream>
#include <string>

using namespace std;

class Car {
private:
    string type;
    unsigned int km;

public:
    Car(string type, unsigned int km) {
        this->type = type;
        this->km = km;
    }

    ~Car() {
        cout << "The car is demolished" << endl;;
    }

    void run(unsigned int run_km) {
        km += run_km;
    }

    void print_data(){
        cout << type << " " << km << endl;
    }

};

int main()
{
    // Create a class called "Car"
    // It should have a "type" property that stores the car's type in a string eg: "Mazda"
    // It should have a "km" property that stores how many kilometers it have run
    // The km and the type property should be a parameter in the constructor
    // It should have a method called "run" that takes a number and increments the "km" property by it

    Car c("Ford", 137032);

    c.print_data();
    c.run(8);
    c.print_data();

    return 0;
}
