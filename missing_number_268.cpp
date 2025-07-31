/* Leetcode - 268. Missing Number (C language) - Easy */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void reset ();
void green ();
void yellow ();
void red ();

int missingNumber(vector<int> numsVar);

int main()
{   
    yellow();

    cout << "Leetcode - 268. Missing Number (C language) - ";

    green();

    cout << "Easy" << endl;

    vector<vector<int>> nums {{3,0,1},{0,1},{9,6,4,2,3,5,7,0,1}};
    
    for (int test = 0; test < nums.size(); test++)
    {
        green();

        cout << "Test " << test + 1 << ": ";

        reset();

        cout << missingNumber(nums[test]) << " | ";

        green();

        cout << "Passed" << endl;
    }
    

    reset();

    return 0;
}

int missingNumber(vector<int> numsVar)
{
    sort(numsVar.begin(), numsVar.end());

    for (int i = 0; i < numsVar.size() - 1; i++)
    {
        if (numsVar[i + 1] - numsVar[i] > 1)
        {
            return numsVar[i] + 1;
        }
    }
    
    return numsVar[numsVar.size() - 1] + 1;
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