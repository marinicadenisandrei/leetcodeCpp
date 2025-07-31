/* Leetcode - 130. Surrounded Regions (C++ language) - Medium */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve(vector<vector<string>> &boardVar);
void print2DVector(const vector<vector<string>> &boardVar);

void reset ();
void green ();
void yellow ();
void red ();

int main()
{
    yellow();

    cout << "Leetcode - 130. Surrounded Regions (C++ language) - Medium" << endl;

    vector<vector<vector<string>>> board {{{"X","X","X","X"},{"X","O","O","X"},{"X","X","O","X"},{"X","O","X","X"}},{{"X"}}};
    
    for (int test = 0; test < board.size(); test++)
    {
        green();

        cout << "Test " << test + 1 << ": ";

        reset();

        solve(board[test]);
        print2DVector(board[test]);

        green();

        cout << "Passed" << endl;
    }

    reset();

    return 0;
}

void print2DVector(const vector<vector<string>> &boardVar)
{
    cout << "[";

    for (int i = 0; i < boardVar.size(); i++)
    {
        for (int j = 0; j < boardVar[i].size(); j++)
        {
            cout << ((j == 0) ? "[" : "") << boardVar[i][j] << ((j < boardVar[i].size() - 1) ? ", " : "]");
        }
    }

    cout << "] | ";
}

void solve(vector<vector<string>> &boardVar)
{
    vector<vector<int>> indexesO {};
    vector<vector<int>> indexesX {};

    for (int i = 0; i < boardVar.size(); i++)
    {
        for (int j = 0; j < boardVar[i].size(); j++)
        {
            if (boardVar[i][j] == "X")
            {
                indexesX.push_back(vector<int> {i,j});
            }
            else
            {
                indexesO.push_back(vector<int> {i,j});
            }
        }
    }

    if (indexesO.size() == 0)
    {
        return;
    }
    
    vector<vector<int>> candidates {};

    for (int i = 0; i < indexesO.size() - 1; i++)
    {
        if ((abs(indexesO[i][0] - indexesO[i + 1][0]) == 1 || abs(indexesO[i][1] - indexesO[i + 1][1]) == 1) && (abs(indexesO[i][0] - indexesO[i + 1][0]) + abs(indexesO[i][1] - indexesO[i + 1][1])) < 3)
        {
            candidates.push_back(vector<int>{indexesO[i][0],indexesO[i][1]});
        }
        else
        {
            for (int i = 0; i < candidates.size(); i++)
            {
                cout << candidates[i][0] << " " << candidates[i][1] << endl;
            }

            break;
        }
    }

    vector<vector<int>> x_candidates {};

    for (int i = 0; i < candidates.size(); i++)
    {
        x_candidates.push_back(vector<int>{candidates[i][0] - 1, candidates[i][1]});
        x_candidates.push_back(vector<int>{candidates[i][0], candidates[i][1] - 1});
        x_candidates.push_back(vector<int>{candidates[i][0] + 1, candidates[i][1]});
        x_candidates.push_back(vector<int>{candidates[i][0], candidates[i][1] + 1});
    }

    for (int i = 0; i < candidates.size(); i++)
    {
        auto it = find(x_candidates.begin(), x_candidates.end(), candidates[i]);

        while (it != x_candidates.end())
        {
            x_candidates.erase(it);
            it = find(x_candidates.begin(), x_candidates.end(), candidates[i]);
        }
    }

    bool flag = true;

    for (int i = 0; i < x_candidates.size(); i++)
    {
        auto it = find(indexesX.begin(), indexesX.end(), x_candidates[i]);
        if (it == indexesX.end())
        {
            flag = false;
            break;
        }
    }

    if (flag)
    {
        for (int i = 0; i < candidates.size(); i++)
        {
            boardVar[candidates[i][0]][candidates[i][1]] = "X";
        }
    }
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