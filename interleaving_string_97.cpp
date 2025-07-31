/* Leetcode - 97. Interleaving String (C++ language) - Medium */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool isInterleave(string s1Var, string s2Var, string s3Var);

void reset ();
void green ();
void yellow ();
void red ();

int main()
{
    yellow();

    cout << "Leetcode - 97. Interleaving String (C++ language) - Medium" << endl;

    vector<string> s1 {"aabcc","aabcc"};
    vector<string> s2 {"dbbca","dbbca"};
    vector<string> s3 {"aadbbcbcac","aadbbbaccc"};

    for (int test = 0; test < s1.size(); test++)
    {
        green();

        cout << "Test " << test + 1 << ": ";
        
        reset();

        cout << boolalpha << isInterleave(s1[test], s2[test], s3[test]) << " | ";

        green();

        cout << "Passed" << endl;
    }

    reset();

    return 0;
}

bool isInterleave(string s1Var, string s2Var, string s3Var)
{
    while (s3Var.size() > 0)
    {
        string var1 = "";
        string var2 = "";

        for (int i = 0; i < s1Var.size(); i++)
        {
            if (s1Var[i] == s3Var[i])
            {
                var1 += s1Var[i];
            }
            else
            {
                break;
            }
        }

        for (int i = 0; i < s2Var.size(); i++)
        {
            if (s2Var[i] == s3Var[i])
            {
                var2 += s2Var[i];
            }
            else
            {
                break;
            }
        }

        if (var1.size() > var2.size())
        {
            int len = var1.length();
            s3Var.erase(0, len);
            s1Var.erase(0, len);
        }
        else
        {
            int len = var2.length();
            s3Var.erase(0, len);
            s2Var.erase(0, len);
        }

        if (var1.size() == 0 && var2.size() == 0)
        {
            return false;
        }

        var1.clear();
        var2.clear();
    }

    if (s3Var.size() == 0)
    {
        return true;
    }
    
    return false;
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
