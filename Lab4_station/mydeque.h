#pragma once
#include "list.h"
#include <iostream>
class mydeque {
  public:
    // Constructor and member functions
    mydeque() {}
    ~mydeque() {}
    
    void push_front(int item){
        cout << "push_front " << item << endl;
        mydequelist.insertHead(item);
    };
    void push_back(int item){
        cout << "push_back " << item << endl;
        mydequelist.insertTail(item);        
    };
    void pop_front(){
        cout << "pop_front() " <<  mydequelist.front();
        mydequelist.pop_front();
    };
    void pop_back(){
        cout << "pop_back() " <<  mydequelist.back();
//        mydequelist.remove(mydequelist.at(mydequelist.size()-1));
mydequelist.pop_back();
    };
    int front(){
        cout << "front() " << mydequelist.front() << endl;
        return mydequelist.front();
    };
    int back(){
        cout << "back() " << mydequelist.back() << endl;
        return mydequelist.back();
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
        list <int> mydequelist;
}; 


