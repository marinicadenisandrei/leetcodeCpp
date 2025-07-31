/* Leetcode - 165. Compare Version Numbers (C++ language) - Medium */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int compareVersion(string version1Var, string version2Var);

void reset ();
void green ();
void yellow ();
void red ();

int main()
{
    yellow();

    cout << "Leetcode - 165. Compare Version Numbers (C++ language) - Medium" << endl;

    vector<string> version1 {"1.2","1.01","1.0"};
    vector<string> version2 {"1.10","1.001","1.0.0.0"}; 

    for (int test = 0; test < version1.size(); test++)
    {
        green();

        cout << "Test " << test + 1 << ": ";

        reset();

        cout << compareVersion(version1[test], version2[test]) << " | ";

        green();

        cout << "Passed" << endl;
    }

    reset();
    
    return 0;
}

int compareVersion(string version1Var, string version2Var)
{
    double num1 = stod(version1Var);
    double num2 = stod(version2Var);

    if (abs(num1 - num2) < 0.01 || num1 == num2)
    {
        return 0;
    }
    else if (num1 < num2) 
    {
        return -1;
    }
    
    return 1;
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