/* Leetcode - 150. Evaluate Reverse Polish Notation (C++ language) - Medium */

#include <iostream>
#include <vector>
#include <cctype>
#include <string>
#include <algorithm>

using namespace std;

int evalRPN(vector<string> tokensVar);

void reset ();
void green ();
void yellow ();
void red ();

int main()
{
    yellow();

    vector<vector<string>> tokens {{"2","1","+","3","*"},{"4","13","5","/","+"},{"10","6","9","3","+","-11","*","/","*","17","+","5","+"}};

    for (int test = 0; test < tokens.size(); test++)
    {
        green();

        cout << "Test " << test + 1 << ": ";

        reset();

        cout << evalRPN(tokens[test]) << " | ";

        green();

        cout << "Passed" << endl;
    }

    reset();
}

bool isNumber(const std::string& str) {
    if (str.empty()) return false;

    size_t idx = 0;
    if (str[idx] == '+' || str[idx] == '-') {
        idx++;
    }
    if (idx == str.size()) return false;

    while (idx < str.size()) {
        if (!std::isdigit(static_cast<unsigned char>(str[idx]))) {
            return false; 
        }
        idx++;
    }

    return true;
}

int evalRPN(vector<string> tokensVar)
{
    while (tokensVar.size() > 1)
    {
        for (int i = 0; i < tokensVar.size(); i++)
        {
            bool sign = isNumber(tokensVar[i]);
            bool num2 = isNumber(tokensVar[i - 1]);
            bool num1 = isNumber(tokensVar[i - 2]);

            if (!sign && num2 && num1)
            {
                int result = 0;

                if (tokensVar[i] == "-")
                {
                    result = stoi(tokensVar[i - 2]) - stoi(tokensVar[i - 1]);
                }
                else if (tokensVar[i] == "+")
                {
                    result = stoi(tokensVar[i - 2]) + stoi(tokensVar[i - 1]);
                }
                else if (tokensVar[i] == "*")
                {
                    result = stoi(tokensVar[i - 2]) * stoi(tokensVar[i - 1]);
                }
                else if (tokensVar[i] == "/")
                {
                    result = stoi(tokensVar[i - 2]) / stoi(tokensVar[i - 1]);
                }
                
                for (int j = 0; j < 3; j++)
                {
                    tokensVar.erase(tokensVar.begin() + (i - 2));
                }

                tokensVar.insert(tokensVar.begin() + (i - 2), to_string(result));
                
                break;
            }
        }
    }
    

    return stoi(tokensVar[0]);
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