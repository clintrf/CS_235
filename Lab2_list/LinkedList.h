#include "LinkedListInterface.h"
using namespace std;
#include <string>
#include <sstream>

template <typename T>
class LinkedList: public LinkedListInterface<T>
{
private:
    struct Node{
        T data;
        Node* next;
		Node(const T& the_data, Node* next_val = NULL) :
	   data(the_data) {next = next_val;}
    };
    
    Node *headNode;
    int num_items;
public:
	LinkedList() {
	    headNode = NULL;
	    num_items=0;
	};
	~LinkedList() {
		clear();
	};
	
	bool findValue(T value){
		if (headNode != NULL){
			Node* ptr = headNode;
			while(ptr != NULL){
				if(ptr->data == value){
					return true;
				}
				ptr = ptr->next;
			}
			return false;
		}
		return false;
	};
	
	void insertHead(T value){
		if(headNode == NULL){
			headNode = new Node(value, NULL);
			num_items++;
		}
		else{
			bool dup = findValue(value);
			if(dup == false){
				Node* insertNode = new Node(value);
				insertNode->next = headNode;
				headNode = insertNode;
				num_items++;
			}
		}

	};

	void insertTail(T value){
		if (headNode== NULL){
			headNode = new Node(value, NULL);
			num_items++;
		}
		else{
			Node* current = headNode;
			while (current->next != NULL){
				current = current->next;
			}
			bool dup = findValue(value);
			if(dup == false){
				Node* insertNode = new Node(value, NULL);
				current->next = insertNode;
				num_items++;
			}
		}

	};

	void insertAfter(T value, T insertionNode){
		bool dubInsertionNode = findValue(insertionNode);
		bool dubVal = findValue(value);
		if(dubInsertionNode == true){
			if(dubVal== false){
				Node* current = headNode;
				while(current->data != insertionNode){
					current = current->next;
				}
				Node* insertNode = new Node(value, current->next);
				current->next = insertNode;
				num_items++;
			}
		}
	};
	
	
	void remove(T value) {
		bool dub = findValue(value);
		if (dub == true){
			Node* current = headNode;
			if(current->data == value){
				headNode = current->next;
				delete current;
				num_items--;
			}
			else{
				while(current->next->data != value){
					current = current->next;
				}
				Node* tempPtr= current->next;
				current->next = tempPtr->next;
				delete tempPtr;
				num_items--;
			}
		}
	};
	
	T at(int index){
		if(index >= num_items || index < 0) {
			throw std::out_of_range("At Error");
		} 
		else {
			Node *ptr = headNode;
			for(int i = 0; i <= index; i++) {
		  		if(i == (index)) { 
		  			return(ptr->data);
		  		}else {
		  			ptr = ptr->next;
		  		}
			}
		}
	};
	
	void clear(){
		while(headNode != NULL){
	        Node *current = headNode;
	        headNode = headNode->next;
	        delete current;
	        num_items--;
	    }
		
	};
	
	int size(){
		return(num_items);
	};

	string toString()	{
		if(headNode != NULL){
			stringstream mylist;
			Node* current = headNode;
			while(current->next != NULL){
				mylist << current->data << " ";
				current = current->next;
			}
			mylist << current->data;
			return mylist.str();
		}
		else {
			string none = "";
			return none;
		}
	};
};
