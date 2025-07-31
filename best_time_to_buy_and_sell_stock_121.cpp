/* Leetcode - 121. Best Time to Buy and Sell Stock (C++ language) - Easy */

#include <iostream>
#include <vector>

using namespace std;

int maxProfit(vector<int> pricesVar);

void reset ();
void green ();
void yellow ();
void red ();

int main()
{   
    yellow();

    cout << "Leetcode - 121. Best Time to Buy and Sell Stock (C++ language) - ";

    green();

    cout << "Easy" << endl;

    vector<vector<int>> prices {{7,1,5,3,6,4},{7,6,4,3,1}};

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
    int profit = 0;

    for (int i = 0; i < pricesVar.size(); i++)
    {
        for (int j = i; j < pricesVar.size(); j++)
        {
            profit = ((profit < pricesVar[j] - pricesVar[i]) ? pricesVar[j] - pricesVar[i] : profit);
        }
    }
    
    return profit;
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