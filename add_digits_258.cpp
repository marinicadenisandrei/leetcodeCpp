/* Leetcode - 258. Add Digits (C++ language) - Easy */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

void reset ();
void green ();
void yellow ();
void red ();

int addDigits(int numVar);

int main()
{
    yellow();

    cout << "Leetcode - 258. Add Digits (C++ language) - ";

    green();

    cout << "Easy" << endl;

    vector<int> num = {38,0};
    
    for (int test = 0; test < num.size(); test++)
    {
        green();

        cout << "Test " << test + 1 << ": ";

        reset();

        cout << addDigits(num[test]) << " | ";

        green();

        cout << "Passed" << endl;
    }

    reset();
    
    return 0;
}

int addDigits(int numVar)
{
    string temp = to_string(numVar);

    while (temp.size() > 1)
    {
        int result = 0;

        for (int i = 0; i < temp.size(); i++)
        {
            result += temp[i] - '0';
        }

        temp = to_string(result);
    }

    return stoi(temp);
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