#pragma once
#include "list.h"
class myORdeque {
  public:
    // Constructor and member functions
    myORdeque() {}
    ~myORdeque() {}
    
    void push_front(int item){
        cout << "push_front " << item << endl;
        myORdequelist.insertHead(item);
    };
    void push_back(int item){
        cout << "push_back " << item << endl;
        myORdequelist.insertTail(item);        
    };
    void pop_front(){
        cout << "pop_front() " <<  myORdequelist.front();
        myORdequelist.pop_front();
    };
    int front(){
        cout << "front() " << myORdequelist.front() << endl;
        return myORdequelist.front();
    };
    int back(){
        cout << "back() " << myORdequelist.back() << endl;
    };
    bool empty(){
        if (size >= 1){
            return false;
    }
        else{
            return true;
        }
    };
    int size = 0;
    private:
        list <int> myORdequelist;
}; 


