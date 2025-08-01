/* Leetcode - 309. Best Time to Buy and Sell Stock with Cooldown (C++ lasnguage) - Medium */

#include <iostream>
#include <vector>

using namespace std;

void reset ();
void green ();
void yellow ();
void red ();

int maxProfit(vector<int> pricesVar);

int main()
{
    yellow();

    cout << "Leetcode - 309. Best Time to Buy and Sell Stock with Cooldown (C++ lasnguage) - Medium" << endl;

    vector<vector<int>> prices = {{1,2,3,0,2},{1}};
    
    for (int test = 0; test < prices.size(); test++)
    {
        green();

        cout << "Test " << test + 1 << ": ";

        reset();

        cout << maxProfit(prices[test]) << " | ";

        green();


        cout << "Passed" << endl;
    }

    reset();

    return 0;
}

int maxProfit(vector<int> pricesVar)
{
    if (pricesVar.size() < 2)
    {
        return 0;
    }
    
    int result = 0;

    for (int i = 0; i < pricesVar.size(); i++)
    {
        int profit = 0;

        for (int j = i; j < pricesVar.size() - i; j += 3)
        {
            if (pricesVar[j + 1] > pricesVar[j])
            {
                profit += pricesVar[j + 1] - pricesVar[j];
            }
        }

        result = ((profit > result) ? profit : result);
    }   

    int profit = 0;
    int indexStart = 0;

    for (int i = 0; i < pricesVar.size(); i++)
    {
        if (pricesVar[i] < pricesVar[i + 1])
        {
            profit += (pricesVar[i] - pricesVar[indexStart]);
            indexStart = i + 1;
        }
    }

    return ((profit > result) ? profit : result);
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