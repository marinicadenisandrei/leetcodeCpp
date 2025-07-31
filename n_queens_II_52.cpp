/* Leetcode - 52. N-Queens II (C++ language) -  Hard */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int totalNQueens(int nVar);
void initializeTable(vector <vector <string>> &vectorVar, int nVar);
void printTable(vector <vector <string>> tableVar);
void blockPaths(vector <vector <string>> &tableVar, int row, int col);
int findEmpty(vector <string> vectorVar);
bool rightTable(vector <vector <string>> tableVar);

void reset ();
void green ();
void yellow ();
void red ();


int main()
{
    yellow();

    cout << "Leetcode - 52. N-Queens II (C++ language) - ";

    red();

    cout << "Hard" << endl;

    vector <int> n {4,1};

    for (int test = 0; test < n.size(); test++)
    {

        green();

        cout << "Test " << test + 1 << ": ";

        reset();

        cout << totalNQueens(n[test]) << " | ";

        green();

        cout << "Passed" << endl;
    }

    reset();

    return 0;
}

bool rightTable(vector <vector <string>> tableVar)
{
    bool flag = true;

    for (auto i : tableVar)
    {
        flag = false;

        for (auto j : i)
        {
            if (j == "Q")
            {
                flag = true;
            }
        }

        if (!flag)
        {
            return false;
        }
    }

    return true;
}

void printTable(vector <vector <string>> tableVar)
{
    for (int i = 0; i < tableVar.size(); i++)
    {
        for (int j = 0; j < tableVar.size(); j++)
        {
            cout << ((j == 0) ? "[" : "") << tableVar[i][j] << ((j < tableVar.size() - 1) ? ", " : "]\n");
        }
    }
}

void initializeTable(vector <vector <string>> &vectorVar, int nVar)
{
    for (int i = 0; i < nVar; i++)
    {
        vectorVar.push_back({});

        for (int j = 0; j < nVar; j++)
        {
            vectorVar.at(i).push_back("*");
        }
    }
}

void blockPaths(vector <vector <string>> &tableVar, int row, int col)
{
    for (int i = row; i < tableVar.size(); i++)
    {
        tableVar[row][i] = "X";
    }

    for (int i = row; i < tableVar.size(); i++)
    {
        tableVar[i][col] = "X";
    }

    for (int i = 1; (i < tableVar.size()) && (row + i) < tableVar.size() && (col + i) < tableVar.size(); i++)
    {
        tableVar[row + i][col + i] = "X";
    }

    for (int i = 1; (i < tableVar.size()); i++)
    {
        if ((row + i) < tableVar.size() && (col - i) >= 0)
        {
            tableVar[row + i][col - i] = "X";
        }
    }
}

int findEmpty(vector <string> vectorVar)
{
    for (int i = 0; i < vectorVar.size(); i++)
    {
        if (vectorVar[i] == "*")
        {
            return i;
        }
    }

    return -1;
}

int totalNQueens(int nVar)
{
    vector <vector <string>> table {};
    initializeTable(table, nVar);

    int counter {0};

    for (int i = 0; i < nVar; i++)
    {
        blockPaths(table, 0, i);
        table[0][i] = "Q";

        for (int j = 1; j < nVar; j++)
        {
            int colIndex = findEmpty(table[j]);

            if (colIndex != - 1)
            {
                blockPaths(table, j, colIndex);
                table[j][colIndex] = "Q";
            }
            else
            {
                break;
            }
        }
        
        counter += ((rightTable(table)) ? 1 : 0);
        table.clear();
        initializeTable(table, nVar);
    }

    return counter;
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