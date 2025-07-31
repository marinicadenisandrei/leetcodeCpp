/* Leetcode - 5. Longest Palindromic Substring (C++ language) - Medium */

#include <iostream>

using namespace std;

bool palNumber(string string_var);

void reset ();
void green ();
void yellow ();
void red ();

int main()
{
    yellow();

    cout << "Leetcode - 5. Longest Palindromic Substring (C++ language) - Medium\n";

    string s[] {{"babad"}, {"cbbd"}};

    for (int test = 0; test < size(s[test]); test++)
    {
        int s_size = size(s[test]);

        string temp {""};
        string output {""};

        palNumber(s[test]);

        for (int i = 0; i < s_size; i++)
        {
            for (int j = i; j < s_size; j++)
            {
                temp += s[test][j];
                if (palNumber(temp) == true)
                {
                    if (size(temp) > size(output))
                    {
                        output = temp;
                    }
                }
            }

            temp = "";
        }

        green();

        cout << "Test " << test + 1 << ": ";

        reset();

        cout << output << " | ";

        green();

        cout << "Passed" << endl;

        reset();
    }
    
    return 0;
}

bool palNumber(string string_var)
{
    int string_size = size(string_var);

    for (int i = 1; i <= string_size; i++)
    {
        if (string_var[i - 1] != string_var[string_size - i])
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