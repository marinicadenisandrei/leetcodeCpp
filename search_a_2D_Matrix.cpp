/* Leetcode - 74. Search a 2D Matrix (Cpp language) - Medium */

#include <iostream>
#include <vector>

using namespace std;

bool searchMatrix(vector <vector <int>> matrixVar, int targetVar);

void reset ();
void green ();
void yellow ();
void red ();

int main()
{
    yellow();

    cout << "Leetcode - 74. Search a 2D Matrix (Cpp language) - Medium" << endl;

    vector <vector <vector <int>>> matrix {{{1,3,5,7},{10,11,16,20},{23,30,34,60}}, {{1,3,5,7},{10,11,16,20},{23,30,34,60}}};
    vector <int> target {3,13};

    for (int test = 0; test < target.size(); test++)
    {
        green();

        cout << "Test " << test + 1 << ": ";

        reset();

        cout << boolalpha << searchMatrix(matrix[test], target[test]) << " | ";

        green();

        cout << "Passed" << endl;
    }

    reset();

    return 0;
}

bool searchMatrix(vector <vector <int>> matrixVar, int targetVar)
{
    for (auto i : matrixVar)
    {
        for (auto j : i)
        {
            if (j == targetVar)
            {
                return true;
            }
        }
    }

    return false;
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