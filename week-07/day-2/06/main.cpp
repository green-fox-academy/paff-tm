#include <iostream>

using namespace std;

// Take the Integer class from the previous exercise and add two methods:
// One which takes an Integer& parameter and adds the value of it to the member variable of this.
// One which takes an int and adds the value of it to the member variable of this.
//
// Write code which uses them both and Prints out the results respectively.

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

        int add(int a)
        {
            mNum = mNum + a;
            return get();
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
    Integer i(3);
    Integer j(2);

    cout << i.add(j) << endl;
    cout << i.add(10) << endl;

	return 0;
}
