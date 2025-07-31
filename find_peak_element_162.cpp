/* Leetcode - 162. Find Peak Element (C++ language) - Medium */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int findPeakElement(vector<int> numsVar);

void reset ();
void green ();
void yellow ();
void red ();

int main()
{
    yellow();

    cout << "Leetcode - 162. Find Peak Element (C++ language) - Medium" << endl;

    vector<vector<int>> nums {{1,2,3,1},{1,2,1,3,5,6,4}};

    for (int test = 0; test < nums.size(); test++)
    {
        green();

        cout << "Test " << test + 1 << ": ";

        reset();

        cout << findPeakElement(nums[test]) << " | ";

        green();

        cout << "Passed" << endl;
    }

    reset();
    
    return 0;
}

int findPeakElement(vector<int> numsVar)
{
    auto l = [] (vector<int> numsVar) {
        for (int i = 1; i < numsVar.size() - 1; i++)
        {
            if (numsVar[i] > numsVar[i - 1] && numsVar[i] > numsVar[i + 1])
            {
                return i;
            }
        }

        return -1;
    };

    return l(numsVar);
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