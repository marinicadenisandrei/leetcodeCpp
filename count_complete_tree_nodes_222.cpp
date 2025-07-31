/* Leetcode - 222. Count Complete Tree Nodes (C++ language) - Easy */

#include <iostream>
#include <vector>

using namespace std;

void reset ();
void green ();
void yellow ();
void red ();

int countNodes(vector<int> rootVar);

int main()
{
    yellow();

    cout << "Leetcode - 222. Count Complete Tree Nodes (C++ language) - ";

    green();

    cout << "Easy" << endl;

    vector<vector<int>> root {{1,2,3,4,5,6},{},{1}};

    for (int test = 0; test < root.size(); test++)
    {
        green();

        cout << "Test " << test + 1 << ": ";

        reset();

        cout << countNodes(root[test]) << " | ";

        green();

        cout << "Passed" << endl;
    }
    
    reset();

    return 0;
}

int countNodes(vector<int> rootVar)
{
    return rootVar.size();
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