#include <iostream>
#include <vector>

using namespace std;

int main()
{
	//create an integer vector with the size of 5 and print all elements of it
	vector <int> int_vector;
	int_vector.reserve(5);

	for (int i = 0; i < int_vector.capacity(); ++i) {
        int_vector.push_back(i);
	}

	for (int i = 0; i < int_vector.size(); ++i) {
        cout << int_vector.at(i) << endl;
	}

    return 0;
}
