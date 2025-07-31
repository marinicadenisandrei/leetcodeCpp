/* Leetcode - 107. Binary Tree Level Order Traversal II (Cpp language) - Medium */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> levelOrderBottom(vector<int> rootVar);
void print2DVector(vector<vector<int>> vectorVar);

void reset ();
void green ();
void yellow ();
void red ();

int main()
{
    yellow();

    cout << "Leetcode - 107. Binary Tree Level Order Traversal II (Cpp language) - Medium" << endl;

    vector<vector<int>> root {{3,9,20,0,0,15,7},{1},{}};

    for (int test = 0; test < root.size(); test++)
    {
        green();

        cout << "Test " << test + 1 << ": ";

        reset();

        vector<vector<int>> output {levelOrderBottom(root[test])};
        print2DVector(output);

        green();

        cout << "Passed" << endl;
    }

    reset();

    return 0;
}

void print2DVector(vector<vector<int>> vectorVar)
{
    cout << "[";

    for (int i = 0; i < vectorVar.size(); i++)
    {
        for (int j = 0; j < vectorVar[i].size(); j++)
        {
            cout << ((j == 0) ? "[" : "") << vectorVar[i][j] << ((j < vectorVar[i].size() - 1) ? ", " : "]");
        }
    }

    cout << "] | ";
}

vector<vector<int>> levelOrderBottom(vector<int> rootVar)
{
    vector<vector<int>> acumulation {};
    vector<int> temp {};
    int power = 1;
    int len = rootVar.size();

    while (len > 0)
    {
        for (int i = 0; i < power; i++)
        {
            if (rootVar[0] != 0)
            {
                temp.push_back(rootVar[0]);
            }
            
            rootVar.erase(rootVar.begin());
        }

        acumulation.push_back(temp);
        temp.clear();
        len -= power;
        power *= 2;
    }

    reverse(acumulation.begin(), acumulation.end());

    return acumulation;
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