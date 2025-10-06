/* Leetcode - 334. Increasing Triplet Subsequence (C++ language) - Medium */

#include <iostream>
#include <vector>

using namespace std;

void reset ();
void green ();
void yellow ();
void red ();

bool increasingTriplet(vector<int> numsVar);

int main()
{
    yellow();
    
    cout << boolalpha;

    cout << "Leetcode - 334. Increasing Triplet Subsequence (C++ language) - Medium" << endl;

    vector<vector<int>> nums = {{1,2,3,4,5},{5,4,3,2,1},{2,1,5,0,4,6}};

    for (int test = 0; test < nums.size(); test++)
    {
        green();

        cout << "Test " << test + 1 << ": ";

        reset();

        cout << increasingTriplet(nums[test]) << " | ";

        green();

        cout << "Passed" << endl;
    }

    reset();

    return 0;
}

bool increasingTriplet(vector<int> numsVar)
{
    for (int i = 0; i < numsVar.size() - 2; i++)
    {
        if (numsVar[i] < numsVar[i + 1] && numsVar[i + 1] < numsVar[i + 2])
        {
            return true;
        }
    }

    return false;
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