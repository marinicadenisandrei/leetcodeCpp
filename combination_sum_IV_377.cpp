/* Leetcode - 377. Combination Sum IV (C++ language) - Medium */

#include <iostream>
#include <vector>

using namespace std;

void reset ();
void green ();
void yellow ();
void red ();

int combinationSum4(vector<int> numsVar, int targetVar);

int main()
{
    yellow();
    
    cout << "Leetcode - 377. Combination Sum IV (C++ language) - Medium\n";

    vector<vector<int>> nums = {{1,2,3},{9}};
    vector<int> target = {4,1};
    
    for (int test = 0; test < nums.size(); test++)
    {
        green();

        cout << "Test " << test + 1 << ": ";

        reset();

        cout << combinationSum4(nums[test], target[test]) << " | ";

        green();

        cout << "Passed\n";
    }

    reset();
}

int combinationSum4(vector<int> numsVar, int targetVar)
{
    int result = 0;

    for (int i = 0; i < numsVar.size(); i++)
    {
        int mulValue = targetVar / numsVar[i];
        int tempSum = 0;

        vector<int> acc = {};

        for (int j = 0; j < mulValue; j++)
        {
            acc.push_back(numsVar[i]); 
            tempSum += numsVar[i];  
        }

        if (tempSum == targetVar)
        {
            result++;   
        }

        while (acc.size() > 2)
        {
            vector<int> temp = {};
            temp.push_back(acc[0] + acc[1]);
            
            for (int j = 2; j < acc.size(); j++)
            {
                temp.push_back(acc[j]);
            }
            
            acc = temp;
            result += acc.size();
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