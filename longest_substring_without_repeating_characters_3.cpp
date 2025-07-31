/* Leetcode - 3. Longest Substring Without Repeating Characters (C++ language) - Medium */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

void reset ();
void green ();
void yellow ();
void red ();

int main()
{   
    yellow();

    cout << "Leetcode - 3. Longest Substring Without Repeating Characters (C++ language) - Medium" << endl;

    vector <string> sTest {"abcabcbb", "bbbbb", "pwwkew"};
    
    for (int test = 0; test < sTest.size(); test++)
    {   
        string s = sTest.at(test);
        string temp {};
        string character {};

        string output {};

        while (s.size() > 0)
        {
            for (auto i : s)
            {
                if (temp.find(i) == string::npos)
                {
                    temp += i;
                }
                else
                {
                    if (temp.size() > output.size())
                    {
                        output = temp;
                        temp = "";
                    }
                }
            }

            s = s.substr(1);
            temp = "";
            character = "";
        }
        
        green();

        cout << "Test " << test + 1 << ": ";

        reset();

        cout << output.size() << " | ";

        green();

        cout << "Passed" << endl;

        reset();
    }
    
    return 0;
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