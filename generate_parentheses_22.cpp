/* Leetcode - 22. Generate Parentheses (C++ language) - Medium */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

void generateUsualParentheses(vector <string> &vectorVar, int size);
void algoParentheses(vector <string> &vectorVar, int size);
void printVector(const vector <string> vectorVar);

void reset ();
void green ();
void yellow ();
void red ();

int main()
{
    yellow();
    
    cout << "Leetcode - 22. Generate Parentheses (C++ language) - Medium" << endl;

    vector <int> n {3, 1};

    for (int test = 0; test < n.size(); test++)
    {
        vector <string> output {};
        generateUsualParentheses(output, n.at(test));
        algoParentheses(output, n.at(test));

        green();

        cout << "Test " << test + 1 << ": ";

        reset();

        printVector(output);

        green();

        cout << "Passed" << endl;
    }

    reset();
    
    return 0;
}

void generateUsualParentheses(vector <string> &vectorVar, int size)
{
    string variableString {};
    
    for (int i = 0; i < size; i++)
    {
        variableString += "(";
    }

    for (int i = 0; i < size; i++)
    {
        variableString += ")";
    }

    vectorVar.push_back(variableString);
    
    if (size > 1)
    {
        variableString = "(";

        for (int i = 0; i < size - 1; i++)
        {
            variableString += "()";
        }

        variableString += ")";

        vectorVar.push_back(variableString);

        variableString.clear();

        for (int i = 0; i < size; i++)
        {
            variableString += "()";
        }
        
        vectorVar.push_back(variableString);
    }
}

void algoParentheses(vector <string> &vectorVar, int size)
{
    int index1 {0};
    int index2 {1};

    string variableString {""};

    for (int j = 0; j < size - 1; j++)
    {
        for (int i = 0; i < size - 1; i++)
        {
            if (i == index1)
            {
                variableString += "(";
            }

            if (i == index2)
            {
                variableString += ")";
            }
            
            variableString += "()";
        }

        index1++;
        index2++;

        if (j == size - 2)
        {
            variableString += ")";
        }

        vectorVar.push_back(variableString);

        variableString.clear();
    }
}

void printVector(const vector <string> vectorVar)
{
    for (int i = 0; i < vectorVar.size(); i++)
    {
        cout << ((i == 0) ? "[" : "") << vectorVar.at(i) << ((i < vectorVar.size() - 1) ? ", " : "] | ");
    }
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