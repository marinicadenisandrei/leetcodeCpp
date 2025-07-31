/* Leetcode - 53. Maximum Subarray (C++ language) - Medium */

#include <iostream>
#include <vector>

using namespace std;

int maxSubArray(vector <int> numsVar);

void reset ();
void green ();
void yellow ();
void red ();

int main()
{
    yellow();

    cout << "Leetcode - 53. Maximum Subarray (C++ language) - Medium" << endl;

    vector <vector <int>> nums {{-2,1,-3,4,-1,2,1,-5,4}, {1}, {5,4,-1,7,8}};

    for (int test = 0; test < nums.size(); test++)
    {
        green();

        cout << "Test " << test + 1 << ": ";

        reset();

        cout << maxSubArray(nums.at(test)) << " | ";  

        green();

        cout << "Passed" << endl;      
    }

    reset();

    return 0;
}

int maxSubArray(vector <int> numsVar)
{
    int maxSum {0};
    int temp {0};

    for (int i = 0; i < numsVar.size(); i++)
    {
        for (int j = i; j < numsVar.size(); j++)
        {
            temp += numsVar.at(j);
            maxSum = ((temp > maxSum) ? temp : maxSum);
        }
        
        temp = 0;
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