#include <iostream>
#include <string>

using namespace std;

class Circle {
    private:
        float radius;

    public:
        Circle(float radius){
            this->radius = radius;
        }

        ~Circle(){

        }

        float get_circumference(){
            return 2 * this->radius * 3.1415;
        }

        float get_area(){
            return this->radius * this->radius * 3.1415;
        }

};

int main()
{
    // Create a `Circle` class that takes it's radius as constructor parameter
    // It should have a `get_circumference` method that returns it's circumference
    // It should have a `get_area` method that returns it's area

    Circle c(2.4);

    cout << "area: " << c.get_area() << endl;
    cout << "circumference: " << c.get_circumference() << endl;

    return 0;
}
