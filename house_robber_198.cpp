/* Leetcode - 198. House Robber (C++ language) - Medium */

#include <iostream>
#include <vector>

using namespace std;

int rob(vector<int> numsVar);

void reset ();
void green ();
void yellow ();
void red ();

int main()
{
    yellow();

    cout << "Leetcode - 198. House Robber (C++ language) - Medium" << endl;

    vector<vector<int>> nums {{1,2,3,1},{2,7,9,3,1}};

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
    int maxVar {0};

    for (int i = 0; i < 2; i++)
    {
        int sumVar {0};

        for (int j = i; j < numsVar.size(); j += 2)
        {
            sumVar += numsVar[j];
        }

        maxVar = ((maxVar < sumVar) ? sumVar : maxVar);
    }

    return maxVar;
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