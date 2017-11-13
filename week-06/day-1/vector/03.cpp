#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
	//create a vector of integers with the size of 20
	//fill this vector with random numbers from 0 to 10
	//print the items of the vector
    //remove the even numbers, then print the items again

    vector <int> int_vector;
    int_vector.reserve(20);

    for (unsigned int i = 0; i < int_vector.capacity(); ++i) {
        int_vector.push_back(rand() % 10 + 1);
	}

	for (unsigned int i = 0; i < int_vector.size(); ++i) {
        cout << int_vector.at(i) << endl;
	}

	for (unsigned int i = 0; i < int_vector.size(); ++i) {
        if (int_vector.at(i) % 2 == 0)
            int_vector.erase(int_vector.begin() + i);
    }

	for (unsigned int i = 0; i < int_vector.size(); ++i) {
        cout << int_vector.at(i) << endl;
	}

	int_vector.clear();

    return 0;
}
