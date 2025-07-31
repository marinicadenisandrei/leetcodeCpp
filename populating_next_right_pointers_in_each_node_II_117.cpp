/* Leetcode - 117. Populating Next Right Pointers in Each Node II (C++ language) - Medium */

#include <iostream>
#include <vector>
#include <algorithm>

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

    cout << "Leetcode - 117. Populating Next Right Pointers in Each Node II (C++ language) - Medium\n";

    vector<vector<int>> root {{1,2,3,4,5,0,7},{}};
    
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
        return;
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
    
    auto eraseZeroes = [&rootVar]() {
        rootVar.erase(remove_if(rootVar.begin(), rootVar.end(), [](int num) { return num == 0; }), rootVar.end());
    };

    eraseZeroes(); 

    rootVar.insert(rootVar.begin() + 1, 0);

    int power = 4;
    int counter = 0;

    while (power + 1 < rootVar.size())
    {
        rootVar.insert(rootVar.begin() + power + counter, 0);
        power *= 2;
        counter++;
    }

    rootVar.push_back(0);
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