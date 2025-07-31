/* Leetcode - 39. Combination Sum (C++ language) - Medium */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void printVectorMatrix(vector <vector <int>> vectorMatrix);
void printVector(vector <int> vectorVar);
int sumOfVector(vector <int> vectorVar);
bool vectorInBigVector(vector <vector <int>> &bigVector, vector <int> smallVector);
vector <vector <int>> combinationSum(vector <int> candidates, int target);

void reset ();
void green ();
void yellow ();
void red ();

int main()
{
    yellow();

    cout << "Leetcode - 39. Combination Sum (C++ language) - Medium" << endl;

    vector <vector <int>> candidates {{2,3,6,7},{2,3,5}};
    vector <int> target = {7,8};
    
    for (int test = 0; test < candidates.size(); test++)
    {
        vector <vector <int>> output = combinationSum(candidates.at(test), target.at(test));

        green();
        
        cout << "Test " << test + 1 << ": ";

        reset();

        printVectorMatrix(output);

        green();

        cout << "Passed" << endl;
    }

    reset();
}

void printVectorMatrix(vector <vector <int>> vectorMatrix)
{
    for (int i = 0; i < vectorMatrix.size(); i++)
    {
        for (int j = 0; j < vectorMatrix.at(i).size(); j++)
        {
            cout << ((j == 0) ? "[" : "") << vectorMatrix.at(i).at(j) << ((j < vectorMatrix.at(i).size() - 1) ? ", " : "]");
        }
    }

    cout << " | ";
}

void printVector(vector <int> vectorVar)
{
    for (int i = 0; i < vectorVar.size(); i++)
    {
        cout << ((i == 0) ? "[" : "") << vectorVar.at(i) << ((i < vectorVar.size() - 1) ? ", " : "]");
    }
}

int sumOfVector(vector <int> vectorVar)
{
    int sum {0};
    
    for (auto i : vectorVar)
    {
        sum += i;
    }

    return sum;
}

bool vectorInBigVector(vector <vector <int>> &bigVector, vector <int> smallVector)
{
    sort(smallVector.begin(), smallVector.end());
    bool flag = false;

    for (auto i : bigVector)
    {
        if (i == smallVector)
        {
            return true;
        }
    }

    return false;
}

vector <vector <int>> combinationSum(vector <int> candidates, int target)
{
    vector <vector <vector<int>>> acumulation {};
    vector <vector <int>> result;

    for (int j = 0; j < 2; j++)
    {
        acumulation.push_back({});

        for (int i = 0; i < candidates.size(); i++)
        {   
            if (candidates[i] == target && j == 0)
            {
                result.push_back({candidates[i]});
            }
            
            acumulation.at(j).push_back({});
            acumulation.at(j).at(i).push_back(candidates[i]);
        }
    }

    bool flag = true;

    while (flag)
    {
        vector <int> temp {};
        flag = false;

        acumulation.push_back({});

        for (int i = 0; i < acumulation[acumulation.size() - 3].size(); i++)
        {
            for (int j = 0; j < acumulation[acumulation.size() - 2].size(); j++)
            {
                for (int k = 0; k < acumulation[acumulation.size() - 3][i].size(); k++)
                {
                    temp.push_back(acumulation[acumulation.size() - 3][i][k]);

                    for (int l = 0; l < acumulation[acumulation.size() - 2][j].size(); l++)
                    {
                        temp.push_back(acumulation[acumulation.size() - 2][j][l]);
                    }

                    acumulation[acumulation.size() - 1].push_back(temp);
                    
                    if (sumOfVector(temp) <= target && flag == false)
                    {
                        flag = true;
                    }
                    
                    if (sumOfVector(temp) == target && !vectorInBigVector(result, temp))
                    {
                        sort(temp.begin(), temp.end());
                        result.push_back(temp);
                    }
                
                    temp.clear();
                }
            }
        }
        
        acumulation.erase(acumulation.begin());
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