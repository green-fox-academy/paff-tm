#include <iostream>
#include <string>

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
        Car(unsigned int age, unsigned int kms_runed, string manufacturer)
        {
            this->age = age;
            this->kms_runed = kms_runed;
            this->manufacturer = manufacturer;
            persons = 0;
            number_of_seats = 0;
        };

        void increase_kms(unsigned int km)
        {
            kms_runed += km;
        };

        void add_person()
        {
            if (persons < number_of_seats) {
                ++persons;
            } else {
                cout << "No more free seats!" << endl;
            }
        };

        unsigned int getNumberOfSeats()
        {
            return number_of_seats;
        };

    protected:
        unsigned int age;
        unsigned int kms_runed;
        string manufacturer;
        unsigned int number_of_seats;
        unsigned int persons;
};

class SUV: public Car {
    public:
        SUV(unsigned int age, unsigned int kms_runed, string manufacturer) : Car(age, kms_runed, manufacturer)
        {
            number_of_seats = 5;
        };

};

class Minibus: public Car {
    public:
        Minibus(unsigned int age, unsigned int kms_runed, string manufacturer) : Car(age, kms_runed, manufacturer)
        {
            number_of_seats = 9;
        };
};

int main()
{
    Minibus mb(10, 120131, "VolksWagen");
    SUV s(12, 235000, "Ford");

    for (unsigned int i = 0; i < mb.getNumberOfSeats() + 2; ++i) {
        mb.add_person();
    }

    for (unsigned int i = 0; i < s.getNumberOfSeats() + 2; ++i) {
        s.add_person();
    }

    return 0;
}
