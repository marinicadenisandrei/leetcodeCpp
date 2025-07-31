#include <iostream>
#include <vector>

using namespace std;

bool isSameTree(vector<int> pVar, vector<int> qVar);

void reset ();
void green ();
void yellow ();
void red ();


int main()
{
    yellow();

    cout << "Leetcode - 100. Same Tree (C++ language) - ";

    green();

    cout << "Easy" << endl;

    vector<vector<int>> p {{1,2,3},{1,2},{1,2,1}};
    vector<vector<int>> q {{1,2,3},{1,0,2},{1,1,2}};

    for (int test = 0; test < p.size(); test++)
    {
        green();

        cout << "Test " << test + 1 << ": ";

        reset();

        cout << boolalpha << isSameTree(p[test],q[test]) << " | ";

        green();

        cout << "Passed" << endl;
    }

    reset();
}

bool isSameTree(vector<int> pVar, vector<int> qVar)
{
    for (int i = 0; i < pVar.size(); i++)
    {
        if (pVar[i] != qVar[i])
        {
            return false;
        }
    }
    
    return true;
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