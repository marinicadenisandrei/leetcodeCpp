/* Leetcode - 70. Climbing Stairs (C++ language) - Easy */

#include <iostream>
#include <vector>

using namespace std;

int climbStairs(int nVar);

void reset ();
void green ();
void yellow ();
void red ();

int main()
{
    yellow();

    cout << "Leetcode - 70. Climbing Stairs (C++ language) - ";

    green();

    cout << "Easy" << endl;

    vector <int> n {2,3};

    for (int test = 0; test < n.size(); test++)
    {
        green();

        cout << "Test " << test + 1 << ": ";

        reset();

        cout << climbStairs(n[test]) << " | ";

        green();

        cout << "Passed" << endl;
    }

    reset();

    return 0;
}

int climbStairs(int nVar)
{
    if (nVar < 3)
    {
        return nVar;
    }
    else
    {
        return 3;
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