#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

vector<int> postorderTraversal(vector<int> rootVar);
void printVector(vector<int> vectorVar);

void reset ();
void green ();
void yellow ();
void red ();

int main()
{
    yellow();

    cout << "Leetcode - 145. Binary Tree Postorder Traversal (C++ language) - ";

    green();

    cout << "Easy" << endl;

    vector<vector<int>> root {{1,0,2,3},{},{1}};

    for (int test = 0; test < root.size(); test++)
    {
        green();

        cout << "Test " << test + 1 << ": ";

        reset();

        root[test] = postorderTraversal(root[test]);
        printVector(root[test]);

        green();

        cout << "Passed" << endl;
    }

    reset();
    
    return 0;
}

void printVector(vector<int> vectorVar)
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

vector<int> postorderTraversal(vector<int> rootVar)
{
    vector<int> result {};

    rootVar.erase(remove_if(rootVar.begin(), rootVar.end(), [] (int x) {
        return x == 0;
    }), rootVar.end());

    for_each(rootVar.rbegin(), rootVar.rend(), [&result] (int x) {
        result.push_back(x);
    });

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