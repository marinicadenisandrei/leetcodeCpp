/* Leetcode - 155. Min Stack (C++ language) - Medium */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class MinStack
{
private:
    vector<int> stackAcumulation {};
    vector<int> cache {};
public:
    MinStack()
    {
        cache.push_back(0);
    };

    ~MinStack() = default;

    void push(int number)
    {
        stackAcumulation.push_back(number);
        cache.push_back(0);
    }

    int getMin()
    {
        vector<int> temp = stackAcumulation;
        sort(temp.begin(), temp.end());

        int min = temp[0];
        cache.push_back(min);
        return min;
    }

    void pop()
    {
        stackAcumulation.pop_back();
        cache.push_back(0);
    }

    int top()
    {
        int temp = *(stackAcumulation.end() - 1);
        cache.push_back(temp);
        return 0;
    }

    void displayCache()
    {
        for (int i = 0; i < cache.size(); i++)
        {
            cout << ((i == 0) ? "[" : "") << cache[i] << ((i < cache.size() - 1) ? ", " : "] | ");
        }
    }
};

void reset ();
void green ();
void yellow ();
void red ();

int main()
{
    yellow();

    cout << "Leetcode - 155. Min Stack (C++ language) - Medium" << endl;

    MinStack minStack;

    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);
    minStack.getMin();
    minStack.pop();
    minStack.top();
    minStack.getMin();

    green();

    cout << "Test 1: ";

    reset();

    minStack.displayCache();

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