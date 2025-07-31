/* Leetcode - 59. Spiral Matrix II (C++ language) - Medium */

#include <iostream>
#include <vector>

using namespace std;

vector <vector <int>> generateMatrix(int n);
void printMatrix(vector <vector <int>> matrix);

void reset ();
void green ();
void yellow ();
void red ();

int main()
{
    yellow();

    cout << "Leetcode - 59. Spiral Matrix II (C++ language) - Medium" << endl;

    vector <int> n {3,1};

    for (int test = 0; test < n.size(); test++)
    {
        green();

        cout << "Test " << test + 1 << ": ";

        reset();

        vector <vector <int>> result {generateMatrix(n[test])};

        printMatrix(result);

        green();

        cout << "Passed" << endl;
    }

    reset();

    return 0;
}

void printMatrix(vector <vector <int>> matrix)
{
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[i].size(); j++)
        {
            cout << ((j == 0) ? "[" : "") << matrix[i][j] << ((j < matrix[i].size() - 1) ? ", " : "]");
        }
    }

    cout << " | ";
}

vector <vector <int>> generateMatrix(int n)
{
    vector <vector <int>> matrix {};

    for (int i = 0; i < n; i++)
    {
        matrix.push_back({});

        for (int j = 0; j < n; j++)
        {
            matrix[i].push_back(0);
        }
    }

    int start = 1;
    int offset = 0;

    while (start <= n * n)
    {
        for (int i = offset; i < n - offset && start <= n * n; i++)
        {
            matrix[offset][i] = start;
            start++; 
        }  

        for (int i = 1 + offset; i < n - offset && start <= n * n; i++)
        {
            matrix[i][n - 1 - offset] = start;
            start++;
        }

        for (int i = matrix[n - 1].size() - 2 - offset; i >= 0 + offset && start <= n * n; i--)
        {
            matrix[n - 1 - offset][i] = start;
            start++;
        }

        for (int i = n - 2; i > 0 && start <= n * n; i--)
        {
            matrix[i][0] = start;
            start++;
        }
        
        offset++;
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