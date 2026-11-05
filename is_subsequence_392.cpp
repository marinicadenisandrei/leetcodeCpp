/* Leetcode - 392. Is Subsequence (C++ language) - Easy */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool isSubsequence(string sVar, string tVar);

void reset ();
void green ();
void yellow ();
void red ();

int main()
{
    cout << boolalpha;

    yellow();

    cout << "Leetcode - 392. Is Subsequence (C++ language) - ";

    green();

    cout << "Easy" << endl;

    vector<string> s = {"abc","axc"};
    vector<string> t = {"ahbgdc","ahbgdc"};
    
    for (int test = 0; test < s.size(); test++)
    {
        cout << "Test " << test + 1 << ": ";

        reset();

        cout << isSubsequence(s[test], t[test]) << " | ";

        green();

        cout << "Passed" << endl;
    }

    reset();

    return 0;
}

bool isSubsequence(string sVar, string tVar)
{
    size_t lastIndex = 0;

    for (char c : sVar)
    {
        size_t index = tVar.find(c, lastIndex);

        if (index == string::npos) {
            return false;
        }

        lastIndex = index + 1;
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