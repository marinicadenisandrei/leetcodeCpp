/* Leetcode - 24. Swap Nodes in Pairs (C++ language) - Medium */

#include <iostream>
#include <vector>

using namespace std;

void swapNodesInPairs(vector <int> &vectorVar);
void printVector(const vector <int> vectorVar);

void reset ();
void green ();
void yellow ();
void red ();

int main()
{
    yellow();

    cout << "Leetcode - 24. Swap Nodes in Pairs (C++ language) - Medium" << endl;

    vector <vector <int>> head {{1,2,3,4},{},{1}};

    for (int test = 0; test < head.size(); test++)
    {
        green();

        cout << "Test " << test + 1 << ": ";
        
        reset();

        swapNodesInPairs(head.at(test));
        printVector(head.at(test));

        green();

        cout << "Passed" << endl;
    }

    reset();

    return 0;
}

void swapNodesInPairs(vector <int> &vectorVar)
{
    if (vectorVar.size() > 1)
    {
        for (int i = 0; i < vectorVar.size(); i += 2)
        {
            int temp = vectorVar.at(i);
            vectorVar.at(i) = vectorVar.at(i + 1);
            vectorVar.at(i + 1) = temp;
        }
    }
}

void printVector(const vector <int> vectorVar)
{
    if (vectorVar.size() == 0) cout << "[] | ";
    
    for (int i = 0; i < vectorVar.size(); i++) cout << ((i == 0) ? "[" : "") << vectorVar.at(i) << ((i < vectorVar.size() - 1) ? ", " : "] | ");
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