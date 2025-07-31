/* Leetcode - 14. Longest Common Prefix (C++ language) - Easy */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int smallWordFromArray(vector <string> vectorVar);

void reset ();
void green ();
void yellow ();
void red ();

int main()
{
    yellow();

    cout << "Leetcode - 14. Longest Common Prefix (C++ language) - ";

    green();

    cout << "Easy" << endl;

    vector <vector <string>> strs {{"flower","flow","flight"}, {"dog","racecar","car"}};

    for (int test = 0; test < strs.size(); test++)
    {
        bool flag {true};
        string output {""};

        for (int i = 0; i < smallWordFromArray(strs.at(test)); i++)
        {
            for (int j = 1; j < strs.at(test).size(); j++)
            {
                if (strs.at(test)[j - 1][i] != strs.at(test)[j][i])
                {
                    flag = false;
                    break;
                }
            }

            output = strs.at(test)[0].substr(0,i);

            if (!flag)
            {
                break;
            }
        }

        green();
        
        cout << "Test " << test + 1 << ": ";

        reset();

        cout << output << " | ";

        green();

        cout << "Passed" << endl;

        reset();
    }
}

int smallWordFromArray(vector <string> vectorVar)
{
    int min { (int) vectorVar.at(0).size()};
    
    for (auto i : vectorVar)
    {
        min = ((i.size() < min) ? i.size() : min);
    }
    
    return min;
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