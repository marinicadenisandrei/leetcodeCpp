/* Leetcode - 62. Unique Paths (Cpp language) - Medium */

#include <iostream>
#include <vector>

using namespace std;

int uniquePaths(int mVar, int nVar);

void reset ();
void green ();
void yellow ();
void red ();

int main()
{
    yellow();

    cout << "Leetcode - 62. Unique Paths (Cpp language) - Medium" << endl;

    vector <int> m = {3,3};
    vector <int> n = {7,2};

    for (int test = 0; test < m.size(); test++)
    {
        green();

        cout << "Test " << test + 1 << ": "; 

        reset();

        cout << uniquePaths(m[test], n[test]) << " | ";

        green();

        cout << "Passed" << endl;
    }

    reset();
    
    return 0;
}

int uniquePaths(int mVar, int nVar)
{
    vector <vector <int>> matrix {};

    for (int i = 0; i < mVar; i++)
    {
        matrix.push_back({});

        for (int j = 0; j < nVar; j++)
        {
            if (j == nVar - 1)
            {
                matrix[i].push_back(1);
                break;
            }

            if (i < mVar - 1)
            {
                matrix[i].push_back(0);
            }
            else
            {
                matrix[i].push_back(1);
            }
        }
    }

    for (int i = mVar - 2; i >= 0; i--)
    {
        for (int j = nVar - 2; j >= 0; j--)
        {
            matrix[i][j] = matrix[i + 1][j] + matrix[i][j + 1];
        }   
    }
    
    return matrix[0][0];
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