/* Leetcode - 343. Integer Break (C++ language) - Medium */

#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

void reset ();
void green ();
void yellow ();
void red ();

int integerBreak(int nVar);

int main()
{
    yellow();
    
    cout << "Leetcode - 343. Integer Break (C++ language) - Medium" << endl;

    vector<int> n = {2,10};
    
    for (int test = 0; test < n.size(); test++)
    {
        green();

        cout << "Test " << test + 1 << ": ";

        reset();

        cout << integerBreak(n[test]) << " | ";
        
        green();

        cout << "Passed" << endl;
    }

    reset();

    return 0;
}

int integerBreak(int nVar)
{
    if (nVar <= 2)
    {
        return 1;
    }
    
    int result = 0;

    for (int i = 2; i < nVar / 2; i++)
    {
        int temp = 0;

        if (i % nVar == 2)
        {
            temp = pow(nVar / 2, i); 
        }
        else
        {
            int factor = nVar / i;
            temp = pow(factor, i - 1) * (factor + 1);
        }

        result = ((result< temp) ? temp : result);
    }

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