/* Leetcode - 172. Factorial Trailing Zeroes (C++ language) - Medium */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int trailingZeroes(int nVar);

void reset ();
void green ();
void yellow ();
void red ();

int main()
{
    yellow();

    cout << "Leetcode - 172. Factorial Trailing Zeroes (C++ language) - Medium" << endl;

    vector<int> n {3,5,0};

    for (int test = 0; test < n.size(); test++)
    {
        green();

        cout << "Test " << test + 1 << ": ";

        reset();

        cout << trailingZeroes(n[test]) << " | ";

        green();

        cout << "Passed" << endl;
    }

    reset();
    
    return 0;
}

int trailingZeroes(int nVar)
{
    int x = 1;
    int factorialResult = 1;
    string strResult {""};

    while (x <= nVar)
    {
        factorialResult *= x++;
    }

    strResult = to_string(factorialResult);
    auto l = [] (string stringVar) {
        int c = 0;

        for (char i : stringVar)
        {
            c += ((i == '0') ? 1 : 0);
        }

        return c;
    };

    return l(strResult);
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