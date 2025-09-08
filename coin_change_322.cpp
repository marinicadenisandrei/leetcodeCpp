/* Leetcode - 322. Coin Change (C++ language) - Medium */

#include <iostream>
#include <vector>

using namespace std;

void reset ();
void green ();
void yellow ();
void red ();

int coinChange(vector<int> coinsVar, int amountVar);

int main()
{
    yellow();

    cout << "Leetcode - 322. Coin Change (C++ language) - Medium" << endl;

    vector<vector<int>> coins = {{1,2,5},{2},{1}};
    vector<int> amount = {11,3,0};
    
    for (int test = 0; test < coins.size(); test++)
    {
        green();

        cout << "Test " << test + 1 << ": ";

        reset();

        cout << coinChange(coins[test], amount[test]) << " | ";

        green();

        cout << "Passed" << endl;
    }

    reset();

    return 0;
}

int coinChange(vector<int> coinsVar, int amountVar)
{
    bool flag = true;
    int counter = 0;

    while (amountVar > 0 && flag)
    {
        flag = false;

        for (int i = coinsVar.size() -1 ; i >= 0; i--)
        {
            if (amountVar >= coinsVar[i])
            {
                amountVar -= coinsVar[i];
                flag = true;

                break;
            }
        }

        counter++;
    }

    return ((amountVar == 0) ? counter : -1);
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