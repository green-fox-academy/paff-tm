#ifndef NODE_H
#define NODE_H

class Node
{
    public:
        Node();
        ~Node();

    protected:
        Node *next;

    private:
};

class IntNode: public Node {
    public:

    private:
        int data;
};

#endif // NODE_H
