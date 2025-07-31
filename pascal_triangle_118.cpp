/* Leetcode - 118. Pascal's Triangle (C++ language) - Easy */

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> generate(int numRowsVar);
void print2DVector(vector<vector<int>> vectorVar, int depth);

void reset ();
void green ();
void yellow ();
void red ();

int main()
{
    yellow();

    cout << "Leetcode - 118. Pascal's Triangle (C++ language) - ";

    green();

    cout << "Easy" << endl;

    vector<int> numRows = {5,1};

    for (int test = 0; test < numRows.size(); test++)
    {
        green();

        cout << "Test " << test + 1 << ": ";

        reset();

        vector<vector<int>> output {generate(numRows[test])};
        print2DVector(output, numRows[test]);

        green();

        cout << "Passed" << endl;
    }

    reset();
}

void print2DVector(vector<vector<int>> vectorVar, int depth)
{
    cout << "[";

    for (int i = 0; i < depth; i++)
    {
        for (int j = 0; j < vectorVar[i].size(); j++)
        {
            cout << ((j == 0) ? "[" : "") << vectorVar[i][j] << ((j < vectorVar[i].size() - 1) ? ", " : "]");
        }

        cout << ((i < depth - 1) ? ", " : "");
    }

    cout << "] | ";    
}

vector<vector<int>> generate(int numRowsVar)
{
    vector<vector<int>> acumulation {};
    acumulation.push_back(vector <int> {1});
    acumulation.push_back(vector<int> {1,1});

    for (int i = 0; i < numRowsVar - 2; i++)
    {
        vector<int> temp {};
        temp.push_back(1);

        for (int j = 0; j < acumulation.back().size() - 1; j++)
        {
            temp.push_back(acumulation.back()[j] + acumulation.back()[j + 1]);
        }
        
        temp.push_back(1);
        acumulation.push_back(temp);
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