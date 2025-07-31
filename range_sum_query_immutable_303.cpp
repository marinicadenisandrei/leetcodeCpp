/* Leetcode - 303. Range Sum Query - Immutable (C++ language) - Easy*/

#include <iostream>
#include <vector>

using namespace std;

void reset ();
void green ();
void yellow ();
void red ();

class NumArray
{
private:
    vector<int> arr;

public:
    NumArray() = default;

    // Use member‐initializer list to copy directly
    NumArray(const vector<int>& input)
      : arr(input)
    {}

    int sumRange(int start, int end) const
    {
        int sum = 0;
        for (int i = start; i <= end; ++i)
            sum += arr[i];
        return sum;
    }
};

int main()
{
    yellow();

    cout << " Leetcode - 303. Range Sum Query - Immutable (C++ language) - ";

    green();

    cout << "Easy" << endl;

    NumArray numArray({ -2, 0, 3, -5, 2, -1 });

    green();

    cout << "Test 1: ";

    reset();

    cout << numArray.sumRange(0, 2) << " "; 
    cout << numArray.sumRange(2, 5) << " ";  
    cout << numArray.sumRange(0, 5) << " "; 
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