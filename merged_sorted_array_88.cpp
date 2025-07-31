/* Leetcode - 88. Merge Sorted Array (C++ language) - Easy */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void merge(vector<int> &nums1Var, int mVar, vector<int> &nums2Var, int nVar);
void printVector(vector<int> vectorVar);

void reset ();
void green ();
void yellow ();
void red ();


int main()
{
    yellow();

    cout << "Leetcode - 88. Merge Sorted Array (C++ language) - ";

    green();

    cout << "Easy" << endl;

    vector<vector<int> >nums1 = {{1,2,3,0,0,0},{1},{0}};
    vector<int> m = {3,1,0};
    
    vector<vector<int>> nums2 = {{2,5,6},{},{1}};
    vector<int> n = {3,0,1};

    for (int test = 0; test < m.size(); test++)
    {
        green();

        cout << "Test " << test + 1 << ": ";

        reset();

        merge(nums1[test], m[test], nums2[test], n[test]);
        printVector(nums1[test]);

        green();

        cout << "Passed" << endl;
    }

    reset();
    
    return 0;
}

void printVector(vector<int> vectorVar)
{
    for (int i = 0; i < vectorVar.size(); i++)
    {
        cout << ((i == 0) ? "[" : "") << vectorVar[i] << ((i < vectorVar.size() - 1) ? ", " : "]");
    }
    
    cout << " | ";
}

void merge(vector<int> &nums1Var, int mVar, vector<int> &nums2Var, int nVar)
{
    nums1Var.resize(mVar);
    nums1Var.insert(nums1Var.end(), nums2Var.begin(), nums2Var.end());
    sort(nums1Var.begin(), nums1Var.end());
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