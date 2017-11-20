#include <iostream>
#include <stdexcept>

using namespace std;

//Try to run the following code!

void checkRange(int i, int length)
{
    if (i < 0 || i > length - 1) {
        throw runtime_error("Error: Out of range");
    }
}

int main () {

    int int_array[5] = {1, 2, 3, 4, 5};
    int i = 0;

    cin >> i;

    try {
        checkRange(i, sizeof(int_array) / sizeof(int_array[0]));
        cout << int_array[i];
    }
    catch (runtime_error &err) {
        cout << err.what() << endl;
    }

    return 0;
}

//The program should compile but crash!
//Create a solution for this problem using try-catch block!

