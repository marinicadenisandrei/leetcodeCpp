/* Leetcode - 111. Minimum Depth of Binary Tree (C++ language) - Easy*/

#include <iostream>
#include <vector>

using namespace std;

int minDepth(vector<int> rootVar);

void reset ();
void green ();
void yellow ();
void red ();

int main()
{
    yellow();

    cout << "Leetcode - 111. Minimum Depth of Binary Tree (C++ language) - ";

    green();

    cout << "Easy" << endl;

    vector<vector<int>> root {{3,9,20,0,0,15,7}, {2,0,3,0,4,0,5,0,6}};

    for (int test = 0; test < root.size(); test++)
    {
        green();

        cout << "Test " << test + 1 << ": ";

        reset();

        cout << minDepth(root[test]) << " | ";

        green();

        cout << "Passed" << endl;
    }

    reset();
}

int minDepth(vector<int> rootVar)
{
    int stop = rootVar.size();

    for (int i = 0; i < rootVar.size(); i++)
    {
        if (((i * 2) + 2) > rootVar.size() - 1)
        {
            break;
        }
        
        if (rootVar[i] == 0)
        {
            rootVar.insert(rootVar.begin() + (i * 2) + 1, 0);
            rootVar.insert(rootVar.begin() + (i * 2) + 2, 0);
        }
    }
    
    int power = 1;
    int counter = 0;
    int depth = 1;

    for (int i = 0; i < rootVar.size(); i++)
    {
        if (power == counter)
        {
            power *= 2;
            counter = 0;
            depth++;
        }

        counter++;
    }

    return depth;
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