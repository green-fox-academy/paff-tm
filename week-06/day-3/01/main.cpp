#include <iostream>

using namespace std;

// Create a Shape class, inherit two derived class from it
// One should be Circle, and the other one is Triangle
// For each derived class, implement a calc_area() method
// which calculates the area of the shape and stores it inside
// the class (so it is a private method)

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

    cout << c.getArea() << endl;
    cout << t.getArea() << endl;

    return 0;
}
