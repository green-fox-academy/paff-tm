#include <iostream>
#include <stdexcept>

using namespace std;

/**
 * Create a function that prints out the fist "N" positive odd numbers.
 * It should take the "N" number as a parameter, and print the output to the console.
 *
 * The output should look like this for 5 as parameter:
 *   1, 3, 5, 7, 9
 *
 * Non-positive "N" numbers should be treated as errors, handle it!
 */

void print_positive_odd_numbers(int x)
{
    if (x < 0) {
        throw runtime_error("N can't be negative!");
    } else {
        for (int i = 2; i <= x * 2; i += 2) {
            cout << i << endl;
        }
    }
}

int main()
{
    int x;
    cin >> x;

    try {
        print_positive_odd_numbers(x);
    }
    catch (runtime_error &err) {
        cout << "Error: " << err.what() << endl;
    }

	return 0;
}
