/* Leetcode - 144. Binary Tree Preorder Traversal (C++ language) - Easy */

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

vector<int> preorderTraversal(vector<int> rootVar);
void printVector(const vector<int>& vectorVar);

void reset ();
void green ();
void yellow ();
void red ();

int main()
{
    yellow();

    cout << "Leetcode - 144. Binary Tree Preorder Traversal (C++ language) - ";
    
    green();

    cout << "Easy" << endl;

    vector<vector<int>> root {{1,0,2,3},{},{1}};

    for (int test = 0; test < root.size(); test++)
    {   
        green();

        cout << "Test " << test + 1 << ": ";

        reset();

        vector<int> result = preorderTraversal(root[test]);
        printVector(result);

        green();

        cout << "Passed" << endl;
    }

    reset();
}

void printVector(const vector<int>& vectorVar)
{
    if (vectorVar.size() == 0)
    {
        cout << "[] | ";
        return;
    }
    
    for (int i = 0; i < vectorVar.size(); i++)
    {
        cout << ((i == 0) ? "[" : "") << vectorVar[i] << ((i < vectorVar.size() - 1) ? ", " : "] | ");
    }
}

vector<int> preorderTraversal(vector<int> rootVar)
{
    rootVar.erase(remove_if(rootVar.begin(), rootVar.end(), [] (int num) {
        return num == 0;
    }), rootVar.end());

    return rootVar;
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