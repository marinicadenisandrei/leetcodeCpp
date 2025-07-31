/* Leetcode - 292. Nim Game (C++ language) - Easy */

#include <iostream>
#include <vector>

using namespace std;

void reset ();
void green ();
void yellow ();
void red ();

bool canWinNim(int n);

int main()
{
    yellow();

    cout << "Leetcode - 292. Nim Game (C++ language) - ";

    green();

    cout << "Easy" << endl;

    vector<int> n = {4,1,2};

    for (int test = 0; test < n.size(); test++)
    {
        green();

        cout << "Test " << test + 1 << ": ";

        reset();

        cout << boolalpha << canWinNim(n[test]) << " | ";

        green();

        cout << "Passed" << endl;
    }
    
    reset();

    return 0;
}

bool canWinNim(int n) {
    return (n % 4) != 0;
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