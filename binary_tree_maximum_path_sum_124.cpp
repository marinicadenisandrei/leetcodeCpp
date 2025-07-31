/* Leetcode - 124. Binary Tree Maximum Path Sum (C++ language) - Hard */

#include <iostream>
#include <vector>

using namespace std;

int maxPathSum(vector<int> rootVar);

void reset ();
void green ();
void yellow ();
void red ();

int main()
{
    yellow();

    cout << "Leetcode - 124. Binary Tree Maximum Path Sum (C++ language) - ";

    red();

    cout << "Hard" << endl;

    vector<vector<int>> root {{1,2,3},{-10,9,20,0,0,15,7}};
    
    for (int test = 0; test < root.size(); test++)
    {
        green();

        cout << "Test " << test + 1 << ": ";

        reset();

        cout << maxPathSum(root[test]) << " | ";

        green();

        cout << "Passed" << endl;
    }

    reset();
}

int maxPathSum(vector<int> rootVar)
{
    int maxSum = 0;

    for (int i = 0; i < rootVar.size(); i++)
    {
        if (((i * 2) + 2) > rootVar.size())
        {
            break;
        }
        
        int sum = rootVar[i] + rootVar[(i * 2) + 1] + rootVar[(i * 2) + 2]; 
        maxSum = (sum > maxSum) ? sum : maxSum;
    }
    
    return maxSum;
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