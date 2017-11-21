#include <iostream>

using namespace std;

// Create a Class named Integer. It should have one int member variable.
// Create add() methods to it. They should take Integer& parameters.
// Make variations of add() method 1, 2, 3, 4 and 5 arguments respectively.
// All methods should add the value of the parameters to the member variable of this.
//
// Try them out. Write code that demonstrates how they work.

class Integer {
    private:
        int mNum;
    public:
        Integer()
        {
            mNum = 0;
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

int main()
{
    Integer i(1);
    Integer j(2);

    cout << i.add(j) << endl;
    cout << i.add(j, j) << endl;
    cout << i.add(j, j, j) << endl;
    cout << i.add(j, j, j, j) << endl;
    cout << i.add(j, j, j, j, j) << endl;

	return 0;
}
