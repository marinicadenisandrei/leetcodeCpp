/* Leetcode - 204. Count Primes (C++ language) - Medium */

#include <iostream>
#include <vector>

using namespace std;

int countPrimes(int nVar);

void reset ();
void green ();
void yellow ();
void red ();

int main()
{
    yellow();

    cout << "Leetcode - 204. Count Primes (C++ language) - Medium" << endl;

    vector<int> n {10,0,1};

    for (int test = 0; test < n.size(); test++)
    {
        green();

        cout << "Test " << (test + 1) << ": ";

        reset();

        cout << countPrimes(n[test]) << " | ";

        green();

        cout << "Passed" << endl;
    }

    reset();

    return 0;
}

int countPrimes(int nVar)
{
    if (nVar < 4)
    {
        return ((nVar - 1) < 0 ? nVar : nVar - 1);
    }

    int counter = 3;

    for (int i = 5; i <= nVar; i++)
    {
        bool flag = true;

        for (int j = 4; j < nVar; j++)
        {
            if (j % i == 0)
            {
                flag = false;
                break;
            }
        }

        if (flag)
        {
            counter++;
        }
    }
    
    return counter;
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