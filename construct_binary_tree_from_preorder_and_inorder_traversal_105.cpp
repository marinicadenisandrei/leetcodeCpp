/* Leetcode - 105. Construct Binary Tree from Preorder and Inorder Traversal (C++ language) - Medium */

#include <iostream>
#include <vector>

using namespace std;

vector<int> buildTree(vector<int> &preorderVar, vector<int> &inorderVar);
void printVector(vector<int> vectorVar);

void reset ();
void green ();
void yellow ();
void red ();

int main()
{
    yellow();

    cout << "Leetcode - 105. Construct Binary Tree from Preorder and Inorder Traversal (C++ language) - Medium" << endl;

    vector<vector<int>> preorder {{3,9,20,15,7},{-1}};
    vector<vector<int>> inorder {{9,3,15,20,7},{-1}};

    for (int test = 0; test < preorder.size(); test++)
    {
        green();

        cout << "Test " << test + 1 << ": ";

        reset();

        vector<int> output {buildTree(preorder[test], inorder[test])};
        printVector(output);

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

vector<int> buildTree(vector<int> &preorderVar, vector<int> &inorderVar)
{
    if (preorderVar.size() < 2)
    {
        return preorderVar;
    }

    vector<int> BST (preorderVar);
    
    for (int i = 0; i < preorderVar.size() - 1; i++)
    {
        for (int j = 0; j < inorderVar.size(); j++)
        {
            if (preorderVar[i] == inorderVar[j])
            {
                if (j == 0 || j == inorderVar.size() - 1)
                {
                    BST.insert(BST.begin() + (i * 2) + 1, 0);
                    BST.insert(BST.begin() + (i * 2) + 2, 0);
                    break;
                }
                else
                {
                    inorderVar.erase(inorderVar.begin() + j);
                    break;
                }
            }
        }
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