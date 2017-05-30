#include "NodeInterface.h"
using namespace std;

class Node : public NodeInterface {
    friend class BST;
public:
    Node(int item) {
        data = item;
        leftChild = NULL;
        rightChild = NULL;
    }
	~Node() {}
    int getData() const;
    NodeInterface * getLeftChild() const;
    NodeInterface * getRightChild() const;
    void setLeftChild(Node *ptr);
    void setRightChild(Node *ptr);
    
protected:
    Node *leftChild;
    Node *rightChild;
    int data;
};