// Still the shape exercise!
// Create public method called how_much_to_paint()
// which should get the area and the price of the paint as parameters
// It should return the costs of the painting

#include <iostream>

#define PAINT_PRICE 400

using namespace std;

class Shape {
    public:
        float getArea() {
            return area;
        };
        float how_much_to_paint() {
            return area * PAINT_PRICE;
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
        void calc_area() {
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
        void calc_area() {
            area = (a * m) / 2;
        };
};

int main()
{
    Circle c(1);
    Triangle t(2, 1);

    cout << "Circle area: " << c.getArea() << endl;
    cout << "Circle radius: " << c.getRadius() << endl;
    cout << "Circle paint price: " << c.how_much_to_paint() << endl;

    cout << "------------------" << endl;

    cout << "Triangle area: " << t.getArea() << endl;
    cout << "Triangle base: " << t.getBase() << endl;
    cout << "Triangle height: " << t.getHeight() << endl;
    cout << "Triangle paint price: " << t.how_much_to_paint() << endl;

    return 0;
}
