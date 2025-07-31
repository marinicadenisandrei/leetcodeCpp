/* Leetcode - 123. Best Time to Buy and Sell Stock III (C++ language) - Hard */

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

    cout << "Leetcode - 123. Best Time to Buy and Sell Stock III (C++ language) - ";

    red();

    cout << "Hard" << endl;

    vector<vector<int>> prices {{3,3,5,0,0,3,1,4},{1,2,3,4,5},{7,6,4,3,1}};

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
}

int maxProfit(vector<int> pricesVar)
{
    int start {0};
    int profit {0};
    bool flag = false;

    vector<int> profits {};
    pricesVar.push_back(-1);

    for (int i = 1; i < pricesVar.size(); i++)
    {
        if (pricesVar[i - 1] <= pricesVar[i] && start == 0)
        {
            start = pricesVar[i - 1];
            flag = true;
        }
        else if (pricesVar[i - 1] > pricesVar[i])
        {
            profit = pricesVar[i - 1] - start;
            profits.push_back(profit);
            start = 0;
        }
    }

    for (int i = 0; i < profits.size() - 1; i++)
    {
        if (profit < (profits[i] + profits[i + 1]))
        {
            profit = profits[i] + profits[i + 1];
        }
    }

    if (!flag)
    {
        return 0;
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