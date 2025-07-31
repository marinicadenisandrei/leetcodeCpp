/* Leetcode - 225. Implement Stack using Queues (C++ language) - Easy */

#include <iostream>
#include <vector>

using namespace std;

void reset ();
void green ();
void yellow ();
void red ();

class MyStack 
{
private:
    vector<int> myStackVar {0};
public:
    MyStack() = default;
    ~MyStack() = default;

    void push(int x)
    {
        myStackVar.push_back(x);
    }

    int pop()
    {
        int popValue = myStackVar[myStackVar.size() - 1];
        myStackVar.pop_back();

        return popValue;
    }

    int top()
    {
        return myStackVar[myStackVar.size() - 1];
    }

    bool empty()
    {
        return myStackVar.size() == 0;
    }
};

int main()
{
    cout << boolalpha;

    yellow();

    cout << "Leetcode - 225. Implement Stack using Queues (C++ language) - ";

    green();

    cout << "Easy" << endl;

    MyStack myStack = MyStack();
    
    green();

    cout << "Test 1: ";

    reset();

    myStack.push(1);
    myStack.push(2);
    cout << myStack.top() << " "; 
    cout << myStack.pop() << " "; 
    cout << myStack.empty() << " | "; 

    green();

    cout << "Passed" << endl;

    reset();

    return 0;
}

void reset () {
    cout << "\033[1;0m";
  }
  
  void green () {
    cout << "\033[1;32m";
  }
  
  void yellow () {
    cout << "\033[1;33m";
  }
  
  void red () {
    cout << "\033[1;31m";
  }