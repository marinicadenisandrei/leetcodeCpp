/* Leetcode - 233. Number of Digit One (C++ language) - Hard */

#include <iostream>
#include <vector>

using namespace std;

void reset ();
void green ();
void yellow ();
void red ();

int CountDigitOne(int nVar);

int main()
{
    yellow();

    cout << "Leetcode - 233. Number of Digit One (C++ language) - ";

    red();
    
    cout << "Hard" << endl;

    vector<int> n = {13, 0};
    
    for (int test = 0; test < n.size(); test++)
    {
        green();

        cout << "Test " << test + 1 << ": ";

        reset();

        cout << CountDigitOne(n[test]) << " | ";

        green();

        cout << "Passed" << endl;
    }

    reset();

    return 0;
}

int CountDigitOne(int nVar)
{
    int counter = 0;

    for (int i = 1; i <= nVar; i++)
    {
        int temp = i;
        
        while (temp > 0)
        {
            int last = temp % 10;
            temp /= 10;

            counter += (last == 1);
        }
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