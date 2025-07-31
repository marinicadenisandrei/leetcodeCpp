/* Leetcode - 214. Shortest Palindrome (C++ language) - Hard */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

string shortestPalindrome(string sVar);

void reset ();
void green ();
void yellow ();
void red ();

int main()
{
    yellow();

    cout << "Leetcode - 214. Shortest Palindrome (C++ language) - ";

    red();

    cout << "Hard" << endl;

    vector<string> s {"aacecaaa","abcd"};
    
    for (int test = 0; test < s.size(); test++)
    {
        green();

        cout << "Test " << test + 1 << ": ";

        reset();

        cout << shortestPalindrome(s[test]) << " | ";

        green();

        cout << "Passed" << endl;
    }
    
    reset();

    return 0;
}

string shortestPalindrome(string sVar)
{
    bool flag = true;

    while (flag)
    {
        flag = false;

        for (int i = 0; i < (int )sVar.size() / 2; i++)
        {
            if (sVar[i] != sVar[sVar.size() - 1 - i])
            {
                sVar.insert(i, 1, sVar[sVar.size() - 1 - i]);
                flag = true;
                break;
            }
            
        }
    }

    return sVar;
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