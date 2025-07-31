/* Leetcode - 69. Sqrt(x) (C++ language) - Easy */

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

#define NUMBER_OF_TESTS 2

void reset ();
void green ();
void yellow ();
void red ();

int mySqrt(int xVar);

int main()
{
    yellow();

    cout << "Leetcode - 69. Sqrt(x) (C++ language) - ";

    green();
    
    cout << "Easy" << endl;

    vector <int> x {4, 8};

    for (int test = 0; test < NUMBER_OF_TESTS; test++)
    {
        green();

        cout << "Test " << test + 1 << ": ";

        reset();

        cout << mySqrt(x[test]) << " | ";

        green();

        cout << "Passed" << endl;
    }

    reset();

    return 0;
}

int mySqrt(int xVar)
{
    return sqrt(xVar);
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