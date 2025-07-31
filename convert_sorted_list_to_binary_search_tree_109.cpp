/* Leetcode - 109. Convert Sorted List to Binary Search Tree (C++ language) - Medium */

#include <iostream>
#include <vector>

using namespace std;

vector<int> sortedListToBST(vector<int> headVar);
void printArray(vector<int> vectorVar);

void reset ();
void green ();
void yellow ();
void red ();

int main()
{
    yellow();

    cout << "Leetcode - 109. Convert Sorted List to Binary Search Tree (C++ language) - Medium" << endl;

    vector<vector<int>> head {{-10,-3,0,5,9},{}};

    for (int test = 0; test < head.size(); test++)
    {
        green();

        cout << "Test " << test + 1 << ": ";

        reset();

        vector<int> result = sortedListToBST(head[test]);
        printArray(result);

        green();

        cout << "Passed" << endl;
    }

    reset();

    return 0;
}

void printArray(vector<int> vectorVar)
{
    if (vectorVar.size() == 0)
    {
        cout << "[] | ";
    }
    
    for (int i = 0; i < vectorVar.size(); i++)
    {
        cout << ((i == 0) ? "[" : "") << vectorVar[i] << ((i < vectorVar.size() - 1) ? ", " : "] | ");
    }
}

vector<int> sortedListToBST(vector<int> headVar)
{   
    int len = headVar.size() - 1;
    int middle = len / 2;
    vector<int> BST {};

    if (headVar.size() == 0)
    {
        return BST;
    }

    BST.push_back(headVar[middle]);

    for (int i = 0; i < middle; i++)
    {
        BST.push_back(headVar[middle - i - 1]);

        if (i > 0)
        {
            BST.push_back(0);
        }
        
        BST.push_back(headVar[len - i]);
    }

    return BST;
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