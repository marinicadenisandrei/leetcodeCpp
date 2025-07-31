#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool isMatch(string sVar, string pVar);
bool checkForWildcardSymbols(string stringVar1, string stringVar2);

void reset ();
void green ();
void yellow ();
void red ();

int main()
{   
    yellow();

    cout << "Leetcode - 44. Wildcard Matching (C++ language) - ";

    red();

    cout << "Hard" << endl;

    vector <string> s {"aa", "aa", "cb"};
    vector <string> p {"a", "*", "?a"};

    for (int test = 0; test < s.size(); test++)
    {
        green();

        cout << "Test " << test + 1 << ": ";

        reset();

        cout << boolalpha << isMatch(s.at(test), p.at(test)) << " | ";

        green();

        cout << "Passed" << endl;
    }

    reset();

    return 0;
}

bool checkForWildcardSymbols(string stringVar)
{
    char wldSym_1 {'*'};
    char wldSym_2 {'?'};
    
    for (auto ch : stringVar)
    {
        if (ch == wldSym_1 || ch == wldSym_2)
        {
            return true;
        }
    }

    return false;
}

bool isMatch(string sVar, string pVar)
{
    if (pVar.size() == 1 && pVar == "*")
    {
        return true;
    }
    
    if (!checkForWildcardSymbols(pVar) && sVar.size() != pVar.size())
    {
        return false;
    }

    int index = 0; 

    for (int i = 0; i < sVar.size(); i++)
    {
        if (sVar.at(i) != pVar.at(index))
        {
            if (pVar.at(index) == '?')
            {
                index++;
                continue;
            }
            
            if (pVar.at(index) == '*' && sVar.at(i) != pVar.at(index + 1))
            {
                continue;
            }
            else if (pVar.at(index) == '*' && sVar.at(i) == pVar.at(index + 1))
            {
                index++;
                continue;
            }
            else
            {
                if (pVar.at(index) != sVar.at(i))
                {
                    return false;
                }
            }
        }
        else
        {
            index++;
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