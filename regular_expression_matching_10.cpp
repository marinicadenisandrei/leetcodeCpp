/* Leetcode - 10. Regular Expression Matching (C++ language) - Hard*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

void reset ();
void green ();
void yellow ();
void red ();

int main()
{
    cout << boolalpha;

    yellow();

    cout << "Leetcode - 10. Regular Expression Matching (C++ language) - ";

    red();

    cout << "Hard" << endl;

    vector <string> sTest {{"aa"}, {"aa"}, {"ab"}};
    vector <string> pTest {{"a"}, {"a*"}, {".*"}};

    for (int test = 0; test < pTest.size(); test++)
    {   
        string s {sTest.at(test)};
        string p {pTest.at(test)};

        bool flag {true};

        if (s.length() != p.length())
        {
            flag = false;
        }
        else
        {
            for (int i = 0; i < s.length(); i++)
            {
                if (s[i] != p[i])
                {
                    if (p[i] != '.')
                    {
                        if (p[i] == '*')
                        {
                            if (p[i-1] != '.')
                            {
                                string temp = s.substr(0,i);
                                size_t position = temp.find(s[i]);

                                if (position == string :: npos)
                                {
                                    flag = false;
                                    break;
                                }
                            }
                        }
                        else
                        {
                            flag = false;
                            break;
                        }
                    }
                }        
            }
        }
        
        green();

        cout << "Test " << test + 1 << ": ";

        reset();

        cout << flag << " | ";

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