/* Leetcode - 378. Kth Smallest Element in a Sorted Matrix (C++ language) - Medium */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void reset ();
void green ();
void yellow ();
void red ();

int kthSmallest(vector<vector<int>> matrixVar, int kVar);

int main()
{
    yellow();

    cout << "Leetcode - 378. Kth Smallest Element in a Sorted Matrix (C++ language) - Medium\n";

    vector<vector<vector<int>>> matrix = {{{1,5,9},{10,11,13},{12,13,15}},{{-5}}};
    vector<int> k = {8,1};

    for (int test = 0; test < matrix.size(); test++)
    {
        green();

        cout << "Test " << (test + 1) << ": ";

        reset();

        cout << kthSmallest(matrix[test], k[test]) << " | ";

        green();

        cout << "Passed\n";
    }
    
    reset();

    return 0;
}

int kthSmallest(vector<vector<int>> matrixVar, int kVar)
{
    vector<int> numbers = {};

    for (int i = 0; i < matrixVar.size(); i++)
    {
        for (int j = 0; j < matrixVar[i].size(); j++)
        {
            numbers.push_back(matrixVar[i][j]);
        }
    }
    
    sort(numbers.begin(), numbers.end());

    return numbers[kVar - 1];
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