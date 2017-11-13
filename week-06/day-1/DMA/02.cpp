#include <iostream>
#include <vector>

using namespace std;

/**
 * Please create a program that asks for a count when it starts.
 * It should ask for a number count times, then it should print the average of the numbers.
 * It should delete any dynamically allocated resource before the program exits.
 */

int main() {
    int count;
    vector <int> int_vector;
    int int_temp;

    cout << "Add the count number: ";
    cin >> count;

    for (int i = 0; i < count; ++i) {
        cout << "Add the " << i + 1 << ". number: ";
        cin >> int_temp;
        int_vector.push_back(int_temp);
    }

    int_temp = 0;
    for (int i = 0; i < count; ++i) {
        int_temp += int_vector.at(i);
    }

    cout << "The average is: " << int_temp / int_vector.size() << endl;

    int_vector.clear();

    return 0;
}
