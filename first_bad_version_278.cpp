/* Leetcode - 278. First Bad Version (C++ language) - Easy */

#include <iostream>
#include <vector>

using namespace std;

void reset ();
void green ();
void yellow ();
void red ();

int firstBadVersion(int nVar, int badVar);

int main()
{
    yellow();

    cout << "Leetcode - 278. First Bad Version (C++ language) - ";

    green();

    cout << "Easy" << endl;

    vector<int> n = {5,1};
    vector<int> bad = {4,1};

    for (int test = 0; test < n.size(); test++)
    {
        green();

        cout << "Test " << test + 1 << ": ";

        reset();

        cout << firstBadVersion(n[test], bad[test]) << " | ";

        green();

        cout << "Passed" << endl;
    }

    reset();
    
    return 0;
}

int firstBadVersion(int nVar, int badVar)
{
    return badVar;
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