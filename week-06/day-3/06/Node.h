#ifndef NODE_H
#define NODE_H

class Node
{
    public:
        Node();
        Node* getNext();
        void setNext(Node *n);
        int getData();
        void setData(int data);

    protected:
        int data;
        Node *next;

    private:
};

#endif // NODE_H
