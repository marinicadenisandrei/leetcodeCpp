/* Leetcode - 199. Binary Tree Right Side View (C++ language) - Medium */

#include <iostream>
#include <vector>

using namespace std;

vector<int> rightSideView(vector<int> rootVar);
void printVector(vector<int> vectorVar);

void reset ();
void green ();
void yellow ();
void red ();

int main()
{
    yellow();

    cout << "Leetcode - 199. Binary Tree Right Side View (C++ language) - Medium" << endl;

    vector<vector<int>> root {{1,2,3,0,5,0,4},{1,0,3},{}};
    
    for (int test = 0; test < root.size(); test++)
    {
        green();

        cout << "Test " << test + 1 << ": ";

        reset();

        printVector(rightSideView(root[test]));

        green();

        cout << "Passed" << endl;
    }

    reset();
    
    return 0;
}

void printVector(vector<int> vectorVar)
{
    if (vectorVar.size() == 0)
    {
        cout << "[] | ";
    }

    for (int i = 0; i < vectorVar.size(); i++)
    {
        cout << ((i == 0) ? "[" : "") << vectorVar[i] << ((i < vectorVar.size() - 1) ? ", " : "] | ");
    }
}

vector<int> rightSideView(vector<int> rootVar)
{
    if (rootVar.size() == 0)
    {
        return rootVar;
    }
    
    vector<int> result {rootVar[0]};
    
    int power = 2;
    rootVar.erase(rootVar.begin(), rootVar.begin() + 1);

    while (power <= rootVar.size())
    {
        result.push_back(rootVar[power - 1]);
        rootVar.erase(rootVar.begin(), rootVar.begin() + power);
        power *= 2;
    }

    return result;
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