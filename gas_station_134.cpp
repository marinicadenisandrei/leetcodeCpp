/* Leetcode - 134. Gas Station (C++ language) - Medium */

#include <iostream>
#include <vector>

using namespace std;

int canCompleteCircuit(vector<int> gasVar, vector<int> costVar);

void reset ();
void green ();
void yellow ();
void red ();

int main()
{
    yellow();

    cout << "Leetcode - 134. Gas Station (C++ language) - Medium" << endl;

    vector<vector<int>> gas {{1,2,3,4,5},{2,3,4}};
    vector<vector<int>> cost {{3,4,5,1,2},{3,4,5}};
    
    for (int test = 0; test < gas.size(); test++)
    {   
        green();

        cout << "Test " << test + 1 << ": ";

        reset();

        cout << canCompleteCircuit(gas[test], cost[test]) << " | ";

        green();

        cout << "Passed" << endl;
    }

    reset();
}

int canCompleteCircuit(vector<int> gasVar, vector<int> costVar)
{
    for (int i = 0; i < gasVar.size(); i++)
    {
        int index = i;
        bool flag = true;

        vector<int> newGas {};
        vector<int> newCost {};

        for (int i = index; i < gasVar.size(); i++)
        {
            newGas.push_back(gasVar[i]);
            newCost.push_back(costVar[i]);
        }

        for (int i = 0; i <= 3; i++)
        {
            newGas.push_back(gasVar[i]);
            newCost.push_back(costVar[i]);
        }

        int startingGas = (newGas[0] - newCost[0]) + newGas[1];

        for (int i = 1; i < newGas.size() - 1; i++)
        {
            if (startingGas - newCost[i] < 0)
            {
                flag = false;
                break;
            }
            startingGas = startingGas - newCost[i] + newGas[i + 1];
        }

        if (flag)
        {
            return index;
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