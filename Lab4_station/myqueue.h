#pragma once
#include "list.h"
class myqueue {
  public:
    // Constructor and member functions
    myqueue() {}
    ~myqueue() {}
    void push(int item){
        cout << "Push " << item << endl;
        myqueuelist.insertTail(item);
    };
    int front(){
        cout << "front() " << myqueuelist.front() << endl;
        return myqueuelist.front();
    };
    void pop(){
        cout << "pop() " <<  myqueuelist.front();
        myqueuelist.pop_front();
    };
    bool empty(){
        if (size >= 1){
            return false;
        }
        else{
            return true;
        }
    }
    int size = 0;
    private:
      // Data fields
      
      list <int> myqueuelist;
}; // End class stack

