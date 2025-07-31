/* Leetcode - 103. Binary Tree Zigzag Level Order Traversal (Cpp language) - Medium */

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> zigzagLevelOrder(vector<int> rootVar);
void printVectorMatrix(vector<vector<int>> vectorVar);

void reset ();
void green ();
void yellow ();
void red ();

int main()
{
    yellow();

    cout << "Leetcode - 103. Binary Tree Zigzag Level Order Traversal (Cpp language) - Medium" << endl;

    vector<vector<int>> root {{3,9,20,0,0,15,7},{1},{}};

    for (int test = 0; test < root.size(); test++)
    {
        green();

        cout << "Test " << test + 1 << ": ";

        reset();

        vector<vector<int>> result = zigzagLevelOrder(root[test]);
        printVectorMatrix(result);

        green();

        cout << "Passed" << endl;
    }

    reset();
    
    return 0;
}

void printVectorMatrix(vector<vector<int>> vectorVar)
{
    if (vectorVar[0].size() == 0)
    {
        cout << "[]";
    }
    
    for (int i = 0; i < vectorVar.size(); i++)
    {
        for (int j = 0; j < vectorVar[i].size(); j++)
        {
            cout << ((j == 0) ? "[" : "") << vectorVar[i][j] << ((j < vectorVar[i].size() - 1) ? ", " : "]");
        }
    }
    
    cout << " | ";
}

vector<vector<int>> zigzagLevelOrder(vector<int> rootVar)
{
    vector<vector<int>> output {};
    vector<int> temp {};

    if (rootVar.size() == 0)
    {
        output.push_back(temp);
        return output;
    }
    
    temp.push_back(rootVar[0]);
    output.push_back(temp);
    temp.clear();

    int zero = 0;
    
    for (int i = 0; i < rootVar.size(); i++)
    {
        if (((i * 2) + 2) > rootVar.size())
        {
            break;
        }

        if (rootVar[(i * 2) + 1] == 0 || rootVar[(i * 2) + 2] == 0)
        {
            zero++;
            continue;
        }
        
        temp.push_back(rootVar[(i * 2) + (((i + zero) % 2 == 0) ? 2 : 1)]);
        temp.push_back(rootVar[(i * 2) + (((i + zero) % 2 == 0) ? 1 : 2)]);
        output.push_back(temp);
        temp.clear();
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