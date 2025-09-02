/* Leetcode - 319. Bulb Switcher (C++ language) - Medium */

#include <iostream>
#include <vector>

using namespace std;

int bulbSwitch(int nVar);

void reset ();
void green ();
void yellow ();
void red ();

int main()
{
    yellow();

    cout << "Leetcode - 319. Bulb Switcher (C++ language) - Medium" << endl;

    vector<int> n = {3,0,1};
    
    for (int test = 0; test < n.size(); test++)
    {
        green();

        cout << "Test " << (test + 1) << ": ";

        reset();

        cout << bulbSwitch(n[test]) << " | ";

        green();

        cout << "Passed" << endl;
    }

    reset();
    
    return 0;
}

int bulbSwitch(int nVar)
{
    if (nVar == 0)
    {
        return 0;
    }
    
    vector<int> bulbs = {};
    int round = 1;
    int result = 0;
    
    for (int i = 0; i < nVar; i++)
    {
        bulbs.push_back(1);
    }
    
    while (round <= 3)
    {
        bulbs[round] = ((bulbs[round] == 1) ? 0 : 1);
        round++;
    }
    
    for (int i = 0; i < bulbs.size(); i++)
    {
        result += bulbs[i];
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