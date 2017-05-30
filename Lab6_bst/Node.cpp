#include "Node.h"
	int Node::getData() const{
	    return(data);
	}
	NodeInterface * Node::getLeftChild() const{
	      if (leftChild == NULL){
	      	return NULL;
	      }
	      return(leftChild);
	}
	NodeInterface * Node::getRightChild() const{
	      if (rightChild == NULL){
	      	return NULL;
	      }
	      return(rightChild);
	}
	void Node::setLeftChild(Node *ptr){
	      leftChild = ptr;
	}
	void Node::setRightChild(Node *ptr){
	      rightChild = ptr;
	}