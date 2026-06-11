/* Leetcode - 374. Guess Number Higher or Lower (C++ language) - Easy */

#include <iostream>
#include <vector>

using namespace std;

void reset ();
void green ();
void yellow ();
void red ();

int guessNumber(int nVar, int pickVar);

int main()
{
    yellow();

    cout << "Leetcode - 374. Guess Number Higher or Lower (C++ language) - ";

    green();

    cout << "Easy" << endl;

    vector<int> n = {10,1,2};
    vector<int> pick = {6,1,1};

    for (int test = 0; test < n.size(); test++)
    {
        green();

        cout << "Test " << test + 1 << ": ";

        reset();

        cout << guessNumber(n[test], pick[test]) << " | ";

        green();

        cout << "Passed" << endl;
    }

    reset();

    return 0;
}

int guessNumber(int nVar, int pickVar)
{
    int left = 0;
    int right = nVar;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        int result = 0;

        if (mid > pickVar)
        {
            result = -1;
        }
        else if (mid < pickVar)
        {
            result = 1;
        }
        else
        {
            result = 0;
        }
        
        if (result == 0) {
            return mid;
        } 
        else if (result == 1) {
            left = mid + 1;
        } 
        else {
            right = mid - 1;
        }
    }

    return -1;
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