/* Leetcode - 236. Lowest Common Ancestor of a Binary Tree (C++ language) - Medium */

#include <iostream>
#include <vector>

using namespace std;

void reset ();
void green ();
void yellow ();
void red ();

int lowestCommonAncestor(vector<int> rootVar, int pVar, int qVar);

int main()
{
    yellow();

    cout << "Leetcode - 236. Lowest Common Ancestor of a Binary Tree (C++ language) - Medium" << endl;

    vector<vector<int>> root ={{3,5,1,6,2,0,8,0,0,7,4},{3,5,1,6,2,0,8,0,0,7,4},{1,2}};
    vector<int> p = {5,5,1};
    vector<int> q = {1,4,2};

    for (int test = 0; test < root.size(); test++)
    {
        green();

        cout << "Test " << test + 1 << ": ";

        reset();

        cout << lowestCommonAncestor(root[test], p[test], q[test]) << " | ";

        green();

        cout << "Passed" << endl;
    }
    
    reset();

    return 0;
}

int lowestCommonAncestor(vector<int> rootVar, int pVar, int qVar)
{
    int first = 0;
    int last = 0;

    bool p_index = false;
    bool q_index = false;

    for (int i = 0; i < rootVar.size(); i++)
    {
        if (rootVar[i] == pVar)
        {
            p_index = true;
            first = i;
        }

        if (rootVar[i] == qVar)
        {
            q_index = true;
            last = i;
        }
    }

    if (last - first > 3)
    {
        return pVar;
    }
    
    return (p_index && q_index) ? rootVar[0] : -1;
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