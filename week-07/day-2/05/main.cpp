#include <iostream>

using namespace std;

// Take the Integer class from the previous exercise.
// Create 3 constructors for them:
// One empty which sets the member varibale to 0;
// A copy constructor, that takes an Integer& argument
// A third one which takes an int as argument and makes the member variable equal to the int it took.
//
// Write code that uses these and prints out the value of the member variable of the integers created.
// (You will have to create a get method to do this appropriately.)

class Integer {
    private:
        int mNum;
    public:
        Integer()
        {
            mNum = 0;
        }

        Integer(Integer& x)
        {
            mNum = x.get();
        }

        Integer(int x)
        {
            mNum = x;
        }

        int get()
        {
            return mNum;
        }

        int add(Integer& a)
        {
            mNum = mNum + a.get();
            return get();
        }

        int add(Integer& a, Integer& b)
        {
            mNum = mNum + a.get() + b.get();
            return get();
        }

        int add(Integer& a, Integer& b, Integer& c)
        {
            mNum = mNum + a.get() + b.get() + c.get();
            return get();
        }

        int add(Integer& a, Integer& b, Integer& c, Integer& d)
        {
            mNum = mNum + a.get() + b.get() + c.get() + d.get();
            return get();
        }

        int add(Integer& a, Integer& b, Integer& c, Integer& d, Integer& e)
        {
            mNum = mNum + a.get() + b.get() + c.get() + d.get() + e.get();
            return get();
        }

};

int main() {

    Integer i;
    Integer j(3);
    Integer k(j);

    cout << "i: " << i.get() << endl;
    cout << "j: " << j.get() << endl;
    cout << "k: " << k.get() << endl;

	return 0;
}
