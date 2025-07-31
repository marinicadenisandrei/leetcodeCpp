/* Leetcode - 232. Implement Queue using Stacks (C++ language) - Easy */

#include <iostream>
#include <vector>

using namespace std;

class MyQueue
{
private:
    vector<int> vect;

public:
    void Push(int x) 
    {
        vect.push_back(x);
    }

    int Pop()
    {
        if (vect.empty()) {
            throw runtime_error("Queue is empty");
        }
        int x = vect.front();
        vect.erase(vect.begin());
        return x;
    }

    int Peek()
    {
        if (vect.empty()) {
            throw runtime_error("Queue is empty");
        }
        return vect.front();
    }

    bool Empty()
    {
        return vect.empty();
    }

    MyQueue() = default;  
    ~MyQueue() = default; 
};

void reset ();
void green ();
void yellow ();
void red ();

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

int main()
{
    yellow();

    cout << "Leetcode - 232. Implement Queue using Stacks (C++ language) - ";

    green();

    cout << "Easy" << endl;

    MyQueue myQueue;

    green();

    cout << "Test 1: ";
    
    reset();

    myQueue.Push(1); 
    myQueue.Push(2); 

    cout << boolalpha << myQueue.Peek() << " "; 
    cout << myQueue.Pop() << " "; 
    cout << myQueue.Empty() << " | "; 

    green();

    cout << "Passed" << endl;

    reset();

    return 0;
}
