/* Leetcode - 365. Water and Jug Problem (C++ language) - Medium */

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void reset ();
void green ();
void yellow ();
void red ();

int gcd(int a, int b);
bool canMeasureWater(int xVar, int yVar, int targetVar);

int main()  
{
    yellow();

    cout << "Leetcode - 365. Water and Jug Problem (C++ language) - Medium" << endl;

    vector<int> x = {3,2,1};
    vector<int> y = {5,6,2};
    vector<int> target = {4,5,3};

    cout << boolalpha;

    for (int test = 0; test < x.size(); test++)
    {
        green();

        cout << "Test " << test + 1 << ": ";

        reset();

        cout << canMeasureWater(x[test], y[test], target[test]) << " | ";

        green();

        cout << "Passed" << endl;
    }

    return 0;
}

int gcd(int a, int b)
{
    while (b != 0)
    {
        int rest = a % b;
        a = b;
        b = rest;
    }
    return a;
}

bool canMeasureWater(int xVar, int yVar, int targetVar)
{
    if (targetVar > xVar + yVar)
        return false;

    if (targetVar == xVar || targetVar == yVar)
        return true;

    return targetVar % gcd(xVar, yVar) == 0;  
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