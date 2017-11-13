#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

//create an integer vector with the size of 5 and print the 3rd element of it

int main()
{
    vector <int> int_vector;
    int vector_len = 5;

    srand(time(0));

    for (int i = 0; i < vector_len; ++i) {
        int_vector.push_back(rand());
    }

    cout << int_vector.at(2);

    int_vector.empty();

    return 0;
}
