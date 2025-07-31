/* Leetcode - 282. Expression Add Operators (C++ language) - Hard */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> addOperators(string numVar, int targetVar);
string calculator(string expression, string operand, int result);
void printVector(vector<string> vect);

void reset ();
void green ();
void yellow ();
void red ();

int main()
{
    yellow();

    cout << "Leetcode - 282. Expression Add Operators (C++ language) - ";

    red();

    cout << "Hard" << endl;

    vector<string> num = {"123","232","3456237490"};
    vector<int> target = {6,8,9191};

    for (int test = 0; test < target.size(); test++)
    {
        green();

        cout << "Test " << test + 1 << ": ";

        reset();

        printVector(addOperators(num[test], target[test]));

        green();

        cout << "Passed" << endl;
    }

    reset();
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

string calculator(string expression, string operand, int result)
{
    int tempCalculate = 0;
    string tempString = "";

    if (operand == "+")
    {
        for (int i = 0; i < expression.size(); i++)
        {
            tempCalculate += (expression[i] - '0');
            tempString += expression[i];
            tempString += (i < expression.size() - 1) ? "+" : "";
        }
    }
    else if (operand == "*")
    {
        tempCalculate = 1;

        for (int i = 0; i < expression.size(); i++)
        {
            tempCalculate *= (expression[i] - '0');
            tempString += expression[i];
            tempString += (i < expression.size() - 1) ? "*" : "";
        }
    }
    else if (operand == "+*")
    {
        for (int i = 0; i < expression.size(); i++)
        {
            if (i % 2 == 0)
            {
                tempCalculate += (expression[i] - '0');
                tempString += expression[i];
                tempString += (i < expression.size() - 1) ? "+" : "";
            }
            else
            {
                tempCalculate *= (expression[i] - '0');
                tempString += expression[i];
                tempString += (i < expression.size() - 1) ? "*" : "";
            }
        }
    }
    else if (operand == "*+")
    {
        tempCalculate = expression[0] - '0';

        tempString += expression[0];
        tempString += "*";

        for (int i = 1; i < expression.size(); i++)
        {
            if (i % 2 == 1)
            {
                tempCalculate *= (expression[i] - '0');
                tempString += expression[i];
                tempString += (i < expression.size() - 1) ? "*" : "";
            }
            else
            {
                tempCalculate += (expression[i] - '0');
                tempString += expression[i];
                tempString += (i < expression.size() - 1) ? "+" : "";
            }
        }
    }
    
    if (tempCalculate == result)
    {
        return tempString;
    }

    return "";
}

vector<string> addOperators(string numVar, int targetVar)
{
    vector<string> result = {};
    vector<string> operands = {"+", "*", "+*", "*+"};

    for (int i = 0; i < operands.size(); i++)
    {
        string res = calculator(numVar, operands[i], targetVar);

        if (res != "")
        {
            result.push_back(res);
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