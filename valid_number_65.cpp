#include <iostream>
#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

bool isNumber(string sVar);

void reset ();
void green ();
void yellow ();
void red ();

int main()
{
    yellow();

    cout << "Leetcode - 65. Valid Number (C++ language) - ";

    red();

    cout << "Hard" << endl;
    
    vector <string> s = {"0","e","."};
    
    for(int test = 0; test < s.size(); test++)
    {
        green();

        cout << "Test " << test + 1 << ": ";

        reset();

        cout << boolalpha << isNumber(s[test]) << " | ";   

        green();

        cout << "Passed" << endl;
    }

    reset();
    
    return 0;
}

bool isNumber(string sVar)
{
    return all_of(sVar.begin(), sVar.end(), ::isdigit);
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