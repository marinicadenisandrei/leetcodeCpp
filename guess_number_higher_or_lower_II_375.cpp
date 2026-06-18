/* Leetcode - 375. Guess Number Higher or Lower II (C++ language) - Medium */

#include <iostream>
#include <vector>

using namespace std;

void reset ();
void green ();
void yellow ();
void red ();

int getMoneyAmount(int nVar);
int calculate(vector<int> vect);

int main()
{
    yellow();

    cout << "Leetcode - 375. Guess Number Higher or Lower II (C++ language) - Medium\n";

    vector<int> n = {10,1,2};
    
    for (int test = 0; test < n.size(); test++)
    {
        green();

        cout << "Test " << (test + 1) << ": ";

        reset();

        cout << getMoneyAmount(n[test]) << " | ";

        green();

        cout << "Passed\n";
    }
    
    reset();

    return 0;
}

int calculate(vector<int> vect)
{
    if (vect.size() <= 1)
    {
        return 0;
    }

    int bestCost = INT_MAX;

    for (int i = 0; i < vect.size(); i++)
    {
        int chosenNumber = vect[i];

        vector<int> firstHalf(vect.begin(), vect.begin() + i);
        vector<int> secondHalf(vect.begin() + i + 1, vect.end());

        int leftCost = calculate(firstHalf);
        int rightCost = calculate(secondHalf);

        int currentCost = chosenNumber + max(leftCost, rightCost);
        bestCost = min(bestCost, currentCost);
    }

    return bestCost;
}

int getMoneyAmount(int nVar)
{
    vector<int> startVect;

    for (int i = 1; i <= nVar; i++)
    {
        startVect.push_back(i);
    }

    return calculate(startVect);
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