/* Leetcode - 132. Palindrome Partitioning II (C++ language) - Hard */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int minCut(string sVar);
bool isPalindrome(string stringPal);

void reset ();
void green ();
void yellow ();
void red ();

int main()
{
    yellow();

    cout << "Leetcode - 132. Palindrome Partitioning II (C++ language) - ";

    red();

    cout << "Hard" << endl;

    vector<string> s {"aab", "a", "ab"};
    for (int test = 0; test < s.size(); test++)
    {
        green();

        cout << "Test " << test + 1 << ": ";

        reset();

        cout << minCut(s[test]) << " | ";

        green();

        cout << "Passed" << endl;
    }

    reset();
    
    return 0;
}

bool isPalindrome(string stringPal)
{
    for (int i = 0; i < stringPal.size(); i++)
    {
        if (stringPal[i] != stringPal[stringPal.size() - 1 - i])
        {
            return false;
        }        
    }
    
    return true;
}

int minCut(string sVar)
{
    string temp {""};
    int count {0};

    for (int i = 0; i < sVar.size() - 1; i++)
    {
        temp += string {sVar[i]};
        
        if (!isPalindrome(temp + string{sVar[i + 1]}))
        {
            temp = "";
            count++;
        }
    }

    return count;
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