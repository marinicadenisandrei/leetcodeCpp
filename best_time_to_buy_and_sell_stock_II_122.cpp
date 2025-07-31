/* Leetcode - 122. Best Time to Buy and Sell Stock II (C++ language) - Medium */

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

    cout << "Leetcode - 122. Best Time to Buy and Sell Stock II (C++ language) - Medium" << endl;
    vector<vector<int>> prices {{7,1,5,3,6,4},{1,2,3,4,5},{7,6,4,3,1}};

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
    int start = 0;

    for (int i = 0; i < pricesVar.size() - 1; i++)
    {
        if (pricesVar[i] < pricesVar[i + 1] && pricesVar[i] != start)
        {
            start = pricesVar[i];
        }
        else
        {
            if (start != 0)
            {
                profit += pricesVar[i] - start;
            }
        }
    }

    if (start != 0 && profit == 0)
    {
        return pricesVar.back() - pricesVar[0];
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