/* Leetcode - 390. Elimination Game (C++ language) - Medium */

#include <iostream>
#include <vector>

using namespace std;

int lastRemaining(int nVar);

void reset ();
void green ();
void yellow ();
void red ();

int main()
{
    yellow();

    cout << "Leetcode - 390. Elimination Game (C++ language) - Medium" << endl;

    vector<int> n = {9,1};
    
    for (int test = 0; test < n.size(); test++)
    {
        green();

        cout << "Test " << test + 1 << ": ";

        reset();

        cout << lastRemaining(n[test]) << " | ";

        green();

        cout << "Passed" << endl;
    }

    reset();
    
    return 0;
}

int lastRemaining(int nVar)
{
    int head = 1;
    int step = 1;
    int remaining = nVar;
    bool left = true;

    while (remaining > 1)
    {
        if (left || remaining % 2 == 1)
        {
            head += step;
        }

        remaining /= 2;
        step *= 2;  
        left = !left;
    }

    return head;
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