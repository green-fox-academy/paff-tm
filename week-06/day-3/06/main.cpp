#include <iostream>
#include "LinkedList.h"

using namespace std;

// Create a linked list using classes.
// If you are not similar whit linked lists look it up on the internet.
// Feel free to walk through some tutorials, get familiar with your implementation.

int main()
{
    LinkedList l;

    l.addItemBack(3);
    l.addItemBack(5);
    l.addItemBack(6);

    cout << "number of items: " << l.size() << endl;

    for (int i = 0; i < l.size(); ++i) {
        cout << l.getData(i) << endl;
    }

    return 0;
}
