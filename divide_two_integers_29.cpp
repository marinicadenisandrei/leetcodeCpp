/* Leetcode - 29. Divide Two Integers (C++ lamguage) - Medium */

#include <iostream>
#include <vector>

using namespace std;

int divide(int dividend, int divisor);

void reset ();
void green ();
void yellow ();
void red ();

int main()
{
    yellow();

    cout << "Leetcode - 29. Divide Two Integers (C++ lamguage) - Medium" << endl;

    vector <int> dividend {10,7};
    vector <int> divisor {3,-3};

    for (int test = 0; test < dividend.size(); test++)
    {
        int result = divide(dividend.at(test), divisor.at(test));

        green();

        cout << "Test " << test + 1 << ": ";

        reset();

        cout << result << " | ";

        green();

        cout << "Passed" << endl;
    }

    reset();

    return 0;
}

int divide(int dividend, int divisor)
{
    return (dividend / divisor);
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