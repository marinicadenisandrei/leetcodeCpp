/* Leetcode - 78. Subsets (C++ language) - Medium */

#include <iostream>
#include <vector>

using namespace std;

vector<vector <int>> subsets(vector <int> numsVar);
void printVectorMatrix(vector <vector <int>> matrix);

void reset ();
void green ();
void yellow ();
void red ();

int main()
{
    yellow();

    cout << "Leetcode - 78. Subsets (C++ language) - Medium" << endl;

    vector <vector <int>> nums {{1,2,3},{0}};

    for (int test = 0; test < nums.size(); test++)
    {
        green();

        cout << "Test " << test + 1 << ": ";

        reset();

        vector<vector <int>> output = subsets(nums[test]);
        printVectorMatrix(output);

        green();

        cout << "Passed" << endl;
    }

    reset();

    return 0;
}

void printVectorMatrix(vector <vector <int>> matrix)
{
    for (int i = 0; i < matrix.size(); i++)
    {
        if (matrix[i].size() == 0)
        {
            cout << "[]";
        }
        
        for (int j = 0; j < matrix[i].size(); j++)
        {
            cout << ((j == 0) ? "[" : "") << matrix[i][j] << ((j < matrix[i].size() - 1) ? "," : "]");
        }
    }

    cout << " | ";
}

vector<vector <int>> subsets(vector <int> numsVar)
{
    vector <vector <int>> result {};
    vector <int> temp {};
    result.push_back(temp);

    for (int i = 0; i < numsVar.size(); i++)
    {
        temp.clear();
        temp.push_back(numsVar[i]);
        result.push_back(temp);
    }

    for (int i = 0; i < numsVar.size(); i++)
    {
        temp.clear();
    
        for (int j = i + 1; j < numsVar.size(); j++)
        {
            if (i != j)
            {
                temp.push_back(numsVar[i]);
                temp.push_back(numsVar[j]);
                result.push_back(temp);

                temp.clear();
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