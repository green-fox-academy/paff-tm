#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node.h"

class LinkedList
{
    public:
        LinkedList();
        ~LinkedList();
        void addItem(IntNode n);

    protected:
        IntNode *first = NULL;

    private:

};

#endif // LINKEDLIST_H
