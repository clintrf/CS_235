#pragma once
#include "list.h"
class mystack {
  public:
    // Constructor and member functions
    mystack() {}
    ~mystack() {}

    /** Pushes an item onto the top of the stack.
        @param item The item to be inserted
    */
    void push(int item);

    /** Returns the top of the stack 
        without removing it.
        @return A reference to the object at the top of the stack
    */
    int top();

    /** Removes the top item from the stack. */
    void pop();

    private:
      // Data fields
      list <int> mystacklist;
}; // End class stack

