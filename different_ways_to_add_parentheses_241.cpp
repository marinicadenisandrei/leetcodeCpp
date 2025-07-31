/* Leetcode - 241. Different Ways to Add Parentheses (C++ language) - Medium */

#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <unordered_map>
#include <cstdlib>

using namespace std;

unordered_map<string, vector<int>> memo;

void reset ();
void green ();
void yellow ();
void red ();

vector<int> diffWaysToCompute(string expressionVar);
void printVector(vector<int> vect);

int main()
{
    yellow();

    cout << "Leetcode - 241. Different Ways to Add Parentheses (C++ language) - Medium" << endl;

    vector<string> expression = {"2-1-1","2*3-4*5"};

    for (int test = 0; test < expression.size(); test++)
    {
        green();
        
        cout << "Test " << test + 1 << ": ";

        reset();

        printVector(diffWaysToCompute(expression[test]));

        green();

        cout << "Passed" << endl;
    }

    reset();

    return 0;
}

void printVector(vector<int> vect)
{
    for (int i = 0; i < vect.size(); i++)
    {
        cout << ((i == 0) ? "[" : "") << vect[i] << ((i < vect.size() - 1) ? ", " : "] | ");
    }
}

vector<int> diffWaysToCompute(string expressionVar)
{
    if (memo.count(expressionVar))
    {
        return memo[expressionVar];
    }
    
    vector<int> res;

    for (int i = 0; i < expressionVar.size(); i++)
    {
        char c = expressionVar[i];

        if (c == '+' || c == '-' || c == '*')
        {
            string left = expressionVar.substr(0,i);
            string right = expressionVar.substr(i + 1);
            
            vector<int> leftRes= diffWaysToCompute(left);
            vector<int> rightRes = diffWaysToCompute(right);

            for(int a : leftRes) {
                for (int b : rightRes)
                {
                    if (c == '+') res.push_back(a + b);
                    else if (c == '-') res.push_back(a - b);
                    else if (c == '*') res.push_back(a * b);
                }
            }
        }
    }

    if (res.empty())
    {
        res.push_back(stoi(expressionVar));
    }

    memo[expressionVar] = res;
    
    return res;
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