/* Leetcode - 389. Find the Difference (C++ language) - Easy */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

char findTheDifference(string sVar, string tVar);

void reset ();
void green ();
void yellow ();
void red ();

int main()
{
    yellow();

    cout << "Leetcode - 389. Find the Difference (C++ language) - ";

    green();

    cout << "Easy" << endl;

    vector<string> s = {"abcd",""};
    vector<string> t = {"abcde","y"};

    for (int test = 0; test < s.size(); test++)
    {
        cout <<"Test " << test + 1 << ": ";

        reset();

        cout << findTheDifference(s[test], t[test]) << " | ";

        green();

        cout << "Passed" << endl;
    }
    
    reset();

    return 0;
}

char findTheDifference(string sVar, string tVar)
{
    int sum = 0;

    for (char c : tVar) sum += c;
    for (char c : sVar) sum -= c;

    return sum;
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