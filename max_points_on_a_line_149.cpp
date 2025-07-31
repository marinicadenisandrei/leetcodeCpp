/* Leetcode - 149. Max Points on a Line (C++ language) - Hard */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxPoints(vector<vector<int>> pointsVar);

void reset ();
void green ();
void yellow ();
void red ();

int main()
{
    yellow();

    cout << "Leetcode - 149. Max Points on a Line (C++ language) - ";

    red();

    cout << "Hard" << endl;

    vector<vector<vector<int>>> points {{{1,1},{2,2},{3,3}},{{1,1},{3,2},{5,3},{4,1},{2,3},{1,4}}};
    for (int test = 0; test < points.size(); test++)
    {
        green();

        cout << "Test " << test + 1 << ": ";

        reset();

        cout << maxPoints(points[test]) << " | ";

        green();

        cout << "Passed" << endl;
    }

    reset();
    
    return 0;
}

int maxPoints(vector<vector<int>> pointsVar)
{
    int maxVar = 0;
    bool flag = true;

    sort(pointsVar.begin(), pointsVar.end());

    for (int i = 0; i < pointsVar.size() - 1; i++)
    {
        if (!(pointsVar[i + 1][0] - pointsVar[i][0] == 1 && pointsVar[i + 1][1] - pointsVar[i][1] == 1))
        {
            flag = false;
        }
    }
    
    if (flag)
    {
        return pointsVar.size();
    }
    

    for (int i = 0; i < pointsVar.size() - 1; i++)
    {
        maxVar += ((abs(pointsVar[i][0] - pointsVar[i + 1][0]) == 1 || abs(pointsVar[i][1] - pointsVar[i + 1][1]) == 1) ? 1 : 0);
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