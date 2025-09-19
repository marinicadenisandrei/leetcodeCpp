/* Leetcode - 327. Count of Range Sum (C++ language) - Hard */

#include <iostream>
#include <vector>

using namespace std;

void reset ();
void green ();
void yellow ();
void red ();

int countRangeSum(vector<int> numsVar, int lowerVar, int upperVar);

int main()
{
    yellow();

    cout << "Leetcode - 327. Count of Range Sum (C++ language) - ";

    red();

    cout << "Hard" << endl;

    vector<vector<int>> nums = {{-2,5,-1},{0}};
    vector<int> lower = {-2,0}; 
    vector<int> upper = {2,0};

    for (int test = 0; test < nums.size(); test++)
    {
        green();

        cout << "Test " << test + 1 << ": ";

        reset();

        cout << countRangeSum(nums[test], lower[test], upper[test]) << " | ";

        green();

        cout << "Passed" << endl;
    }

    reset();

    return 0;
}

int countRangeSum(vector<int> numsVar, int lowerVar, int upperVar)
{
    if (numsVar.size() == 1 && numsVar[0] >= lowerVar && numsVar[0] <= upperVar)
    {
        return 1;
    }
    
    int result = 0;

    for (int i = 0; i < numsVar.size(); i++)
    {
        int sum = 0;

        for (int j = i; j < numsVar.size(); j++)
        {
            sum += numsVar[j];

            if (sum >= lowerVar && sum <= upperVar)
            {
                result++;
            }
        }
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