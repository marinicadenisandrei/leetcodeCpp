/* Leetcode - 326. Power of Three (C++ language) - Easy */

#include <iostream>
#include <vector>

using namespace std;

void reset ();
void green ();
void yellow ();
void red ();

bool isPowerOfThree(int nVar);

int main()
{
    yellow();

    cout << "Leetcode - 326. Power of Three (C++ language) - ";

    green();

    cout << "Easy" << endl;

    vector<int> n = {27,0,-1};

    for (int test = 0; test < n.size(); test++)
    {
        cout << "Test " << test + 1 << ": ";

        reset();

        cout << boolalpha << isPowerOfThree(n[test]) << " | ";

        green();

        cout << "Passed" << endl;
    }

    reset();
    
    return 0;
}

bool isPowerOfThree(int nVar)
{
    if (nVar < 1) return false;
    
    while (nVar % 3 == 0)
    {
        nVar /= 3;
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