/* Leetcode - 313. Super Ugly Number (C++ language) - Medium */

#include <iostream>
#include <vector>

using namespace std;

void reset ();
void green ();
void yellow ();
void red ();

int nthSuperUglyNumber(int nVar, vector<int> primesVar);

int main()
{   
    yellow();
    
    cout << "Leetcode - 313. Super Ugly Number (C++ language) - Medium" << endl;

    vector<int> n = {12,1};
    vector<vector<int>> primes = {{2,7,13,19},{2,3,5}};

    for (int test = 0; test < n.size(); test++)
    {
        green();

        cout << "Test " << test + 1 << ": ";

        reset();

        cout << nthSuperUglyNumber(n[test], primes[test]) << " | ";
        
        green();

        cout << "Passed" << endl;
    }

    reset();
    
    return 0;
}

int nthSuperUglyNumber(int nVar, vector<int> primesVar)
{
    vector<int> result = {1};
    int start = 2;

    while (result.size() < nVar)
    {
        int temp = start;
        int prev = temp;

        while (temp > 1)
        {
            bool flag = false;

            for (int i = 0; i < primesVar.size(); i++)
            {
                if (temp % primesVar[i] == 0)
                {
                    temp /= primesVar[i];
                    flag = true;
                    break;
                }
            }

            if (!flag)
            {
                temp = 2;
                break;
            }
            
        }
        
        if (temp == 1)
        {
            result.push_back(start);
        }

        start++;
    }

    return result[nVar - 1];
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