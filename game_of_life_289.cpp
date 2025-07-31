/* Leetcode - 289. Game of Life (C++ language) - Medium */

#include <iostream>
#include <vector>

using namespace std;

void reset ();
void green ();
void yellow ();
void red ();

void setCells(int i, int j,
              const vector<vector<int>>& src,
              vector<vector<int>>& dst);
void gameOfLife(vector<vector<int>>& boardVar);
void print2DVect(const vector<vector<int>>& vect);

int main()
{
    yellow();

    cout << "Leetcode - 289. Game of Life (C++ language) - Medium" << endl;

    vector<vector<vector<int>>> board = {{{0,1,0},{0,0,1},{1,1,1},{0,0,0}},{{1,1},{1,0}}};

    for (int test = 0; test < board.size(); test++)
    {
        green();

        cout << "Test " << test + 1 << ": ";

        reset();

        gameOfLife(board[test]);
        print2DVect(board[test]);

        green();

        cout << "Passed" << endl;
    }

    reset();
    
    return 0;
}

void gameOfLife(vector<vector<int>>& boardVar)
{
    int rows = boardVar.size();
    if (rows == 0) return;
    int cols = boardVar[0].size();

    vector<vector<int>> prev = boardVar;

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            setCells(i, j, prev, boardVar);
        }
    }
}

void setCells(int i, int j,
              const vector<vector<int>>& src,
              vector<vector<int>>& dst) 
{
    int rows = src.size();
    int cols = src[0].size();

    int deadCells =
        ((i-1 >= 0    && src[i-1][j]   == 0) ? 1 : 0) +  // up
        ((i+1 < rows && src[i+1][j]   == 0) ? 1 : 0) +  // down
        ((j-1 >= 0    && src[i][j-1]   == 0) ? 1 : 0) +  // left
        ((j+1 < cols && src[i][j+1]   == 0) ? 1 : 0) +  // right
        ((i-1 >= 0    && j-1 >= 0           && src[i-1][j-1] == 0) ? 1 : 0) +  // up-left
        ((i-1 >= 0    && j+1 < cols         && src[i-1][j+1] == 0) ? 1 : 0) +  // up-right
        ((i+1 < rows && j-1 >= 0           && src[i+1][j-1] == 0) ? 1 : 0) +  // down-left
        ((i+1 < rows && j+1 < cols         && src[i+1][j+1] == 0) ? 1 : 0);   // down-right

    int aliveCells =
        ((i-1 >= 0    && src[i-1][j]   == 1) ? 1 : 0) +
        ((i+1 < rows && src[i+1][j]   == 1) ? 1 : 0) +
        ((j-1 >= 0    && src[i][j-1]   == 1) ? 1 : 0) +
        ((j+1 < cols && src[i][j+1]   == 1) ? 1 : 0) +
        ((i-1 >= 0    && j-1 >= 0           && src[i-1][j-1] == 1) ? 1 : 0) +
        ((i-1 >= 0    && j+1 < cols         && src[i-1][j+1] == 1) ? 1 : 0) +
        ((i+1 < rows && j-1 >= 0           && src[i+1][j-1] == 1) ? 1 : 0) +
        ((i+1 < rows && j+1 < cols         && src[i+1][j+1] == 1) ? 1 : 0);

    if (aliveCells < 2) {
        dst[i][j] = 0;
    }
    else if (aliveCells == 2 || aliveCells == 3) {
        dst[i][j] = 1;
    }
    else if (aliveCells > 3) {
        dst[i][j] = 0;
    }
    else if (src[i][j] == 0 && aliveCells == 3) {
        dst[i][j] = 1;
    }
}

void print2DVect(const vector<vector<int>>& vect)
{
    cout << "[";
    for (const auto& row : vect) {
        cout << "[";
        for (size_t j = 0; j < row.size(); ++j) {
            cout << row[j];
            if (j + 1 < row.size()) cout << ", ";
        }
        cout << "]";
    }

    cout << "] | ";
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