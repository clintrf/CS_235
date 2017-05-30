#include "BSTInterface.h"
#include "Node.h"
using namespace std;

class BST : public BSTInterface {
public:
    BST() {
        root = NULL;
    }
    ~BST(){
        clear();
    }
    NodeInterface * getRootNode() const;
    bool add(int item);
    bool add(Node*& local_root, int item);
    bool remove(int item);
    bool remove(Node*& local_root, int item);
    void clear();
    void clear(Node*& local_root);
    void replace_parent(Node*& old_root, Node*& local_root);
    
protected:
    Node *root;
};