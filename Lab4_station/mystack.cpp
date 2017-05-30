#include "mystack.h"
#include <iostream>
using namespace std;
void mystack::push(int item)
{
    cout << "Push "<<item<<endl;
    mystacklist.insertHead(item);
}
int mystack::top()
{
    cout << "top() "<<mystacklist.front()<<endl;
    mystacklist.front();
}
void mystack::pop()
{
    cout << "pop() "<<mystacklist.front()<<endl;
    mystacklist.pop_front();
}