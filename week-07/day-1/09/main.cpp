#include <iostream>
#include <stdexcept>

using namespace std;

/**
 * Create a function that prints a multiplication table with a given base number.
 * It should take the base number as a parameter, and print the output to the console.
 *
 * The output should look like this for 5 as base:
 *   1 * 5 = 5
 *   2 * 5 = 10
 *   3 * 5 = 15
 *   4 * 5 = 20
 *   5 * 5 = 25
 *   6 * 5 = 30
 *   7 * 5 = 35
 *   8 * 5 = 40
 *   9 * 5 = 45
 *   10 * 5 = 50
 *
 *  If the function gets invalid parameter
 *  Negative numbers are invalid parameters.
 *  It should throw an exceptions
 */

void print_multiplication_table(int x)
{
    if (x < 0) {
        throw runtime_error("Base is negative!");
    } else if (x > 10) {
        throw runtime_error("Base is bigger than 10");
    } else {
        for (int i = 1; i <= 10; ++i) {
            cout << i << " * " << x << " = " << i * x << endl;
        }
    }
}

int main()
{
    int x;
    cin >> x;

    try {
        print_multiplication_table(x);
    }
    catch (runtime_error &err) {
        cout << "Error: " << err.what() << endl;
    }

	return 0;
}
