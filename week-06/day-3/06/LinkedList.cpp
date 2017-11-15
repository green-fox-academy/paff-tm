#include <iostream>
#include "Node.h"
#include "LinkedList.h"

using namespace std;

LinkedList::LinkedList()
{
    first = NULL;
}

LinkedList::~LinkedList()
{
    clear();
}

void LinkedList::addItem(int data)
{
    Node *p = new Node;
    p->setData(data);
    p->setNext(first);
    first = p;
    cout << "add an item" << endl;
}

int LinkedList::getFirstData()
{
    if (first == NULL) {
        return 0;
    }

    return first->getData();
}

void LinkedList::delFirstItem()
{
    if (first != NULL) {
        Node *p = first->getNext();
        delete first;
        first = p;
    }
}

void LinkedList::clear()
{
    while (first != NULL) {
        delFirstItem();
        cout << "del an item" << endl;
    }
}

unsigned int LinkedList::size()
{
    unsigned int count = 0;
    Node *p = first;

    while (p != NULL) {
        p = p->getNext();
        ++count;
    }

    return count;
}
