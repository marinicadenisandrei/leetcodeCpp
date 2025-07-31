/* Leetcode - 216. Combination Sum III (C++ language) - Medium */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void reset ();
void green ();
void yellow ();
void red ();

vector<vector<int>> combinationSum3(int kVar, int nVar);
int sumElements(vector<int> vectorVar);
bool vectorExists(const std::vector<std::vector<int>>& vec2D, const std::vector<int>& vec1D);
bool hasDuplicates(std::vector<int>& vec);
void print2DVector(vector<vector<int>> vec);

int main()
{
    yellow();

    cout << "Leetcode - 216. Combination Sum III (C++ language) - Medium" << endl;

    vector<int> k {3,3,4};
    vector<int> n {7,9,1};

    for (int test = 0; test < k.size(); test++)
    {
        green();

        cout << "Test " << test + 1 << ": ";

        reset();

        print2DVector(combinationSum3(k[test], n[test]));

        green();

        cout << "Passed" << endl;
    }

    reset();
    
    return 0;
}

void print2DVector(vector<vector<int>> vec)
{
    if (vec.size() == 0)
    {
        cout << "[] | ";
        return;
    }

    cout << "[";
    
    for (int i = 0; i < vec.size(); i++)
    {
        for (int j = 0; j < vec[i].size(); j++)
        {
            cout << ((j == 0) ? "[" : "") << vec[i][j] << ((j < vec[i].size() - 1) ? ", " : "]");
        }
    }

    cout << "] | ";
}

bool hasDuplicates(std::vector<int>& vec) 
{
    std::sort(vec.begin(), vec.end());
    return std::adjacent_find(vec.begin(), vec.end()) != vec.end();
}

bool vectorExists(const std::vector<std::vector<int>>& vec2D, const std::vector<int>& vec1D) 
{
    auto it = std::find(vec2D.begin(), vec2D.end(), vec1D);
    return it != vec2D.end();
}

int sumElements(vector<int> vectorVar)
{
    int sum = 0;
    
    for (int i : vectorVar)
    {
        sum += i;
    }
    
    return sum;
}

vector<vector<int>> combinationSum3(int kVar, int nVar)
{
    vector<vector<int>> result = {};
    vector<vector<vector<int>>> acumulation {{{1},{2},{3},{4},{5},{6},{7}},
                                     {}};

    for (int i = 0; i < kVar - 1; i++) {
        vector<vector<int>> newAccumulation;

        for (int j = 0; j < acumulation[0].size(); j++) {
            for (int k = 1; k <= nVar; k++) {             
                vector<int> temp = acumulation[0][j];
                temp.push_back(k);                        
                newAccumulation.push_back(temp);          
            }
        }

        acumulation[0] = newAccumulation;
    }

    for (int i = 0; i < acumulation[0].size(); i++) {
        vector<int> sortedVector = acumulation[0][i];
        sort(sortedVector.begin(), sortedVector.end());

        if (sumElements(sortedVector) == nVar && !vectorExists(result, sortedVector) && !hasDuplicates(sortedVector))
        {
            result.push_back(sortedVector);
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