#pragma once
#include "list.h"
class myIRdeque {
  public:
    // Constructor and member functions
    myIRdeque() {}
    ~myIRdeque() {}
    
    void push_front(int item){
        cout << "push_front " << item << endl;
        myIRdequelist.insertHead(item);
    };
    void pop_front(){
        cout << "pop_front() " <<  myIRdequelist.front();
        myIRdequelist.pop_front();
    };
    void pop_back(){
        cout << "pop_back() " <<  myIRdequelist.back();
        myIRdequelist.pop_back();        
    };
    int front(){
        cout << "front() " << myIRdequelist.front() << endl;
        return myIRdequelist.front();
    };
    int back(){
        cout << "back() " << myIRdequelist.back() << endl;
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
        list <int> myIRdequelist;
}; 


