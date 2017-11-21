#include <iostream>
#include <string>

using namespace std;

// Take the Integer class from the previous exercise and create two operators for it:
// a + operator that takes and Integer& and adds it's member variables value to this.
// a + operator that takes an int and adds it's value to the member variable of this.
//
// Consider what the return value of the operator should be: Integer& or void? Or something else?
// Make it so that the code below compiles and works.

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

        Integer& operator+ (Integer& other)
        {
            Integer *x = new Integer(mNum + other.get());
            return *x;
        }

        Integer& operator+ (int a)
        {
            Integer *x = new Integer(mNum + a);
            return *x;
        }
};

int main ()
{
    Integer a(12);
    Integer b(12);

    cout << (a + b).get() << endl;
    cout << (a + 12).get() << endl;
    cout << (a + b + 12).get() << endl;



    return 0;
}
