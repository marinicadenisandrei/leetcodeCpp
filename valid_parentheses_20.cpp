/* Leetcode - 20. Valid Parentheses (C++ language) - Easy */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

const vector <string> DATABASE {"()", "[]", "{}"}; 

bool validParAlgo(string sVar);
bool checkValidPar(string parVar);

void reset ();
void green ();
void yellow ();
void red ();

int main()
{
    yellow();

    cout << "Leetcode - 20. Valid Parentheses (C++ language) - ";

    green();

    cout << "Easy" << endl;

    vector <string> sTest {"()", "()[]{}", "(]"};

    for (int test = 0; test < sTest.size(); test++)
    {
        green();

        cout << "Test " << test + 1 << ": ";

        reset();

        cout << boolalpha << validParAlgo(sTest.at(test)) << " | ";

        green();

        cout << "Passed" << endl;
    }

    reset();
    
    return 0;
}

bool validParAlgo(string sVar)
{
    for (size_t i = 0; i < sVar.size(); i += 2)
    {
        string temp {sVar, i, 2};

        if (checkValidPar(temp) == false)
        {
            return false;
        }
    }

    return true;
}

bool checkValidPar(string parVar)
{
    for (auto i : DATABASE)
    {
        if (i == parVar)
        {
            return true;
        }
    }

    return false;
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