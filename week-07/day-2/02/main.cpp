#include <iostream>

using namespace std;

// Create 3 functions: each should take respectively 2, 3 and 4 strings.
// Each should return a string that contains all the input string concatenated.
// (Combined into one in a linear order.)
// Write code that showcases how this works and prints out the result of the function.

string constr(string a, string b)
{
    return a + b;
}

string constr(string a, string b, string c)
{
    return a + b + c;
}

string constr(string a, string b, string c, string d)
{
    return a + b + c + d;
}

int main() {
    string a = "egy ";
    string b = "ketto ";
    string c = "harom ";
    string d = "negy ";

    cout << constr(a, b) << endl;
    cout << constr(a, b, c) << endl;
    cout << constr(a, b, c, d) << endl;

	return 0;
}
