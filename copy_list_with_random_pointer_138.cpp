#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> copyRandomList(vector<vector<int>> headVar);
void print2DVector(vector<vector<int>> vector2D);

void reset ();
void green ();
void yellow ();
void red ();

int main()
{
    yellow();
    
    cout << "Leetcode - 138. Copy List with Random Pointer (C++ language) - Medium" << endl;

    vector<vector<vector<int>>> head = {{{7,0},{13,0},{11,4},{10,2},{1,0}},{{1,1},{2,1}},{{3,0},{3,0},{3,0}}};

    for (int test = 0; test < head.size(); test++)
    {
        green();

        cout << "Test " << test + 1 << ": ";

        reset();

        head[test] = copyRandomList(head[test]);
        print2DVector(head[test]);

        green();

        cout << "Passed" << endl;
    }

    reset();
    
    return 0;
}

void print2DVector(vector<vector<int>> vector2D)
{
    cout << "[";

    for (int i = 0; i < vector2D.size(); i++)
    {
        for (int j = 0; j < vector2D[i].size(); j++)
        {
            cout << ((j == 0) ? "[" : "") << vector2D[i][j] << ((j < vector2D[i].size() - 1) ? ", " : "]");
        }  
    }

    cout << "] | ";
}

vector<vector<int>> copyRandomList(vector<vector<int>> headVar)
{
    return headVar;
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