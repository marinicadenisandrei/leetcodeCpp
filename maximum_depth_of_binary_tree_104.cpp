#include <iostream>
#include <vector>

using namespace std;

int maxDepth(const vector<int> &rootVar);

void reset ();
void green ();
void yellow ();
void red ();


int main()
{
    yellow();
    
    cout << "Leetcode - 104. Maximum Depth of Binary Tree (C++ language) - ";

    green();

    cout << "Easy" << endl;

    const vector<vector<int>> root {{3,9,20,0,0,15,7},{1,0,2}};
    
    for (int test = 0; test < root.size(); test++)
    {
        green();

        cout << "Test " << test + 1 << ": ";

        reset();

        cout << maxDepth(root[test]) << " | ";

        green();

        cout << "Passed" << endl;
    }

    reset();
    
    return 0;
}

int maxDepth(const vector<int> &rootVar)
{
    int length = rootVar.size();
    int depth = 1;
    int counter = 0;

    while (length > 0)
    {
        length -= depth;
        depth *= 2;
        counter++;
    }
    
    return counter;
}

void reset () {
  printf("\033[1;0m");
}

void green () {
  printf("\033[1;32m");
}

void yellow () {
  printf("\033[1;33m");
}

void red () {
  printf("\033[1;31m");
}