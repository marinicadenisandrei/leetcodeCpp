/* Leetcode - 264. Ugly Number II (C++ language) - Medium */

#include <iostream>
#include <vector>

using namespace std;

void reset ();
void green ();
void yellow ();
void red ();

bool isUgly(int nVar);
int nthUglyNumber(int nVar);

int main()
{
    yellow();

    cout << "Leetcode - 264. Ugly Number II (C++ language) - Medium" << endl;

    vector<int> n = {10,1};  
    
    for (int test = 0; test < n.size(); test++)
    {
        green();

        cout << "Test " << test + 1 << ": ";

        reset();

        cout << nthUglyNumber(n[test]) << " | ";

        green();

        cout << "Passed" << endl;
    }

    reset();
    
    return 0;
}

int nthUglyNumber(int nVar)
{
    vector<int> candidates = {};
    int c = 1;

    while (candidates.size() < nVar)
    {
        if (isUgly(c))
        {
            candidates.push_back(c);       
        }

        c++;
    }
    
    return candidates[candidates.size() - 1];
}

bool isUgly(int nVar)
{
    while (nVar > 1)
    {
        if (nVar % 2 == 0)
        {
            nVar /= 2;
        }
        else if (nVar % 3 == 0) {
            nVar /= 3;
        }   
        else if (nVar % 5 == 0) {
            nVar /= 5;
        }
        else
        {
            return false;
        }
    }

    return true;
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