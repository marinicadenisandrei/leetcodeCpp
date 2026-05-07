/* Leetcode - 368. Largest Divisible Subset (C++ language) - Medium */

#include <iostream>
#include <vector>
#include <algorithm>

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

    for (int i = numsVar.size() - 1; i >= 1; i--)
    {
        vector<int> tempVector = {};
        tempVector.push_back(numsVar[i]);
        int temp = numsVar[i];

        for (int j = i - 1; j >= 0; j--)
        {
            if (temp % numsVar[j] == 0)
            {
                temp = numsVar[j];
                tempVector.push_back(temp);
            }
        }


        if (result.size() < tempVector.size())
        {
            result = tempVector;
        }
    }

    std::sort(result.begin(), result.end());

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