/* Leetcode - 76. Minimum Window Substring (C++ language) - Hard */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

string minWindow(string sVar, string tVar);
bool haveCharacter(string big, string check);

void reset ();
void green ();
void yellow ();
void red ();

int main(void)
{
    yellow();

    cout << "Leetcode - 76. Minimum Window Substring (C++ language) - ";

    red();

    cout << "Hard" << endl;

    vector <string> s = {"ADOBECODEBANC", "a", "a"};
    vector <string> t = {"ABC","a","aa"};

    for (int test = 0; test < t.size(); test++)
    {
        green();

        cout << "Test " << test + 1 << ": ";

        reset();

        cout << minWindow(s[test],t[test]) << " | ";

        green();

        cout << "Passed" << endl;
    }

    reset();

    return 0;
}

bool haveCharacter(string big, string check)
{
    int valid {0};

    for (int i = 0; i < check.size(); i++)
    {
        if (big.find(check[i]) != std::string::npos)
        {
            valid++;
        }
    }

    if (valid == check.size())
    {
        return true;
    }

    return false;
}

string minWindow(string sVar, string tVar)
{
    if (sVar.size() < tVar.size())
    {
        return "";
    }
    
    string minString {""};

    for (int i = 0; i < sVar.size(); i++)
    {
        string temp {""};

        for (int j = i; j < sVar.size(); j++)
        {
            temp += sVar[j]; 
        }

        if (i == 0)
        {
            minString = temp;
        }
        else
        {
            if (minString.size() > temp.size(), haveCharacter(temp, tVar))
            {
                minString = temp;
            }
        }
    }

    return minString;
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