#include <iostream>
using namespace std;

// Create a function which throws an integer
// In the main(), put that function in a try block
// Also in the main() catch, what your function throws

void check0division(int x) //throw(int)
{
    if (x == 0)
        throw 8;
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
    catch (int x) {
        cout << "Error: " << x << endl;
    }

	return 0;
}
