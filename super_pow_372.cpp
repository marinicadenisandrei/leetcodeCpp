/* Leetcode - 372. Super Pow (C++ language) - Medium */

#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

void reset ();
void green ();
void yellow ();
void red ();

int superPow(int aVar, vector<int> bVar);

int main()
{
    yellow();

    cout << "Leetcode - 372. Super Pow (C++ language) - Medium\n";

    vector<int> a = {2,2,1};
    vector<vector<int>> b = {{3},{1,0},{4,3,3,8,5,2}};
    
    for (int test = 0; test < a.size(); test++)
    {
        green();

        cout << "Test " << test + 1 << ": ";

        reset();

        cout << superPow(a[test], b[test]) << " | ";

        green();

        cout << "Passed\n";
    }
    
    reset();

    return 0;
}

int superPow(int aVar, vector<int> bVar)
{
    int var = 0;

    for (int digit : bVar) {
        var = var * 10 + digit;
    }

    return (int)pow(aVar, var) % 1337;
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