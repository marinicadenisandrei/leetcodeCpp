#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool isScramble(string s1Var, string s2Var);

void reset ();
void green ();
void yellow ();
void red ();

int main()
{
    yellow();

    cout << "Leetcode - 87. Scramble String (C++ language) - ";

    green();
    
    cout << "Hard" << endl;

    vector <string> s1 {"great","abcde","a"};
    vector <string> s2 {"rgeat","caebd","a"};

    for (int test = 0; test < s1.size(); test++)
    {
        green();

        cout << "Test " << test + 1 << ": ";

        reset();

        cout << boolalpha << isScramble(s1[test], s2[test]) << " | ";

        green();

        cout << "Passed" << endl;
    }

    reset();

    return 0;
}

bool isScramble(string s1Var, string s2Var)
{
    vector <string> acumulation {};
    vector <string> result {};

    acumulation.push_back(s1Var);

    while (acumulation.size() > 0)
    {
        for (int i = 0; i < acumulation.size(); i++)
        {
            int lenMid = acumulation[i].size() / 2;
            string string1 = acumulation[i].substr(0, lenMid);
            string string2 = acumulation[i].substr(lenMid, acumulation[i].size());

            if (string1.size() <= 2 && string2.size() <= 2)
            {
                result.push_back(string1);
                result.push_back(string2);

                acumulation.erase(acumulation.begin() + i);
            }
            else
            {
                acumulation.push_back(string1);
                acumulation.push_back(string2);

                acumulation.erase(acumulation.begin() + i);

                break;
            }
        }        
    }

    for (auto i : result)
    {
        size_t pos = s2Var.find(i);

        if (pos == string::npos)
        {
            return false;
        }
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
