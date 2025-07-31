/* Leetcode - 27. Remove Element (C++ language) - Easy */

#include <iostream>
#include <vector>

using namespace std;

void removeElement(vector<int>& nums, int val);
void printVector(const vector<int>& nums);

void reset ();
void green ();
void yellow ();
void red ();

int main()
{
    yellow();

    cout << "Leetcode - 27. Remove Element (C++ language) - ";

    green();

    cout << "Easy" << endl;

    vector <vector<int>> nums {{3, 2, 2, 3}, {0,1,2,2,3,0,4,2}};
    vector <int> val {3, 2};

    for (int test = 0; test < nums.size(); test++)
    {
        green();

        cout << "Test " << test + 1 << ": ";

        reset();

        removeElement(nums.at(test), val.at(test));

        green();

        cout << "Passed" << endl;
    }

    reset();
    
    return 0;
}

void removeElement(vector<int>& nums, int val)
{
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums.at(i) == val)
        {
            nums.erase(nums.begin() + i);
        }
    }

    printVector(nums);
}

void printVector(const vector<int>& nums)
{
    for (int i = 0; i < nums.size(); i++)
    {
        cout << ((i == 0) ? "[" : "") << nums.at(i) << ((i < nums.size() - 1) ? ", " : "] | ");
    }
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