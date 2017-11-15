// Countinue the Shape exercise!
// Create getter methods for each values
// (for example: in a Triangle class you should be able to
// get: Height, Base and Area)

#include <iostream>

using namespace std;

class Shape {
    public:
        float getArea() {
            return area;
        };
    protected:
        float area;
        virtual void calc_area() = 0;
};

class Circle: public Shape {
    public:
        Circle(float r) {
            this->r = r;
            calc_area();
        };
        float getRadius() {
            return r;
        };

    private:
        float r;
        virtual void calc_area() {
            area =  r *r * 3.1415;
        };
};

class Triangle: public Shape {
    public:
        Triangle(float a, float m) {
            this->a = a;
            this->m = m;
            calc_area();
        };
        float getBase() {
            return a;
        };
        float getHeight() {
            return m;
        };

    private:
        float a;
        float m;
        virtual void calc_area() {
            area = (a * m) / 2;
        };
};


int main()
{
    Circle c(1);
    Triangle t(2, 1);

    cout << "Circle area: " << c.getArea() << endl;
    cout << "Circle radius: " << c.getRadius() << endl;

    cout << "Triangle area: " << t.getArea() << endl;
    cout << "Triangle base: " << t.getBase() << endl;
    cout << "Triangle height: " << t.getHeight() << endl;

    return 0;
}
