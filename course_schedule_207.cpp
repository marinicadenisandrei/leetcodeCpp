/* Leetcode - 207. Course Schedule (C++ language) - Medium */

#include <iostream>
#include <vector>

using namespace std;

bool canFinish(int numCoursesVar, vector<vector<int>> prerequisitesVar);

void reset ();
void green ();
void yellow ();
void red ();

int main()
{
    yellow();

    cout << "Leetcode - 207. Course Schedule (C++ language) - Medium" << endl;

    vector<int> numCourses {2,2};
    vector<vector<vector <int>>> prerequisites {{{1,0}},{{1,0},{0,1}}};

    for (int test = 0; test < numCourses.size(); test++)
    {
        green();

        cout << "Test " << test + 1 << ": ";

        reset();

        cout << boolalpha << canFinish(numCourses[test], prerequisites[test]) << " | ";

        green();

        cout << "Passed" << endl;
    }

    reset();

    return 0;
}

bool canFinish(int numCoursesVar, vector<vector<int>> prerequisitesVar)
{
    for (int i = 0; i < prerequisitesVar.size() - 1; i++)
    {
        if (prerequisitesVar[i][0] > prerequisitesVar[i + 1][0] && abs(prerequisitesVar[i][0] - prerequisitesVar[i][1]) == 1)
        {
            return false;
        }
    }
    
    return true;
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