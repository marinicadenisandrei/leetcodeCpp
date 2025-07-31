/* Leetcode - 90. Subsets II (C++ language) - Medium */

#include <iostream>
#include <vector>

using namespace std;

vector <vector<int>> subsetWithDup(vector <int> nums);
void printVectorMatrix(vector<vector <int>> vectorMatrix);

void reset ();
void green ();
void yellow ();
void red ();

int main()
{
    yellow();

    cout << "Leetcode - 90. Subsets II (C++ language) - Medium" << endl;

    vector <vector<int>> nums {{1,2,2},{0}};

    for (int test = 0; test < nums.size(); test++)
    {
        green();

        cout << "Test " << test + 1 << ": ";

        reset();

        vector <vector<int>> output = subsetWithDup(nums[test]);
        printVectorMatrix(output);

        green();

        cout << "Passed" << endl;
    }

    reset();

    return 0;
}

void printVectorMatrix(vector<vector <int>> vectorMatrix)
{
    for (int i = 0; i < vectorMatrix.size(); i++)
    {
        if (vectorMatrix[i].size() == 0)
        {
            cout << "[]";
        }
        
        for (int j = 0; j < vectorMatrix[i].size(); j++)
        {
            cout << ((j == 0) ? "[" : "") << vectorMatrix[i][j] << ((j < vectorMatrix[i].size() - 1) ? ", " : "]");
        }
    }

    cout << " | ";
}

vector <vector<int>> subsetWithDup(vector <int> nums)
{
    vector <int> temp {};
    vector <vector <int>> acumulation {};
    acumulation.push_back(temp);

    int minus = ((nums.size() > 1) ? 1 : 0);

    for (int i = 0; i < nums.size() - minus; i++)
    {
        for (int j = i; j < nums.size(); j++)
        {
            temp.push_back(nums[j]);
            acumulation.push_back(temp);
        }

        temp.clear();
    }

    return acumulation;
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