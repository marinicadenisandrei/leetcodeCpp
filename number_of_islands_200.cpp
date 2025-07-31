/* Leetcode - 200. Number of Islands (C++ language) - Medium */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int numIslands(vector<vector<string>> gridVar);

void reset ();
void green ();
void yellow ();
void red ();

int main()
{
    yellow();

    cout << "Leetcode - 200. Number of Islands (C++ language) - Medium" << endl;

    vector<vector<vector<string>>> grid = {
        {{"1","1","1","1","0"},
        {"1","1","0","1","0"},
        {"1","1","0","0","0"},
        {"0","0","0","0","0"}},
        {{"1","1","0","0","0"},
        {"1","1","0","0","0"},
        {"0","0","1","0","0"},
        {"0","0","0","1","1"}}};

    for (int test = 0; test < grid.size(); test++)
    {   
        green();

        cout << "Test " << test + 1 << ": ";

        reset();

        cout << numIslands(grid[test]) << " | ";

        green();

        cout << "Passed" << endl;
    }

    reset();
}

int numIslands(vector<vector<string>> gridVar)
{
    int islands = 0;

    for (int i = 0; i < gridVar.size(); i++)
    {
        for (int j = 0; j < gridVar[i].size(); j++)
        {
            if (gridVar[i][j] == "1")
            {
                int col_start = j;
                int col_end = 0;

                int row_start = i;
                int row_end = 0;

                for (int k = col_start; k < gridVar[i].size(); k++)
                {
                    if (gridVar[i][k] == "0")
                    {
                        col_end = k;  
                        break; 
                    }
                }

                for (int k = i; k < gridVar.size(); k++)
                {
                    if (gridVar[k][j] == "0")
                    {
                        row_end = k; 
                        break;  
                    }
                }

                islands++;

                if (row_end == 0 & col_end == 0)
                {
                    continue;
                }

                i = row_end;
                j = col_end;
            }
        }
    }

    return islands;
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