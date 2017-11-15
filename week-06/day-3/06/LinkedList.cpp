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
    //cout << "add an item" << endl;
}

void LinkedList::addItemBack(int data)
{
    Node *p = new Node;
    p->setData(data);
    p->setNext(NULL);

    if (first == NULL) {
        first = p;
    } else {
        Node *t = first;
        while (t->getNext() != NULL) {
            t = t->getNext();
        }
        t->setNext(p);
    }
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

int LinkedList::getData(unsigned int pos)
{
    Node *p = first;
    unsigned int i = 0;
    while (i < pos && p != NULL) {
        p = p->getNext();
        ++i;
    }

    if (p == NULL) {
        return 0;
    }

    return p->getData();
}

void LinkedList::clear()
{
    while (first != NULL) {
        delFirstItem();
        //cout << "del an item" << endl;
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
