/* Leetcode - 58. Length of Last Word (C++ language) - Easy */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int lengthOfLastWord(string sVar);

void reset ();
void green ();
void yellow ();
void red ();

int main()
{
    yellow();

    cout << "Leetcode - 58. Length of Last Word (C++ language) - ";

    green();

    cout << "Easy" << endl;

    vector <string> s {"Hello World", "   fly me   to   the moon  ", "luffy is still joyboy"};

    for (int test = 0; test < s.size(); test++)
    {
        green();

        cout << "Test " << test + 1 << ": ";

        reset();

        cout << lengthOfLastWord(s[test]) << " | ";

        green();

        cout << "Passed" << endl;
    }

    reset();

    return 0;
}

int lengthOfLastWord(string sVar)
{
    int counter {0};

    for (int i = sVar.size() - 1; i >= 0; i--)
    {
        if (sVar[i] != ' ')
        {
            for (int j = i; j >= 0; j--)
            {
                if (sVar[j] == ' ')
                {
                    return counter;
                }
                
                counter++;
            }
        }
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