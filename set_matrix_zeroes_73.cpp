/* Leetcode - 73. Set Matrix Zeroes (C++ language) - Medium */

#include <iostream>
#include <vector>

using namespace std;

void setZeroes(vector <vector <int>> &matrixVar);
void printMatrix(vector <vector <int>> matrixVar);

void reset ();
void green ();
void yellow ();
void red ();

int main()
{
    yellow();

    cout << "Leetcode - 73. Set Matrix Zeroes (C++ language) - Medium" << endl;

    vector <vector <vector <int>>> matrix {{{1,1,1},{1,0,1},{1,1,1}}, {{0,1,2,0},{3,4,5,2},{1,3,1,5}}};

    for (int test = 0; test < matrix.size(); test++)
    {   
        green();

        cout << "Test " << test + 1 << ": ";

        reset();

        setZeroes(matrix[test]);
        printMatrix(matrix[test]);

        green();

        cout << "Passed" << endl;
    }

    reset();
        
    return 0;
}

void setZeroes(vector <vector <int>> &matrixVar)
{
    vector <int> iZero {};
    vector <int> jZero {};

    for (int i = 0; i < matrixVar.size(); i++)
    {
        for (int j = 0; j < matrixVar[i].size(); j++)
        {
            if (matrixVar[i][j] == 0)
            {
                iZero.push_back(i);
                jZero.push_back(j);
            }
        }
    }

    for (int i = 0; i < iZero.size(); i++)
    {
        for (int k = 0; k < matrixVar[i].size(); k++)
        {
            matrixVar[iZero[i]][k] = 0;
        }

        for (int k = 0; k < matrixVar.size(); k++)
        {
            matrixVar[k][jZero[i]] = 0;
        }
    }
}

void printMatrix(vector <vector <int>> matrixVar)
{
    for (int i = 0; i < matrixVar.size(); i++)
    {
        for (int j = 0; j < matrixVar[i].size(); j++)
        {
            cout << ((j == 0) ? "[" : "") << matrixVar[i][j] << ((j < matrixVar[i].size() - 1) ? ", " : "]");
        }
    }

    cout << " | ";
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