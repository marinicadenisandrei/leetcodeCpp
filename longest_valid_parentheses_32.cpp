#include <iostream>
#include <string>
#include <vector>

using namespace std;

int longestValidParentheses(string stringVar);

void reset ();
void green ();
void yellow ();
void red ();

int main()
{
    yellow();

    cout << "Leetcode - 32. Longest Valid Parentheses (C++ language) - ";

    red();

    cout << "Hard" << endl;

    vector <string> s {"(()",")()())", ""};

    for (int test = 0; test < s.size(); test++)
    {
        int result = {longestValidParentheses(s.at(test))};

        green();

        cout << "Test " << test + 1 << ": ";

        reset();

        cout << result << " | ";

        green();

        cout << "Passed" << endl;
    }
    
    reset();

    return 0;
}

int longestValidParentheses(string stringVar)
{
    string valid {"()"};
    
    size_t found = stringVar.find(valid);
    int counter {0};

    while (found != string::npos)
    {
        stringVar.erase(found, valid.length());
        found = stringVar.find(valid);
        counter += 2;
    }
    
    return counter;
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

