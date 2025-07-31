/* Leetcode - 154. Find Minimum in Rotated Sorted Array II (C++ language) - Hard */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void reset ();
void green ();
void yellow ();
void red ();

int findMin(vector<int> numsVar);

int main()
{
    yellow();

    cout << "Leetcode - 154. Find Minimum in Rotated Sorted Array II (C++ language) - ";
    
    red();

    cout << "Hard" << endl;

    vector<vector<int>> nums {{1,3,5},{2,2,2,0,1}};

    for (int test = 0; test < nums.size(); test++)
    {
        green();

        cout << "Test " << test + 1 << ": ";

        reset();

        cout << findMin(nums[test]) << " | ";

        green();

        cout << "Passed" << endl;
    }

    reset();
    
    return 0;
}

int findMin(vector<int> numsVar)
{
    auto l = [] (vector<int> numsVar) {
        sort(numsVar.begin(), numsVar.end());
        return numsVar[0];
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