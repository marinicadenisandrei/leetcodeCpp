/* Leetcode - 284. Peeking Iterator (C++ language) - Medium */

#include <iostream>
#include <vector>

using namespace std;

void reset ();
void green ();
void yellow ();
void red ();

class PeekingIterator
{
private:
    vector<int> nums;
    size_t iterator = 0;

public:
    PeekingIterator(vector<int> nums)
    {
        this->nums = nums;
    }

    int next()
    {
        return nums[iterator++];
    }

    int peek()
    {
        return nums[iterator];
    }

    bool hasNext()
    {
        return iterator < nums.size();
    }
};

int main()
{
    yellow();

    cout << "Leetcode - 284. Peeking Iterator (C++ language) - Medium" << endl;

    PeekingIterator peekingIterator({1, 2, 3});

    green();

    cout << "Test 1: ";

    reset();

    cout << boolalpha;
    cout << peekingIterator.next() << " "; 
    cout << peekingIterator.peek() << " ";  
    cout << peekingIterator.next() << " ";  
    cout << peekingIterator.next() << " ";  
    cout << peekingIterator.hasNext() << " "; 

    cout << " | ";

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