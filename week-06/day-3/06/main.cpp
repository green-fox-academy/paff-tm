#include <iostream>
#include "LinkedList.h"

using namespace std;

// Create a linked list using classes.
// If you are not similar whit linked lists look it up on the internet.
// Feel free to walk through some tutorials, get familiar with your implementation.

int main()
{
    LinkedList l;

    l.addItem(3);
    l.addItem(5);
    l.addItem(6);

    cout << "number of items: " << l.size() << endl;

    cout << l.getFirstData() << endl;
    l.delFirstItem();
    cout << l.getFirstData() << endl;
    l.delFirstItem();
    cout << l.getFirstData() << endl;
    l.delFirstItem();
    cout << l.getFirstData() << endl;
    l.delFirstItem();
    cout << l.getFirstData() << endl;


    return 0;
}
