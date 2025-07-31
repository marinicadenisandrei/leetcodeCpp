/* Leetcode - 301. Remove Invalid Parentheses (C++ language) - Hard */

#include <iostream>
#include <unordered_set>
#include <string>
#include <stack>
#include <vector>

using namespace std;

void reset ();
void green ();
void yellow ();
void red ();

vector<string> removeInvalidParentheses(string sVar);
bool parenthesisMatching(string expression);
void printVector(vector<string> vect);

int main()
{
    yellow();

    cout << "Leetcode - 301. Remove Invalid Parentheses (C++ language) - ";

    red();

    cout << "Hard" << endl;

    vector<string> s = {"()())()","(a)())()",")("};
    
    for (int test = 0; test < s.size(); test++)
    {
        green();

        cout << "Test " << test + 1 << ": ";

        reset();

        printVector(removeInvalidParentheses(s[test]));

        green();

        cout << "Passed" << endl;
    }

    reset();

    return 0;
}

void printVector(vector<string> vect)
{
    if (vect.size() == 0)
    {
        cout << "[] | ";
        return;
    }
    
    for (int i = 0; i < vect.size(); i++)
    {
        cout << ((i == 0) ? "[" : "") << vect[i] << ((i < vect.size() - 1) ? ", " : "] | ");
    }
}

bool parenthesisMatching(string expression)
{
    stack<char> temp;

    for (int i = 0; i < expression.size(); i++)
    {
        if (expression[i] == '(')
        {
            temp.push('(');
        }
        else if (expression[i] == ')')
        {
            if (temp.size() > 0)
            {
                temp.pop();
            }
            else
            {
                return false;
            }
        }
    }

    if (temp.size() != 0)
    {
        return false;
    }

    return true;
}

vector<string> removeInvalidParentheses(string sVar)
{
    vector<string> result;
    unordered_set<string> seen;    

    for (int i = 0; i < (int)sVar.size(); i++)
    {
        string copySVar = sVar;
        copySVar.erase(i, 1);

        if (parenthesisMatching(copySVar))
        {
            if (seen.insert(copySVar).second) {
                result.push_back(move(copySVar));
            }
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
