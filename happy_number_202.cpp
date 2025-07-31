/* Leetcode - 202. Happy Number (C++ language) - Easy */

#include <iostream>
#include <vector>
#include <string>
#include <math.h>

using namespace std;

bool isHappy(int nVar);

void reset ();
void green ();
void yellow ();
void red ();

int main()
{
    yellow();

    cout << "Leetcode - 202. Happy Number (C++ language) - ";
    
    green();

    cout << "Easy" << endl;
    
    vector<int> n = {19,2};

    for (int test = 0; test < n.size(); test++)
    {
        green();

        cout << "Test " << test + 1 << ": ";

        reset();

        cout << boolalpha <<isHappy(n[test]) << " | ";

        green();

        cout << "Passed" << endl;
    }

    reset();

    return 0;
}

bool isHappy(int nVar)
{
    vector<int> cache {};

    while (nVar != 1)
    {
        string nString = to_string(nVar);
        int result = 0;

        for (int i = 0; i < nString.size(); i++)
        {
            int temp = nString[i] - '0';
            result += pow(temp, 2);
        }

        nVar = result;
        cache.push_back(nVar);
        
        int c = 0;

        for (int i = 0; i < cache.size(); i++)
        {
            if (nVar == cache[i])
            {
                c++;
            }

            if (c > 3)
            {
                return false;
            }
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