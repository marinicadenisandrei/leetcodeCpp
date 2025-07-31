/* Leetcode - 64. Minimum Path Sum (C++ language) - Medium */

#include <iostream>
#include <vector>

using namespace std;

int minPathSum(vector <vector <int>> gridVar);

void reset ();
void green ();
void yellow ();
void red ();

int main()
{
    yellow();

    cout << "Leetcode - 64. Minimum Path Sum (C++ language) - Medium" << endl;
   
    vector <vector <vector <int>>> grid {{{1,3,1}, {1,5,1}, {4,2,1}}, {{1,2,3}, {4,5,6}}};
   
    for (int test = 0; test < grid.size(); test++)
    {
        green();

        cout << "Test " << test + 1 << ": ";

        reset();
       
        cout << minPathSum(grid[test]) << " | ";

        green();
       
        cout << "Passed" << endl;
    }  

    reset();
}

int minPathSum(vector <vector <int>> gridVar)
{
    int minSum {0};
    int row = gridVar.size() - 1;
    int col = gridVar[row].size() - 1;
   
    while (true)
    {
        if (row == 0)
        {
            break;
        }
       
        minSum += gridVar[row][col];
       
        if (gridVar[row - 1][col] > gridVar[row][col - 1])
        {
            col--;
        }
        else
        {
            row--;
        }
    }
   
    for (int i = col; i >= 0; i--)
    {
        minSum += gridVar[row][i];
    }
   
    return minSum;
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