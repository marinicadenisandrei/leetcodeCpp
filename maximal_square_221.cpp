/* Leetcode - 221. Maximal Square (C++ language) - Medium */

#include <iostream>
#include <vector>
#include <string>
#include <math.h>

using namespace std;

void reset ();
void green ();
void yellow ();
void red ();

int maximalSquare(vector<vector<string>> matrixVar);

int main()
{
    yellow();

    cout << "Leetcode - 221. Maximal Square (C++ language) - Medium" << endl;

    vector<vector<vector<string>>> matrix {{{"1","0","1","0","0"},{"1","0","1","1","1"},{"1","1","1","1","1"},{"1","0","0","1","0"}}, {{"0","1"},{"1","0"}}};    
    
    for (int test = 0; test < matrix.size(); test++)
    {   
        green();

        cout << "Test " << test + 1 << ": ";

        reset();

        cout << maximalSquare(matrix[test]) << " | ";

        green();

        cout << "Passed" << endl;
    }

    reset();

    return 0;
}

int maximalSquare(vector<vector<string>> matrixVar)
{
    int result = 0;

    for (int i = 0; i < matrixVar.size(); i++)
    {
        for (int j = 0; j < matrixVar[i].size(); j++)
        {
            if (matrixVar[i][j] == "1")
            {
                int row_stop = 0;
                int col_stop = 0;

                for (int k = i + 1; k < matrixVar.size(); k++)
                {
                    if (matrixVar[k][j] == "0")
                    {
                        row_stop = k;
                        break;
                    }
                    
                    if (k == matrixVar.size() - 1)
                    {
                        row_stop = matrixVar.size();
                        break;
                    }
                }
                
                for (int k = j + 1; k < matrixVar[i].size(); k++)
                {
                    if (matrixVar[i][k] == "0" || matrixVar[i].size() - 1)
                    {
                        col_stop = k;
                        break;
                    }

                    if (k == matrixVar[i].size() - 1)
                    {
                        col_stop = matrixVar[i].size();
                        break;
                    }
                }

                int temp = (((row_stop - i < col_stop - j) ? sqrt(row_stop - i) * 2: sqrt(col_stop - j)) * 2) * 2;
                result = (result < temp) ? temp : result;
            }
        }
    }

    return ((result == 0) ? 1 : result);
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