/* Leetcode - 226. Invert Binary Tree (C++ language) - Easy */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void reset ();
void green ();
void yellow ();
void red ();

vector<int> InvertTree(vector<int> root);
void printVector(vector<int> vect);

int main()
{
    yellow();

    cout << "Leetcode - 226. Invert Binary Tree (C++ language) - ";

    green();

    cout << "Easy" << endl;

    vector<vector<int>> root {{4,2,7,1,3,6,9},{2,1,3},{}};
    
    for (int test = 0; test < root.size(); test++)
    {
        green();

        cout << "Test " << test + 1 << ": ";

        reset();

        printVector(InvertTree(root[test]));

        green();

        cout << "Passed" << endl;
    }

    reset();
    
    return 0;
}

void printVector(vector<int> vect)
{
    if (vect.size() == 0)
    {
        cout << "[] | ";
        return;
    }

    for (int i = 0; i < vect.size(); i++)
    {
        cout << ((i == 0) ? "[" : "") << vect[i] << ((i < vect.size() - 1) ? ", " : "] | ");
    }
}

vector<int> InvertTree(vector<int> root)
{
    vector<int> invertRoot = {};
    int powerVar = 2;

    if (root.size() == 0)
    {
        return invertRoot;
    }
    
    invertRoot.push_back(root[0]);
    root.erase(root.begin());

    while (root.size() > 0)
    {
        vector<int> subvec(root.begin(), root.begin() + powerVar);
        reverse(subvec.begin(), subvec.end());

        for (int i : subvec)
        {
            invertRoot.push_back(i);
        }

        root.erase(root.begin(), root.begin() + powerVar);
        powerVar *= 2;
    }
    
    return invertRoot;
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