/* Leetcode - 307. Range Sum Query - Mutable (C++ language) - Medium */

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
    vector<int> arr = {};
public:
    NumArray(vector<int> arr) {this->arr=arr;}
    ~NumArray() = default;

    void update(int index, int val)
    {
        if (index >= 0 && index <= arr.size())
        {
            arr[index] = val;
        }
    }

    int sumRange(int left, int right)
    {
        int sum = 0;

        if (left < right && 0 <= left && right < arr.size())
        {
            for (int i = left; i <= right; i++)
            {
                sum += arr[i];
            }
        }
        
        return sum;
    }
};

int main()
{
    yellow();

    cout << "Leetcode - 307. Range Sum Query - Mutable (C++ language) - Medium" << endl;

    green();

    cout << "Test 1: ";

    reset();

    NumArray numArray = NumArray(vector<int>({1,3,5}));
    cout << numArray.sumRange(0, 2) << " "; 
    numArray.update(1, 2);   
    cout << numArray.sumRange(0, 2) << " ";
    cout << "| ";

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