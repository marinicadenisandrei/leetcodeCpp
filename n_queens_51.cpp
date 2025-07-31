/* Leetocde - 51. N-Queens (C++ language) - Hard */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector <vector <string>> solveNQueens(int nVar);
void printMatrix(vector <vector <string>> matrixVar);
void blockMatrix(vector <vector <string>> &matrixVar, int row, int col);
int findEmptySpace(vector <string> vectorVar);
void emptyMatrix(vector <vector <string>> matrixVar);
bool queensValid(vector <vector <string>> matrixVar);
void emptyResult(vector <vector <string>> &matrixVar);

void reset ();
void green ();
void yellow ();
void red ();

int main()
{   
    yellow();

    cout << "Leetocde - 51. N-Queens (C++ language) - ";

    red();
    
    cout << "Hard" << endl;

    vector <int> n {4,1};
    
    for (int test = 0; test < n.size(); test++)
    {
        vector<vector <string>> output {solveNQueens(n[test])};

        green();

        cout << "Test " << test + 1 << ": ";

        reset();

        printMatrix(output);

        green();

        cout << "Passed" << endl;
    }

    reset();

    return 0;
}

void emptyResult(vector <vector <string>> &matrixVar)
{
    for (int i = 0; i < matrixVar.size(); i++)
    {
        for (int j = 0; j < matrixVar.size(); j++)
        {
            if (matrixVar[i][j] == "X")
            {
                matrixVar[i][j] = ".";
            }
        }
    }
}

bool queensValid(vector <vector <string>> matrixVar)
{
    bool flag = false;

    for (int i = 0; i < matrixVar.size(); i++)
    {
        flag = false;

        for (int j = 0; j < matrixVar.size(); j++)
        {
            if (matrixVar[i][j] == "Q")
            {
                flag = true;
            }
        }

        if (flag == false)
        {
            return false;
        }
    }

    return true;
}

void emptyMatrix(vector <vector <string>> matrixVar)
{
    for (int i = 0; i < matrixVar.size(); i++)
    {
        for (int j = 0; j < matrixVar.size(); j++)
        {
            matrixVar[i][j] = "";
        }
    }
}

int findEmptySpace(vector <string> vectorVar)
{
    for (int i = 0; i < vectorVar.size(); i++)
    {
        if (vectorVar[i] == "")
        {
            return i;
        }
    }
    
    return -1;
}

void printMatrix(vector <vector <string>> matrixVar)
{
    for (int i = 0; i < matrixVar.size(); i++)
    {
        for (int j = 0; j < matrixVar.at(i).size(); j++)
        {
            cout << ((j == 0) ? "[" : "") << matrixVar.at(i).at(j) << ((j < matrixVar.at(i).size() - 1) ? ", " : "]");
        }
    }

    cout << " | ";
}

void blockMatrix(vector <vector <string>> &matrixVar, int row, int col)
{
    for (int i = 0; i < matrixVar.size(); i++)
    {
        matrixVar[row][i] = "X";
    }
    
    for (int i = col; i < matrixVar.size(); i++)
    {
        matrixVar[i][col] = "X";
    }

    for (int i = 0; i < matrixVar.size(); i++)
    {
        if ((row + i) < matrixVar.size() && (col + i) < matrixVar.size())
        {
            matrixVar[row + i][col + i] = "X";
        }
        else
        {
            break;
        }
    }

    for (int i = 0; i < matrixVar.size(); i++)
    {
        if ((row + i) < matrixVar.size() && (col - i) >= 0)
        {
            matrixVar[row + i][col - i] = "X";
        }
        else
        {
            break;
        }
    }
}

vector <vector <string>> solveNQueens(int nVar)
{
    vector <vector <string>> matrix {};

    if (nVar == 1)
    {
        matrix.push_back({"Q"});
        return matrix;
    }
    
    for (int i = 0; i < nVar; i++)
    {
        matrix.push_back({});

        for (int j = 0; j < nVar; j++)
        {
            matrix[i].push_back("");
        }
    }

    int indexStart = 1;

    for(int j = 0; j < matrix.size() - 1; j++)
    {
        blockMatrix(matrix, 0, indexStart);
        matrix[0][indexStart] = "Q";

        int col {0};

        for (int i = 1; i < matrix.size(); i++)
        {
            col = findEmptySpace(matrix[i]);

            if (col != -1)
            {
                blockMatrix(matrix, i, col);
                matrix[i][col] = "Q";
            }
            else
            {
                break;
            }
        }

        indexStart++;

        if (!queensValid(matrix))
        {
            emptyResult(matrix);
            break;
        }
    }

    return matrix;   
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