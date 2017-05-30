#include "BST.h"
	NodeInterface * BST::getRootNode() const{
	    return root;
	}
	bool BST::add(int item){
		return add(this->root, item);
	}
	bool BST::add(Node*& local_root, const int item){
		if (local_root == NULL) {
			local_root = new Node(item);
    		return true;
		}
		else {
    		if (item < local_root->data)
    			return add(local_root->leftChild, item);
    		else if (local_root->data < item)
    			return add(local_root->rightChild, item);
			else {
				return false;
			}
		}
	}
	bool BST::remove(int item){
	    return remove(this->root, item);
	}
	bool BST::remove(Node*& local_root, int item){
		if (local_root == NULL) {
			return false;
		}
		else {
			if (item < local_root->data)
		    	return remove(local_root->leftChild, item);
		    else if (local_root->data < item)
		    	return remove(local_root->rightChild, item);
		    else {
		    	Node* old_root = local_root;
		    	if (local_root->leftChild == NULL) {
		    		local_root = local_root->rightChild;
		    	}
		    	else if (local_root->rightChild == NULL) {
		        	local_root = local_root->leftChild;
		    	}
		    	else {
		        	replace_parent(old_root, old_root->leftChild);
		    	}
				delete old_root;      
				return true;
			}
		}
	}
	void BST::replace_parent(Node*& old_root, Node*& local_root) {
		if (local_root->rightChild != NULL) {
			replace_parent(old_root, local_root->rightChild);
		}
		else {
			old_root->data = local_root->data;
			old_root = local_root;
			local_root = local_root->leftChild;
		}
	}
	void BST::clear(){
	    clear(root);
	}
	void BST::clear(Node*& local_root){
		while(root != NULL){
			remove(root->data);
		}
	}