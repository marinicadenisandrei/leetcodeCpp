/* Leetcode - 368. Largest Divisible Subset (C++ language) - Medium */

#include <iostream>
#include <vector>

using namespace std;

void reset ();
void green ();
void yellow ();
void red ();

vector<int> largestDivisibleSubset(vector<int> numsVar);
void printVector(vector<int> vect);

int main()
{
    yellow();

    cout << "Leetcode - 368. Largest Divisible Subset (C++ language) - Medium" << endl;

    vector<vector<int>> nums = {{1,2,3},{1,2,4,8}};
    
    for (int test = 0; test < nums.size(); test++)
    {
        green();

        cout << "Test " << test + 1 << ": ";

        reset();

        printVector(largestDivisibleSubset(nums[test]));
    
        green();

        cout << "Passed" << endl;
    }
    
    reset();

    return 0;
}

void printVector(vector<int> vect)
{
    for (int i = 0; i < vect.size(); i++)
    {
        cout << ((i == 0) ? "[" : "") << vect[i] << ((i < vect.size() - 1) ? ", " : "] | ");
    }
}

vector<int> largestDivisibleSubset(vector<int> numsVar)
{
    vector<int> result = {};

    for (int i = 0; i < numsVar.size() - 1; i++)
    {
        vector<int> temp = {numsVar[i]};

        for (int j = i + 1; j < numsVar.size(); j++)
        {
            if (numsVar[j] % temp[temp.size() - 1] == 0)
            {
                temp.push_back(numsVar[j]);
            }
        }

        if (result.size() < temp.size())
        {
            result = temp;
        }
    }

    return result;
}

void reset () {
  printf("\033[1;0m");
}

void green () {
  printf("\033[1;32m");
}

void yellow () {
  printf("\033[1;33m");
}

void red () {
  printf("\033[1;31m");
}