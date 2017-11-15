#include <iostream>
#include <vector>

using namespace std;

// Create a Car class.
// Create the following private variables : age, kms_runed, manufacturer, number_of_seats
// use proper variable types.
// Implement a method which has one parameter, and increases the kms_runed variable by its parameter value.
// Implement a method which can add a person to a car, if the number of persons in the car reached
// the value of number of seats in the car it should tell you that 'The car is full!' or something like that.
// Inherite at least two car models and try out the methods you have created.

class Car {
    public:
        void increase_kms(unsigned int km) {
            kms_runed += km;
        };
        void add_person() {
            if (persons < number_of_seats) {
                ++persons;
            } else {
                cout << "No more free seats!" endl;
            }
        };

    private:
        unsigned int age;
        unsigned int kms_runed;
        string manufacturer;
        unsigned int number_of_seats;
        unsigned int persons;
};

int main()
{

    return 0;
}
