#include <iostream>
#include "Node.h"

using namespace std;

Node::Node()
{
    next = NULL;
}

Node* Node::getNext()
{
    return next;
}

void Node::setNext(Node *n)
{
    next = n;
}

int Node::getData()
{
    return data;
}

void Node::setData(int data)
{
    this->data = data;
}
