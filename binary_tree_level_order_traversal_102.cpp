/* Leetcode - 102. Binary Tree Level Order Traversal (C++ language) - Medium */

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> levelOrder(vector<int> rootVar);
void print2DVector(vector<vector<int>> vectorMatrix);

void reset ();
void green ();
void yellow ();
void red ();

int main()
{
    yellow();

    cout << "Leetcode - 102. Binary Tree Level Order Traversal (C++ language) - Medium" << endl;

    vector<vector<int>> root {{3,9,20,0,0,15,7},{1},{}};

    for (int test = 0; test < root.size(); test++)
    {
        green();

        cout << "Test " << test + 1 << ": ";

        reset();

        vector<vector<int>> result = levelOrder(root[test]);
        print2DVector(result);

        green();

        cout << "Passed" << endl;
    }

    reset();

    return 0;
}

void print2DVector(vector<vector<int>> vectorMatrix)
{
    if (vectorMatrix.size() == 0)
    {
        cout << "[[]] | ";
        return;
    }
    
    for (int i = 0; i < vectorMatrix.size(); i++)
    {
        for (int j = 0; j < vectorMatrix[i].size(); j++)
        {
            cout << ((i == 0) ? "[" : "") << ((j == 0) ? "[" : "") << vectorMatrix[i][j] << ((j < vectorMatrix[i].size() - 1) ? ", " : "]");
        }
    }

    cout << "] | ";
}

vector<vector<int>> levelOrder(vector<int> rootVar)
{   
    vector<vector<int>> output {};
    vector<int> temp {};

    if (rootVar.size() == 0)
    {
        return output;
    }

    temp.push_back(rootVar[0]);
    output.push_back(temp);
    temp.clear();

    for (int i = 0; i < rootVar.size(); i++)
    {
        if (((i * 2) + 2) > rootVar.size())
        {
            break;
        }
        
        if (rootVar[(i * 2) + 1] != 0 && rootVar[(i * 2) + 2] != 0)
        {
            temp.push_back(rootVar[(i * 2) + 1]);
            temp.push_back(rootVar[(i * 2) + 2]);
            output.push_back(temp);
            temp.clear();
        }
    }


    return output;
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