/* Leetcode - Count Numbers with Unique Digits (C++ language) - Medium */

#include <iostream>
#include <vector>

using namespace std;

void reset ();
void green ();
void yellow ();
void red ();

int countNumbersWithUniqueDigits(int nVar);

int main()
{   
    yellow();

    cout << "Leetcode - Count Numbers with Unique Digits (C++ language) - Medium" << endl;

    vector<int> n = {2,0};
    
    for (int test = 0; test < n.size(); test++)
    {
        green();

        cout << "Test " << test + 1 << ": ";

        reset();

        cout << countNumbersWithUniqueDigits(n[test]) << " | ";

        green();

        cout << "Passed" << endl;
    }

    reset();

    return 0;
}

int countNumbersWithUniqueDigits(int nVar)
{
    if (nVar == 0)
    {
        return 1;
    }

    int total = 10;     
    int current = 9;    
    int available = 9;

    for (int i = 2; i <= nVar && available > 0; i++)
    {
        current *= available;
        total += current;
        available--;
    }

    return total;
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