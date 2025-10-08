/* Leetcode - 335. Self Crossing (C++ language) - Hard */

#include <iostream>
#include <vector>

using namespace std;

void reset ();
void green ();
void yellow ();
void red ();

bool isSelfCrossing(vector<int> distanceVar);

int main()
{
    yellow();

    cout << "Leetcode - 335. Self Crossing (C++ language) - ";

    red();

    cout << "Hard" << endl;

    vector<vector<int>> distance = {{2,1,1,2},{1,2,3,4},{1,1,1,2,1}};
    
    for (int test = 0; test < distance.size(); test++)
    {
        green();

        cout << "Test " << test + 1 << ": ";

        reset();

        cout << boolalpha << isSelfCrossing(distance[test]) << " | ";

        green();

        cout << "Passed" << endl;
    }

    reset();

    return 0;
}

bool isSelfCrossing(vector<int> distanceVar)
{
    for (int i = 0; i < distanceVar.size() - 3; i++)
    {
        if (distanceVar[i] >= distanceVar[i + 2] || distanceVar[i + 1] >= distanceVar[i + 3])
        {
            return true;
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
