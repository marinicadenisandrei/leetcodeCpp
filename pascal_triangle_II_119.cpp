/* Leetcode - 119. Pascal's Triangle (C++ language) - Easy */

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

    cout << "Leetcode - 119. Pascal's Triangle (C++ language) - ";

    green();

    cout << "Easy" << endl;

    vector<int> numRows = {3,0,1};

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
  for (int j = 0; j < vectorVar[depth].size(); j++)
  {
      cout << ((j == 0) ? "[" : "") << vectorVar[depth][j] << ((j < vectorVar[depth].size() - 1) ? ", " : "] | ");
  }   
}

vector<vector<int>> generate(int numRowsVar)
{
    vector<vector<int>> acumulation {};
    acumulation.push_back(vector <int> {1});
    acumulation.push_back(vector<int> {1,1});

    for (int i = 0; i <= numRowsVar; i++)
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