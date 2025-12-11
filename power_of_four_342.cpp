/* Leetcode - 342. Power of Four (C++ language) - Easy */

#include <iostream>
#include <vector>

using namespace std;

void reset ();
void green ();
void yellow ();
void red ();

bool isPowerOfFour(int nVar);

int main()
{
    yellow();

    cout << "Leetcode - 342. Power of Four (C++ language) - ";

    green();

    cout << "Easy" << endl;

    vector<int> n = {16,5,1};

    for (int test = 0; test < n.size(); test++)
    {
        cout << "Test " << test + 1 << ": ";

        reset();

        cout << boolalpha << isPowerOfFour(n[test]) << " | ";

        green();

        cout << "Passed" << endl;
    }
    
    reset();

    return 0;
}

bool isPowerOfFour(int nVar)
{
    if (nVar <= 0) return false;

    while (nVar % 4 == 0)
    {
        nVar /= 4;
    }
    
    return nVar == 1;
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