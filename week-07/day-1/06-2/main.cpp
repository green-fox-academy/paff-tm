#include <iostream>
#include <stdexcept>

using namespace std;

// Put it all together, create a try block which throws integer,
// char and built-in exceptions and a catch block which can "catch them all".

void check0division(int x)
{
    if (x == 0)
        //throw runtime_error("division by 0");
        //throw "Error!";
        throw 42;
}

int main()
{
    int a, b;

    try {
        cin >> a;
        cin >> b;
        check0division(b);
        cout << a / b;
    }
    catch (...) {
        cout << "Standard error..." << endl;
    }

	return 0;
}
