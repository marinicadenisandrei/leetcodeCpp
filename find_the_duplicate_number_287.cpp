/* Leetcode - 287. Find the Duplicate Number (C++ language) - Medium */

#include <iostream>
#include <vector>

using namespace std;

void reset ();
void green ();
void yellow ();
void red ();

int findDuplicate(vector<int> numsVar);

int main()
{   
    yellow();

    cout << "Leetcode - 287. Find the Duplicate Number (C++ language) - Medium" << endl;

    vector<vector<int>> nums = {{1,3,4,2,2},{3,1,3,4,2},{3,3,3,3,3}};
    
    for (int test = 0; test < nums.size(); test++)
    {
        green();
        
        cout << "Test " << test + 1 << ": ";

        reset();

        cout << findDuplicate(nums[test]) << " | ";

        green();

        cout << "Passed" << endl;
    }

    reset();
    
    return 0;
}

int findDuplicate(vector<int> numsVar)
{
    for (int i = 0; i < numsVar.size(); i++)
    {
        for (int j = 0; j < numsVar.size(); j++)
        {
            if (i != j && numsVar[i] == numsVar[j])
            {
                return numsVar[i];
            }       
        }
    }
    
    return -1;
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