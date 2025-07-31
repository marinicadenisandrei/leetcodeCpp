/* Leetcode - 67. Add Binary (C++ language) - Easy */

#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

string addBinary(string aVar, string bVar);

void reset ();
void green ();
void yellow ();
void red ();

int main()
{
    yellow();

    cout << "Leetcode - 67. Add Binary (C++ language) - ";

    green();

    cout << "Easy" << endl;

    vector <string> a {"11", "1010"};
    vector <string> b {"1", "1011"};

    for (int test = 0; test < a.size(); test++)
    {
        green();

        cout << "Test " << test + 1 << ": ";

        reset();

        cout << addBinary(a[test], b[test]) << " | ";

        green();

        cout << "Passed" << endl;
    }

    reset();
}

string addBinary(string aVar, string bVar)
{
    int aNew {0};
    string result {""};

    for (int i = aVar.size() - 1, exp = 0; i >= 0; i--, exp++)
    {
        if (aVar[i] == '1')
        {
            aNew += pow(2, exp);
        }
    }

    for (int i = bVar.size() - 1, exp = 0; i >= 0; i--, exp++)
    {
        if (bVar[i] == '1')
        {
            aNew += pow(2, exp);
        }
    }

    while (aNew > 0)
    {
        if (aNew % 2 == 0)
        {
            result += "0";
        }
        else
        {
            result += "1";
        }

        aNew /= 2;
    }
    
    reverse(result.begin(), result.end());

    return result;
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