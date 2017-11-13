#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

int main()
{
	//Create a vector of integers
	//reserve place for 10 element, then fill those place with random numbers between 0 and 10

	vector <int> int_vector;
	int_vector.reserve(10);
	srand(time(0));

	for (unsigned int i = 0; i < int_vector.capacity(); ++i) {
        int_vector.push_back(rand() % 10 + 1);
	}

	for (unsigned int i = 0; i < int_vector.size(); ++i) {
        cout << int_vector.at(i) << endl;
	}

    return 0;
}
