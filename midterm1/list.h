#ifndef LIST_H_
#define LIST_H_

#include <iostream>
#include <stdexcept>
#include <cstddef>
#include <string>
#include <sstream>
using namespace std;

template<typename Item_Type>
class list {
    private:
#include "DNode.h"
    public:
    DNode* head;
    DNode* tail;
    int num_items;

	list() {
	  head = NULL;
	  tail = NULL;
	  num_items = 0;
	};
	~list() {
	  while (head != NULL) {
	  	DNode* current = head;
	  	head = head->next;
	  	delete current;
	  }
	  tail = NULL;
	  num_items = 0;
	};
	void insertHead(const Item_Type& item) {
	  head = new DNode(item, NULL, head);
	  if (head->next != NULL)
	  	head->next->prev = head; 
	  if (tail == NULL)    
	  	tail = head;
	    num_items++;
	};
	void insertTail(const Item_Type& item) {
	  if (tail != NULL) {
	  	tail->next = new DNode(item, tail, NULL);
	  	tail = tail->next; 
	  	num_items++;
	  } else {        
	  	insertHead(item);
	  }
	};
	Item_Type front() {
	  if(head != NULL && num_items != 0)
	    return head->data;
	  else
	    return -1;
	};
	Item_Type back(){
		DNode* current = head;
		while (current->next != NULL){
			current = current->next;
		}
		return current->data;
	};
	void pop_front() {
	    if(head != NULL) {
	        DNode *temp = head;
		    head = head->next;
		    delete temp;
		    num_items--;
	    if(head == NULL)
	        tail = NULL;
	        num_items--;
	    }
	};
	void pop_back() {
	    if(head == NULL){
	        return;
	    }
	    DNode* current = head;
	    while (current->next != NULL){
	    	current = current->next;
	    }
	    if (current->prev != NULL){
	    	current->prev->next = NULL;
	    }
	    tail = current->prev;
	    delete current;
	    num_items--;
	};
	bool findValue(const Item_Type& item){
			if (head != NULL){
				DNode* ptr = head;
				while(ptr != NULL){
					if(ptr->data == item){
						return true;
					}
					ptr = ptr->next;
				}
				return false;
			}
			return false;
		};
		
	void remove(const Item_Type& item) {
		 bool dub = findValue(item);
		 if (dub == true){
			DNode* current = head;
			DNode* temp;
			
			if (head->data == item){
				removeHead();
				num_items--;
			}
			else if (tail->data == item){
				removeTail();
				num_items--;
			}
			else {
				while(current->data != item){
					current = current->next;
				}
				temp = current;
				temp->prev->next = temp->next;
				temp->next->prev = temp->prev;
				current->next = NULL;
				current->prev = NULL;
				delete current;
				num_items--;
			}
		 }
	};
	void removeHead(){
		DNode* current = head;
		if (head == tail){
    	head = tail = NULL;
		}
		else{
		    head = head->next;
		}
		delete current;
	};
	void removeTail(){
		DNode* current = tail;
		if (tail == head){
    		tail = head = NULL;
		}
		else{
    		tail = tail->prev;
    		tail->next = NULL;
		}	
		delete current;
	};
	void removeAt(int pos){
		DNode* current = head;
		DNode* temp;
		if (pos == 1){
			removeHead();
			num_items--;
		}
		else if (pos == num_items){
			removeTail();
			num_items--;
		}
		else {
			for (int i = 1; i <= num_items; i++ ){
				if (pos != i){
					current = current->next;
				}
				else {
					temp = current;
					temp->prev->next = temp->next;
					temp->next->prev = temp->prev;
					current->next = NULL;
					current->prev = NULL;
					delete current;
					num_items--;
					break;
				}
			}
		}
	}
	void removeCountBack(int pos){
		DNode *current = head;
		DNode* Tptr;
		while(current->next != NULL){
			current = current->next;
		}
		if (pos == num_items){
			removeHead();
			num_items--;
		}
		else if(pos == 1){
			removeTail();
			num_items--;
		}
		else{
			for (int i = 1; i < num_items; i++ ){
				if (pos != i){
					current = current->prev;
				}
				else {
					Tptr = current;
					Tptr->prev->next = Tptr->next;
					Tptr->next->prev = Tptr->prev;
					current->next = NULL;
					current->prev = NULL;
					delete current;
					num_items--;
					break;
				}
			}
		}
	};
	
	Item_Type at(const Item_Type& item){
		DNode *ptr = head;
		for(int i = 0; i <= item; i++) {
	  		if(i == (item)) { 
	  			return(ptr->data);
	  		}else {
	  			ptr = ptr->next;
	  		}
		}
	};
	
	Item_Type atpos(int pos){
		DNode *ptr = head;
		if (pos <= num_items){
			for(int i = 1; i <= pos; i++) {
				if(i == (pos)) {
					
					return(ptr->data);
				}
				else {
					ptr = ptr->next;
				}
			}
		}
	};
	Item_Type atCountBackPos(int posFromBack){
		DNode *ptr = head;
		while(ptr->next != NULL){
			ptr = ptr->next;
		}
		if (posFromBack <= num_items){
			for (int i = 1; i <= num_items; i++){
				if(i == posFromBack){
					return(ptr->data);
				}
				else{
					ptr = ptr->prev;
				}
			}
		}
	};
	
	int size(){
			return(num_items);
		};
	void clear(){
			while(head != NULL){
		        DNode *current = head;
		        head = head->next;
		        delete current;
		        num_items--;
		    }
			tail = NULL;
			head = NULL;
			num_items = 0;
			
		};
	string toString()	{
			if(head != NULL){
				stringstream mylist;
				DNode* current = head;
				while(current->next != NULL ){
					mylist << current->data << ", ";
					current = current->next;
				}
				mylist << current->data << endl;
				return (mylist.str());
			}
			else {
				string none = "Empty\n";
				return none;
			}
		};
};
    
#endif