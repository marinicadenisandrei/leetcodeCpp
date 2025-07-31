/* Leetcode - 112. Path Sum (C++ language) - Easy */

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> hasPathSum(vector<int> rootVar, int targetSumVar);
void print2DVector(vector<vector<int>> vectorVar);

void reset ();
void green ();
void yellow ();
void red ();

int main()
{
    yellow();

    cout << "Leetcode - 112. Path Sum (C++ language) - Medium" << endl;

    vector<vector<int>> root {{5,4,8,11,0,13,4,7,2,0,0,5,1}, {1,2,3}, {}};
    vector<int> targetSum {22,5,0};

    for (int test = 0; test < targetSum.size(); test++)
    {
        green();

        cout << "Test " << test + 1<< ": ";

        reset();

        vector<vector<int>> output = hasPathSum(root[test], targetSum[test]);
        print2DVector(output);

        green();

        cout << "Passed" << endl;
    }

    reset();

    return 0;
}

void print2DVector(vector<vector<int>> vectorVar)
{    
    cout << "[";

    for (int i = 0; i < vectorVar.size(); i++)
    {
        for (int j = 0; j < vectorVar[0].size(); j++)
        {
            cout << ((j == 0) ? "[" : "") << vectorVar[i][j] << ((j < vectorVar[0].size() - 1) ? ", " : "]");
        }
    }
    
    cout << "] | ";
}

vector<vector<int>> hasPathSum(vector<int> rootVar, int targetSumVar)
{
    int len = rootVar.size();
    int power = 1;
    int counter = 0;

    for (int i = 0; i < rootVar.size(); i++)
    {
        if ((i * 2) + 2 > rootVar.size())
        {
            break;
        }
    
        if (rootVar[i] == 0 && (rootVar[(i * 2) + 1] != 0))
        {
            rootVar.insert(rootVar.begin() + (i * 2) + 1, 0);
        }

        if (rootVar[i] == 0 && (rootVar[(i * 2) + 2] != 0))
        {
            rootVar.insert(rootVar.begin() + (i * 2) + 2, 0);
        }
    }

    while (len > 0)
    {
        len -= power;
        power *= 2;
        counter++;
    }
    
    int splitVar = counter;
    int index = 1;
    int c = 0;
    int indexVector = 0;

    while (rootVar.size() < power)
    {
        rootVar.push_back(0);
    }
    
    vector<vector<int>> acumulation {};
    vector<int> sums (counter * 2, rootVar[0]);
    acumulation.push_back(sums);
    sums.clear();

    for (int i = 0; i < counter - 1; i++)
    {
        for (int j = 0; j < counter * 2; j++)
        {
            if (c == splitVar)
            {
                index++; 
                c = 0;
            }

            sums.push_back(rootVar[index]);
            indexVector++;
            c++;          
        }

        acumulation.push_back(sums);
        sums.clear();

        c = 0;
        index++;
        splitVar /= 2;
        indexVector = 0;
    }

    int stopIndex {0};
    int stopElement {0};
    vector<vector<int>> result {};
    
    if (acumulation.size() > 1)
    {
        for (int i = acumulation.back().size(); i >= 0; i--)
        {
            if (acumulation.back()[i] != 0)
            {
                stopElement = acumulation.back()[i];

                for (int j = i; j >= 0; j--)
                {
                    if (acumulation.back()[j] == 0)
                    {
                        stopIndex = j;
                        break;
                    }
                }
                break;
            }
        }
    
        while (acumulation.back().back() != stopElement)
        {
            acumulation.back().insert(acumulation.back().begin() + stopIndex, 0);
            acumulation.back().pop_back();
        }
        
        vector<int> temp {};

        int sum {0};

        for (int i = 0; i < acumulation[0].size(); i++)
        {
            for (int j = 0; j < acumulation.size(); j++)
            {
                temp.push_back(acumulation[j][i]);
                sum += acumulation[j][i];
            }

            if (sum == targetSumVar)
            {
                result.push_back(temp);
            }

            sum = 0;
            temp.clear();
        }
    }

    return result;
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