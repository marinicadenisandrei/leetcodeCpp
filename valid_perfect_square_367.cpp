/* Leetcode - 367. Valid Perfect Square (C++ language) - Easy */

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void reset ();
void green ();
void yellow ();
void red ();

bool isPerfectSquare(int numVar);

int main()
{
    cout << boolalpha;

    yellow();

    cout << "Leetcode - 367. Valid Perfect Square (C++ language) - ";

    green();

    cout << "Easy" << endl;

    vector<int> num = {16,14};
    
    for (int test = 0; test < num.size(); test++)
    {
        cout << "Test " << test + 1 <<": ";
        
        reset();
        
        cout << isPerfectSquare(num[test]) << " | ";

        green();

        cout << "Passed" << endl;
    }
    
    reset();

    return 0;
}

bool isPerfectSquare(int numVar)
{
    long long root = sqrt(numVar);
    return root * root == numVar;
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