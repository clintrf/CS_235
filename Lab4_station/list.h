#ifndef LIST_H_
#define LIST_H_

#include <iostream>
#include <stdexcept>
#include <cstddef>
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
    }
    ~list() {
      while (head != NULL) {
      	DNode* current = head;
      	head = head->next;
      	delete current;
      }
      tail = NULL;
      num_items = 0;
    }
    void insertHead(const Item_Type& item) {
      head = new DNode(item, NULL, head);
      if (head->next != NULL)
      	head->next->prev = head; 
      if (tail == NULL)    
      	tail = head;
        num_items++;
    }
    void insertTail(const Item_Type& item) {
      if (tail != NULL) {
      	tail->next = new DNode(item, tail, NULL);
      	tail = tail->next; 
      	num_items++;
      } else {        
      	insertHead(item);
      }
    }
    
    Item_Type front() {
      if(head != NULL && num_items != 0)
        return head->data;
      else
        return -1;
    }
    Item_Type back(){
      if(tail != NULL)
        return tail->data;
      else
        return -1;
    }
    
    void pop_front() {
      if(head != NULL) {
        DNode *temp = head;
        head = head->next;
        if(head == NULL)
          tail = NULL;
          num_items--;
      }
    }
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
    
    }
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
			if(current->data == item){
				head = current->next;
				delete current;
				num_items--;
			}
			else{
				while(current->next->data != item){
					current = current->next;
				}
				DNode* tempPtr= current->next;
				current->next = tempPtr->next;
				delete tempPtr;
				num_items--;
			}
		}
	};
	
		Item_Type at(const Item_Type& item){
		//   		if(item >= num_items || item < 0) {
		// 	throw std::out_of_range("error");
		// } 
			DNode *ptr = head;
			for(int i = 0; i <= item; i++) {
		  		if(i == (item)) { 
		  			return(ptr->data);
		  		}else {
		  			ptr = ptr->next;
		  		}
			}
		}
	int size(){
		return(num_items);
	};
};
    
#endif
