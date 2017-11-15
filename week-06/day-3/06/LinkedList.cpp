#include <iostream>
#include "Node.h"
#include "LinkedList.h"

using namespace std;

LinkedList::LinkedList()
{
    //ctor
}

LinkedList::~LinkedList()
{
    //dtor
}

void LinkedList::addItem(int data)
{
    Node *p = new Node;
    p->setData(data);
    p->setNext(NULL);
    first = p;
}

int LinkedList::getFirstData()
{
    return first->getData();
}
