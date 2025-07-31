/* Leetcode - 263. Ugly Number (C++ language) - Easy */

#include <iostream>
#include <vector>

using namespace std;

void reset ();
void green ();
void yellow ();
void red ();

bool isUgly(int nVar);

int main()
{
    yellow();

    cout << "Leetcode - 263. Ugly Number (C++ language) - ";

    green();

    cout << "Easy" << endl;

    vector<int> n = {6,1,14};  
    
    for (int test = 0; test < n.size(); test++)
    {
        green();

        cout << "Test " << test + 1 << ": ";

        reset();

        cout << boolalpha << isUgly(n[test]) << " | ";

        green();

        cout << "Passed" << endl;
    }

    reset();
    
    return 0;
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