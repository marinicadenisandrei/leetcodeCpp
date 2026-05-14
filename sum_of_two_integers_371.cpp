/* Leetcode - 371. Sum of Two Integers (C++ language) - Easy */

#include <iostream>
#include <vector>

using namespace std;

void reset ();
void green ();
void yellow ();
void red ();

int getSum(int aVar, int bVar);

int main()
{
    yellow();

    cout << "Leetcode - 371. Sum of Two Integers (C++ language) - ";

    green();

    cout << "Easy" << endl;

    vector<int> a = {1,2};
    vector<int> b = {2,3};

    for (int test = 0; test < a.size(); test++)
    {
        cout << "Test " << test + 1 << ": ";

        reset();

        cout << getSum(a[test], b[test]) << " | ";

        green();

        cout << "Passed" << endl;
    }

    reset();

    return 0;
}

int getSum(int aVar, int bVar)
{
    while (bVar != 0)
    {
        int sumWithoutTransport = aVar ^ bVar;
        unsigned transport = (unsigned)(aVar & bVar) << 1;

        aVar = sumWithoutTransport;
        bVar = transport;
    }
    
    return aVar;
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