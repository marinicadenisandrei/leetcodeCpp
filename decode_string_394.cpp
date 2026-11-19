/* Leetcode - 394. Decode String (C++ language) - Medium */

#include <iostream>
#include <string>
#include <vector>
#include <cctype>

using namespace std;

string decodeString(string sVar);

void reset ();
void green ();
void yellow ();
void red ();

int main()
{
    yellow();

    cout << "Leetcode - 394. Decode String (C++ language) - Medium" << endl;

    vector<string> s = {"3[a]2[bc]", "3[a2[c]]", "2[abc]3[cd]ef"};
    
    for (int test = 0; test < s.size(); test++)
    {
        green();

        cout << "Test " << test + 1 << ": ";

        reset();

        cout << decodeString(s[test]) << " | ";

        green();

        cout << "Passed" << endl;
    }

    reset();
    
    return 0;
}

string decodeString(string sVar)
{
    string result = "";
    int i = 0;

    while (i < (int)sVar.size())
    {
        if (isdigit((unsigned char)sVar[i]))
        {
            int k = 0;
            while (isdigit((unsigned char)sVar[i]))
            {
                k = k * 10 + (sVar[i++] - '0');
            }

            int start = i + 1;
            int depth = 1;
            i++;

            while (depth > 0)
            {
                if (sVar[i] == '[') depth++;
                else if (sVar[i] == ']') depth--;
                i++;
            }

            string inner = decodeString(sVar.substr(start, i - 1 - start));

            for (int j = 0; j < k; j++)
            {
                result += inner;
            }
        }
        else
        {
            result += sVar[i++];
        }
    }

    return result;
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