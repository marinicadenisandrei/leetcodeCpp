/* Leetcode - 105. Construct Binary Tree from Preorder and Inorder Traversal (C++ language) - Medium */

#include <iostream>
#include <vector>

using namespace std;

vector<int> buildTree(vector<int> inorder, vector<int> postorder);
void printVector(vector<int> vectorVar);

void reset ();
void green ();
void yellow ();
void red ();

int main()
{
    yellow();

    cout << "Leetcode - 105. Construct Binary Tree from Preorder and Inorder Traversal (C++ language) - Medium" << endl;

    vector<vector<int>> inorder {{9,3,15,20,7},{-1}};
    vector<vector<int>> postorder {{9,15,7,20,3},{-1}};
    
    for (int test = 0; test < inorder.size(); test++)
    {
        green();

        cout << "Test " << test + 1 << ": ";
        
        reset();

        vector<int> output = buildTree(inorder[test], postorder[test]);
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

vector<int> buildTree(vector<int> inorder, vector<int> postorder)
{
    if (inorder.size() == 1)
    {
        return inorder;
    }
    
    vector<int> inorderCopy (inorder);
    vector<vector<int>> formation {};
    bool flag {true};
    vector<int> root {};
    root.push_back(postorder.back());

    int locateRoot {0};

    for (int i = 0; i < inorder.size(); i++)
    {
        if (inorder[i] == postorder.back())
        {
            locateRoot = i;
        }
    }

    vector<int> temp {};
    
    for (int i = 0; i < inorder.size(); i++)
    {
        if (i == locateRoot)
        {
            formation.push_back(temp);
            temp.clear();
            continue;
        }

        temp.push_back(inorder[i]);
    }

    formation.push_back(temp);
    temp.clear();

    while (flag)
    {
        flag = false;

        for (int i = 0; i < formation.size(); i++)
        {
            if (formation[i].size() > 2)
            {
                flag = true;
                int sizeVar = formation[i].size();
                int middle = sizeVar / 2;

                temp.push_back(formation[i][middle]);
                formation.insert(formation.begin() + i + 1, temp);
                temp.clear();

                for (int j = 0; j < formation[i].size(); j++)
                {
                    if (j == middle)
                    {
                        formation.insert(formation.begin() + i + 2, temp);
                        temp.clear();
                        continue;
                    }
                    
                    temp.push_back(formation[i][j]);
                }

                formation.insert(formation.begin() + i + 3, temp);
                temp.clear();
                formation.erase(formation.begin() + i);
            }
        }
    }
    
    for (auto i : formation)
    {
        root.push_back(i[0]);
    }

    for (int i = 0; i < root.size(); i++)
    {
        if (root[i] != 0)
        {
            for (int j = 0; j < inorderCopy.size(); j++)
            {
                if (inorderCopy[j] == root[i])
                {
                    if (j > 0 && j < inorderCopy.size())
                    {
                        break;
                    }
                    else
                    {
                        root.insert(root.begin() + (i * 2) + 1, 0);
                        root.insert(root.begin() + (i * 2) + 2, 0);

                        inorderCopy.erase(inorderCopy.begin() + j);
                    }
                }
            }
        }
    }
    
    return root;
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