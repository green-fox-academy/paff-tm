#include <iostream>
#include <stdexcept>
using namespace std;

// Create a function which throws a bulit-in exception
// In the main(), put that function in a try block
// Also in the main() catch, what your function throws

void check0division(int x)
{
    if (x == 0)
        throw runtime_error("division by 0");
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
    catch (runtime_error &err) {
        cout << "Error: " << err.what() << endl;
    }

	return 0;
}
