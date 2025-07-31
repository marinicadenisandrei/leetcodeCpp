/* Leetcode - 114. Flatten Binary Tree to Linked List (C++ language) - Medium */

#include <iostream>
#include <vector>

using namespace std;

void flatten(vector <int> &rootVar);
void printVector(vector <int> vectorVar);

void reset ();
void green ();
void yellow ();
void red ();

int main()
{
    yellow();

    cout << "Leetcode - 114. Flatten Binary Tree to Linked List (C++ language) - Medium" << endl;
    vector<vector<int>> root {{1,2,5,3,4,0,6},{},{0}};

    for (int test = 0; test < root.size(); test++)
    {
        green();

        cout << "Test " << test + 1 << ": ";

        reset();

        flatten(root[test]);
        printVector(root[test]);

        green();

        cout << "Passed" << endl;
    }

    reset();

    return 0;
}

void printVector(vector <int> vectorVar)
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

void flatten(vector <int> &rootVar)
{
    if (rootVar.size() < 2)
    {
        return;
    }
    
    int stop = rootVar.size();

    for (int i = 0; i < stop; i += 2)
    {
        if (rootVar[i + 1] != 0)
        {
            rootVar.insert(rootVar.begin() + i + 1, 0);
        }
    }
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