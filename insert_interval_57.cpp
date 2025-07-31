/* Leetcode - 57. Insert Interval (C++ language) - Medium */

#include <iostream>
#include <vector>

using namespace std;

vector <vector <int>> insert(vector <vector <int>> intervalsVar, vector <int> newIntervalVar);
void printMatrix(vector <vector <int>> matrixVar);

void reset ();
void green ();
void yellow ();
void red ();

int main()
{
    yellow();

    cout << "Leetcode - 57. Insert Interval (C++ language) - Medium" << endl;

    vector <vector <vector <int>>> intervals {{{1,3}, {6,9}}, {{1,2}, {3,5}, {6,7}, {8,10}, {12,16}}};
    vector <vector <int>> newInterval {{2,5}, {4,8}};

    for (int test = 0; test < intervals.size(); test++)
    {
        green();

        cout << "Test " << test + 1 << ": ";

        reset();

        intervals[test] = insert(intervals[test], newInterval[test]);
        printMatrix(intervals[test]);

        green();

        cout << "Passed" << endl;
    }

    reset();

    return 0;
}

void printMatrix(vector <vector <int>> matrixVar)
{
    for (auto i : matrixVar)
    {
        for (int j = 0; j < i.size(); j++)
        {
            cout << ((j == 0) ? "[" : "") << i[j] << ((j < i.size() - 1) ? ", " : "]");
        }
    }

    cout << " | ";
}

vector <vector <int>> insert(vector <vector <int>> intervalsVar, vector <int> newIntervalVar)
{
    for (int i = 0; i < intervalsVar.size(); i++)
    {
        if (intervalsVar[i][0] < newIntervalVar[0] && intervalsVar[i][1] >= newIntervalVar[0] && intervalsVar[i][1] < newIntervalVar[1])
        {
            intervalsVar[i][1] = newIntervalVar[1];
        }
    }

    for (int i = 0; i < intervalsVar.size() - 1; i++)
    {
        if (intervalsVar[i][0] < intervalsVar[i+1][0] && intervalsVar[i][1] >= intervalsVar[i+1][0] && intervalsVar[i][1] < intervalsVar[i+1][1])
        {
            intervalsVar[i][1] = intervalsVar[i+1][1];
            intervalsVar.erase(intervalsVar.begin() + i + 1);
        }
        else if (intervalsVar[i][0] < intervalsVar[i+1][0] && intervalsVar[i][1] >= intervalsVar[i+1][0] && intervalsVar[i][1] > intervalsVar[i+1][1])
        {
            intervalsVar.erase(intervalsVar.begin() + i + 1);
            i--;
        }
    }
    
    return intervalsVar;
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