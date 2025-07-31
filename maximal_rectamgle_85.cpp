/* Leetcode - 85. Maximal Rectangle (C++ language) - Hard */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int maximalRectangle(vector <vector <string>> matrixVar);
bool checkZeroes(vector <vector<string>> matrixVar, int istart, int jstart, int iend);

void reset ();
void green ();
void yellow ();
void red ();

int main()
{   
    yellow();

    cout << "Leetcode - 85. Maximal Rectangle (C++ language) - ";

    red();

    cout << "Hard" << endl;

    vector <vector <vector <string>>> matrix {{{"1","0","1","0","0"},{"1","0","1","1","1"},{"1","1","1","1","1"},{"1","0","0","1","0"}},{{"0"}},{{"1"}}};

    for (int test = 0; test < matrix.size(); test++)
    {   
        green();

        cout << "Test " << test + 1 << ": ";

        reset();

        cout << maximalRectangle(matrix[test]) << " | ";

        green();

        cout << "Passed" << endl;
    }

    reset();

    return 0;
}

bool checkZeroes(vector <vector<string>> matrixVar, int istart, int jstart, int iend, int jend)
{
    for (int i = istart; i < jend; i++)
    {
        for (int j = jstart; j < iend; j++)
        {
            if (matrixVar[i][j] == "0")
            {
                return false;
            }
        }
    }

    return true;
}

int maximalRectangle(vector <vector <string>> matrixVar)
{
    int maxVar = 0;

    for (int i = 0; i < matrixVar.size(); i++)
    {
        for (int j = 0; j < matrixVar.size(); j++)
        {
            if (matrixVar[i][j] == "1")
            {
                int rowStop = 0;
                int colStop = 0;

                bool rowFlag = true;
                bool colFlag = true;

                for (int k = j + 1; k < matrixVar[i].size(); k++)
                {
                    if (matrixVar[i][k] == "0")
                    {
                        rowStop = k;
                        rowFlag = false;
                        break;
                    }
                }

                for (int k = i + 1; k < matrixVar.size(); k++)
                {
                    if (matrixVar[k][j] == "0")
                    {
                        colStop = k;
                        colFlag = false;
                        break;
                    }
                }

                rowStop = ((rowFlag) ? matrixVar[i].size() : rowStop);
                colStop = ((colFlag) ? matrixVar.size() : colStop);

                bool checker = checkZeroes(matrixVar, i, j, rowStop, colStop);

                if (checker)
                {
                    int result = (rowStop - j) * (colStop - i); 
                    maxVar = ((maxVar < result) ? result : maxVar);
                }
            }
        }
    }

    return maxVar;
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