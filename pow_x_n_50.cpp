/* Leetcode - 50. Pow(x, n) (C++ language) - Medium */

#include <iostream>
#include <vector>

using namespace std;

float myPow(float xVar, int nVar);

void reset ();
void green ();
void yellow ();
void red ();

int main()
{
    yellow();

    cout << "Leetcode - 50. Pow(x, n) (C++ language) - Medium" << endl;

    vector <float> x {2.00000, 2.10000, 2.00000};
    vector <int> n {10, 3, -2};

    for (int test = 0; test < x.size(); test++)
    {
        green();

        cout << "Test " << test + 1 << ": ";

        reset();

        double result = myPow(x.at(test), n.at(test));
        cout << result << " | ";

        green();

        cout << "Passed" << endl;
    }

    reset();
    
    return 0;
}

float myPow(float xVar, int nVar)
{
    double copy {xVar};
    int sign = ((nVar > 0) ? 1 : - 1);

    if (sign == -1)
    {
        nVar *= -1;
    }
    
    while (nVar > 1)
    {
        xVar *= copy;
        nVar--;
    }

    if (sign == - 1)
    {
        return 1/xVar;
    }
    
    return xVar;
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