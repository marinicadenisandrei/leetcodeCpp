/* Leetcode - 54. Spiral Matrix (C++ language) - Medium */

#include <iostream>
#include <vector>

using namespace std;

vector <int> spiralOrder(vector <vector <int>> matrixVar);
void printVector(vector <int> matrixVar); 

void reset ();
void green ();
void yellow ();
void red ();


int main()
{
    yellow();

    cout << "Leetcode - 54. Spiral Matrix (C++ language) - Medium" << endl;

    vector <vector <vector <int>>> matrix {{{1,2,3}, {4,5,6}, {7,8,9}},{{1,2,3,4}, {5,6,7,8}, {9,10,11,12}}};
    
    for (int test = 0; test < matrix.size(); test++)
    {    
        vector <int> output {spiralOrder(matrix[test])};

        green();

        cout << "Test " << test + 1 << ": ";

        reset();

        printVector(output);

        green();

        cout << "Passed" << endl;
    }

    reset();
}

void printVector(vector <int> matrixVar)
{
    for (int j = 0; j < matrixVar.size(); j++)
    {
        cout << ((j == 0) ? "[" : "") << matrixVar[j] << ((j < matrixVar.size() - 1) ? ", " : "] | "); 
    }
}

vector <int> spiralOrder(vector <vector <int>> matrixVar)
{
    vector <int> result {};
    
    while (matrixVar.size() > 0)
    {
        for (int i = 0; i < matrixVar[0].size() && matrixVar.size() > 0; i++)
        {
            result.push_back(matrixVar[0][i]);
        }

        if (matrixVar.size() > 0)
        {
            matrixVar.erase(matrixVar.begin());
        }

        for (int i = 0; i < matrixVar.size() - 1 && matrixVar.size() > 0; i++)
        {
            result.push_back(matrixVar[i][matrixVar[0].size() - 1]);
            matrixVar[i].erase(matrixVar[i].end() - 1);
        }

        for (int i = matrixVar[matrixVar.size() - 1].size() - 1; i >= 0 && matrixVar.size() > 0; i--)
        {
            result.push_back(matrixVar[matrixVar.size() - 1][i]);
        }

        if (matrixVar.size() > 0)
        {
            matrixVar.erase(matrixVar.end() - 1);
        }

        for (int i = matrixVar.size() - 1; i >= 0 && matrixVar.size() > 0; i--)
        {
            result.push_back(matrixVar[i][0]);
            matrixVar[i].erase(matrixVar[i].begin());
        }
    }

    return result;
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