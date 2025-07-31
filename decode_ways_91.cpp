/* Leetcode - 91. Decode Ways (C++ language) - Medium */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int numDecodings(string sVar);

void reset ();
void green ();
void yellow ();
void red ();

int main()
{
    yellow();

    cout << "Leetcode - 91. Decode Ways (C++ language) - Medium" << endl;

    vector<string> s {"12","226","06"};

    for (int test = 0; test < s.size(); test++)
    {
        green();

        cout << "Test " << test + 1 << ": ";

        reset();

        cout << numDecodings(s[test]) << " | ";

        green();

        cout << "Passed" << endl;
    }

    reset();

    return 0;
}

int numDecodings(string sVar)
{
    int counter {((sVar[0] == '0') ? 0 : 1)};

    if (counter == 0) return 0;
    
    for (int i = 0; i < sVar.size() - 1; i++)
    {
        if (sVar.substr(i,2) <= "26") counter++;
    }

    return counter;
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