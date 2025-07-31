/* Leetcode - 56. Merge Intervals (C++ language) - Medium */

#include <iostream>
#include <vector>

using namespace std;

void merge(vector <vector <int>> &intervalsVar);
void printMatrix(vector <vector <int>> matrix);\

void reset ();
void green ();
void yellow ();
void red ();

int main()
{
    yellow();

    cout << "Leetcode - 56. Merge Intervals (C++ language) - Medium" << endl;

    vector <vector <vector <int>>> intervals {{{1,4}, {4,5}, {8, 10}, {15,18}}, {{1,4}, {4,5}}};

    for (int test = 0; test < intervals.size(); test++)
    {
        green();

        cout << "Test " << test + 1 << ": ";

        reset();

        merge(intervals[test]);
        printMatrix(intervals[test]);

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
        for (int j = 0; j < 2; j++)
        {
            cout << ((j == 0) ? "[" : "") << matrix[i][j] << ((j < 1) ? ", " : "]");
        }
    }

    cout << " | ";
}

void merge(vector <vector <int>> &intervalsVar)
{
    for (int i = 0; i < intervalsVar.size() - 1; i++)
    {
        if (intervalsVar[i][0] < intervalsVar[i + 1][0] && intervalsVar[i][1] >= intervalsVar[i + 1][0] && intervalsVar[i][1] < intervalsVar[i + 1][1])
        {
            intervalsVar[i][1] = intervalsVar[i + 1][1];
            intervalsVar.erase(intervalsVar.begin() + i + 1);
        }
    }
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

