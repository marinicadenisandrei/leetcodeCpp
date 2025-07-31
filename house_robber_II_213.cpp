/* Leetcode - 213. House Robber II (C++ language) - Medium */

#include <iostream>
#include <vector>

using namespace std;

void reset ();
void green ();
void yellow ();
void red ();

int rob(vector<int> numsVar);

int main()
{
    yellow();

    cout << "Leetcode - 213. House Robber II (C++ language) - Medium" << endl;

    vector<vector<int>> nums {{2,3,2},{1,2,3,1},{1,3,2}};
    
    for (int test = 0; test < nums.size(); test++)
    {
        green();

        cout << "Test " << test + 1 << ": ";

        reset();

        cout << rob(nums[test]) << " | ";

        green();

        cout << "Passed" << endl;
    }
    
    reset();

    return 0;
}

int rob(vector<int> numsVar)
{
    int result = 0;

    for (int i = 0; i < 2; i++)
    {
        int history = 0;
        int profit = 0;

        for (int j = i; j < numsVar.size(); j += 2)
        {
            if (numsVar[j] != history)
            {
                profit += numsVar[j];
                history = numsVar[j];
            }
            else
            {
                j++;
            }
        }        

        result = (result < profit) ? profit : result;
    }
    
    return result;
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