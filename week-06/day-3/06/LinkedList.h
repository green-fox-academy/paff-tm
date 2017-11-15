#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node.h"

class LinkedList
{
    public:
        LinkedList();
        ~LinkedList();
        void addItem(int data);
        int getFirstData();

    protected:
        Node *first = NULL;

    private:

};

#endif // LINKEDLIST_H
