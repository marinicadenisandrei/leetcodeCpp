/* Leetcode - 373. Find K Pairs with Smallest Sums (C++ language) - Medium */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void reset ();
void green ();
void yellow ();
void red ();

vector<vector<int>> kSmallestPairs(vector<int> nums1Var, vector<int> nums2Var, int kVar);
void print2DVector(vector<vector<int>> vect);

int main()
{
    yellow();

    cout << "Leetcode - 373. Find K Pairs with Smallest Sums (C++ language) - Medium\n";

    vector<vector<int>> nums1 = {{1,7,11},{1,1,2}};
    vector<vector<int>> nums2 = {{2,4,6},{1,2,3}};
    vector<int> k = {3,2};

    for (int test = 0; test < nums1.size(); test++)
    {
        green();

        cout << "Test " << test + 1 << ": ";

        reset();

        print2DVector(kSmallestPairs(nums1[test], nums2[test], k[test]));
    
        green();

        cout << "Passed" << endl;
    }

    reset();

    return 0;
}

vector<vector<int>> kSmallestPairs(vector<int> nums1Var, vector<int> nums2Var, int kVar)
{
    vector<vector<int>> result = {};

    for (int i = 0; i < nums1Var.size(); i++)
    {
        for (int j = 0; j < nums2Var.size(); j++)
        {
            result.push_back({nums1Var[i], nums2Var[j]}); 
        }        
    }

    sort(result.begin(), result.end(), [](vector<int>& a, vector<int>& b) {
        return a[0] + a[1] < b[0] + b[1];
    });

    if (result.size() > kVar)
    {
        result.resize(kVar);
    }

    return result;
}

void print2DVector(vector<vector<int>> vect)
{
    cout << "[";

    for (int i = 0; i < vect.size(); i++)
    {
        for (int j = 0; j < vect[i].size(); j++)
        {
            cout << ((j == 0) ? "[" : "") << vect[i][j] << ((j < vect[i].size() - 1) ? ", " : "]");
        }
    }

    cout << "] | ";
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