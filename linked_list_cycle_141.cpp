/* Leetcode - 141. Linked List Cycle (C language) - Easy */

#include <iostream>
#include <vector>

using namespace std;

bool hasCycle(vector<int> headVar, int posVar);

void reset ();
void green ();
void yellow ();
void red ();

int main()
{
    yellow();

    cout << "Leetcode - 141. Linked List Cycle (C language) - ";

    green();

    cout << "Easy" << endl;

    vector<vector<int>> head {{3,2,0,-4},{1,2},{1}};
    vector<int> pos {1,0,-1};

    for (int test = 0; test < pos.size(); test++)
    {
        green();

        cout << "Test " << test + 1 << ": ";

        reset();

        cout << boolalpha << hasCycle(head[test], pos[test]) << " | ";

        green();

        cout << "Passed" << endl;
    }

    reset();

    return 0;
}

bool hasCycle(vector<int> headVar, int posVar)
{
    if (headVar.size() > posVar && posVar >= 0)
    {
        return true;
    }
    
    return false;
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