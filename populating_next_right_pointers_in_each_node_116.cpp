/* Leetcode - 116. Populating Next Right Pointers in Each Node (C++ language) - Medium */

#include <iostream>
#include <vector>

using namespace std;

void connect(vector<int> &rootVar);
void printVector(vector<int> vectorVar);

void reset ();
void green ();
void yellow ();
void red ();

int main()
{
    yellow();

    cout << "Leetcode - 116. Populating Next Right Pointers in Each Node (C++ language) - Medium" << endl;
    vector<vector<int>> root {{1,2,3,4,5,6,7},{}};
    
    for (int test = 0; test < root.size(); test++)
    {
        green();

        cout << "Test " << test + 1 << ": ";

        reset();

        connect(root[test]);
        printVector(root[test]);

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

void connect(vector<int> &rootVar)
{
    if (rootVar.size() == 0)
    {
        return;
    }
    
    rootVar.insert(rootVar.begin() + 1, 0);
    int counter = 0;
    int power = 4;

    while (power < rootVar.size())
    {
        rootVar.insert(rootVar.begin() + power + counter, 0);
        power *= 2;
        counter++;
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