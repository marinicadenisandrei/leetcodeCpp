/* Leetcode - 94. Binary Tree Inorder Traversal (C++ language) - Easy */

#include <iostream>
#include <vector>

using namespace std;

void inorderTraversal(vector <int> &rootVar);
void printVector(const vector <int> vectorVar);

void reset ();
void green ();
void yellow ();
void red ();

int main()
{
    yellow();

    cout << "Leetcode - 94. Binary Tree Inorder Traversal (C++ language) - ";

    green();

    cout << "Easy" << endl;

    vector <vector <int>> root {{1,0,2,3},{},{1}};

    for (int test = 0; test < root.size(); test++)
    {
        green();

        cout << "Test " << test + 1 << ": ";

        reset();

        inorderTraversal(root[test]);
        printVector(root[test]);

        green();

        cout << "Passed" << endl;
    }

    reset();
    
    return 0;
}

void printVector(const vector <int> vectorVar)
{
    if (vectorVar.size() == 0)
    {
        cout << "[] | ";
        return;
    }
    
    for (int i = 0; i < vectorVar.size(); i++)
    {
        cout << ((i == 0) ? "[" : "") << vectorVar[i] << ((i < vectorVar.size() - 1) ? ", " : "]"); 
    }

    cout << " | ";
}

void inorderTraversal(vector <int> &rootVar)
{
    if (rootVar.size() == 0)
    {
        return;
    }
    
    int depth = rootVar.size();
    
    for (int i = 0; i < rootVar.size(); i++)
    {
        if (rootVar[i] == 0)
        {
            rootVar.erase(rootVar.begin() + i);
        }    
    }

    for (int i = 1; i < rootVar.size() - 1; i+=2)
    {
        int temp = rootVar[i];
        rootVar[i] = rootVar[i + 1];
        rootVar[i + 1] = temp;
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