#include <iostream>
using namespace std;

// Create a function which throws an char
// In the main(), put that function in a try block
// Also in the main() catch, what your function throws

void check0division(char c)
{
    if (c == 0)
        throw '0';
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
    catch (char x) {
        cout << "Error: " << x << endl;
    }

	return 0;
}
