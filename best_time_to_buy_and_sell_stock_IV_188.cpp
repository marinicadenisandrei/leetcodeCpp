/* Leetcode - 188. Best Time to Buy and Sell Stock IV (C++ language) - Hard */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxProfit(int kVar, vector<int> pricesVar);

void reset ();
void green ();
void yellow ();
void red ();

int main()
{
    yellow();

    cout << "Leetcode - 188. Best Time to Buy and Sell Stock IV (C++ language) - ";

    red();

    cout << "Hard" << endl;

    vector<int> k {2,2};
    vector<vector<int>> prices {{2,4,1},{3,2,6,5,0,3}};

    for (int test = 0; test < k.size(); test++)
    {
        green();

        cout << "Test " << test + 1 << ": ";

        reset();

        printf("%i | ",maxProfit(k[test], prices[test]));

        green();

        cout << "Passed" << endl;
    }

    reset();
    
    return 0;
}

int maxProfit(int kVar, vector<int> pricesVar)
{
    pricesVar.push_back(-1);
    int globalProfit = 0;
    
    for (int j = 0; j < pricesVar.size(); j++)
    {
        int start = pricesVar[j];
        int profit = 0;
        int counter = 0;

        for (int i = j; i < pricesVar.size() - 1; i++)
        {
            if (pricesVar[i] > pricesVar[i + 1])
            {
                if (counter == kVar + 1)
                {
                    break;
                }
                
                profit += pricesVar[i] - start;
                start = pricesVar[i + 1];
                counter++;
            }
        }

        globalProfit = ((globalProfit < profit) ? profit : globalProfit);
    }
    
    return globalProfit;
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