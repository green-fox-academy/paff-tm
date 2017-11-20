#include <iostream>
using namespace std;

// Write a try - catch block.
// Throw an char in the try block
// Catch it in the catch block and write it out.

int main()
{
    try {
        throw 'x';
    }
    catch (char c) {
        cout << "Error: " << c << endl;
    }

	return 0;
}
