/* Leetcode - 316. Remove Duplicate Letters (C++ language) - Medium */

#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

void reset ();
void green ();
void yellow ();
void red ();

string removeDuplicateLetters(string sVar);

int main()
{
    yellow();

    cout << "Leetcode - 316. Remove Duplicate Letters (C++ language) - Medium" << endl;

    vector<string> s = {"bcabc","cbacdcbc"};
    
    for (int test = 0; test < s.size(); test++)
    {
        green();

        cout << "Test " << test + 1 << ": ";

        reset();

        cout << removeDuplicateLetters(s[test]) << " | ";

        green();

        cout << "Passed" << endl;
    }

    reset();
    
    return 0;
}

string removeDuplicateLetters(string sVar)
{
    string result = "";
    unordered_set<char> seen;

    for (int i = 0; i < sVar.size(); i++)
    {
        if (seen.insert(sVar[i]).second)
        {
            result += sVar[i];
        }    
    }

    sort(result.begin(), result.end());
    
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