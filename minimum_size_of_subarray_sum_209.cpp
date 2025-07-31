/* Leetcode - 209. Minimum Size Subarray Sum (C++ language) - Medium */

#include <iostream>
#include <vector>

using namespace std;

int minSubArrayLen(int targetVar, vector<int> numVar);

void reset ();
void green ();
void yellow ();
void red ();

int main()
{
    yellow();

    cout << "Leetcode - 209. Minimum Size Subarray Sum (C++ language) - Medium" << endl;

    vector<int> target {7,4,11};
    vector<vector<int>> num = {{2,3,1,2,4,3},{1,4,4},{1,1,1,1,1,1,1,1}};

    for (int test = 0; test < target.size(); test++)
    {
        green();

        cout << "Test " << test + 1 << ": ";

        reset();

        cout << minSubArrayLen(target[test], num[test]) << " | ";

        green();

        cout << "Passed" << endl;
    }

    reset();
}

int minSubArrayLen(int targetVar, vector<int> numVar)
{
    int sumVar = numVar.size();

    for (int i = 0; i < numVar.size(); i++)
    {
        int sumTemp = 0;

        for (int j = i; j < numVar.size(); j++)
        {
            sumTemp += numVar[j];

            if (sumTemp == targetVar && sumVar > j - i + 1)
            {
                sumVar = j - i + 1;
            }   
        }
    }

    if (sumVar == numVar.size())
    {
        return 0;
    }
    
    return sumVar;
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