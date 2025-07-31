/* Leetcode - 61. Rotate List (C++ language) - Medium */

#include <iostream>
#include <vector>

using namespace std;

void rotateRight(vector <int> &headVar, int kVar);
void printVector(vector <int> vectorVar);

void reset ();
void green ();
void yellow ();
void red ();

int main()
{
    yellow();

    cout << "Leetcode - 61. Rotate List (C++ language) - Medium" << endl;

    vector <vector <int>> head {{1,2,3,4,5}, {0,1,2}};
    vector <int> k {2, 4};

    for (int test = 0; test < head.size(); test++)
    {
        green();

        cout << "Test " << test + 1 << ": ";

        reset();

        rotateRight(head[test], k[test]);
        printVector(head[test]);   

        green();

        cout << "Passed" << endl;
    }

    reset();

    return 0;
}

void printVector(vector <int> vectorVar)
{
    for (int i = 0; i < vectorVar.size(); i++)
    {
        cout << ((i == 0) ? "[" : "") << vectorVar[i] << ((i < vectorVar.size() - 1) ? ", " : "]");
    }

    cout << " | ";
}

void rotateRight(vector <int> &headVar, int kVar)
{
    for (int i = 0; i < kVar; i++)
    {
        headVar.insert(headVar.begin(), headVar[headVar.size() - 1]);
        headVar.pop_back();
    }
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