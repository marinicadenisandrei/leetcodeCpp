/* Leetcode - 230. Kth Smallest Element in a BST (C++ language) - Medium */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void reset ();
void green ();
void yellow ();
void red ();

int KthSmallest(vector<int> rootVar, int kVar);

int main()
{
    yellow();

    cout << "Leetcode - 230. Kth Smallest Element in a BST (C++ language) - Medium" << endl;

    vector<vector<int>> root {{3,1,4,0,2},{5,3,6,2,4,0,0,1}};
    vector<int> k {1,3};

    for (int test = 0; test < root.size(); test++)
    {
        green();

        cout << "Test " << test + 1 << ": ";
        
        reset();

        cout << KthSmallest(root[test], k[test]) << " | ";

        green();

        cout << "Passed" << endl;   
    }

    reset();
}

int KthSmallest(vector<int> rootVar, int kVar)
{
    sort(rootVar.begin(), rootVar.end());
    rootVar.erase(std::remove(rootVar.begin(), rootVar.end(), 0), rootVar.end());

    return rootVar[kVar - 1];
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