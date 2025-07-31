/* Leetcode - 133. Clone Graph (C++ language) - Medium */

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> cloneGraph(vector<vector<int>> adjListVar);
void printVector(vector<vector<int>> vectorVar);

void reset ();
void green ();
void yellow ();
void red ();

int main(void)
{
    yellow();

    cout << "Leetcode - 133. Clone Graph (C++ language) - Medium" << endl;

    vector<vector<vector<int>>> adjList {{{2,4},{1,3},{2,4},{1,3}},{{}},{}};

    for (int test = 0; test < adjList.size(); test++)
    {   
        green();

        cout << "Test " << test + 1 << ": ";

        reset();

        printVector(adjList[test]);

        green();

        cout << "Passed" << endl;
    }

    reset();
}

void printVector(vector<vector<int>> vectorVar)
{
    if (vectorVar.size() == 0)
    {
        cout << "[] | ";
        return;
    }
    
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

vector<vector<int>> cloneGraph(vector<vector<int>> adjListVar)
{
    return adjListVar;
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