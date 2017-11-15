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
        void delFirstItem();
        void clear();
        unsigned int size();

    protected:
        Node *first;

    private:

};

#endif // LINKEDLIST_H
