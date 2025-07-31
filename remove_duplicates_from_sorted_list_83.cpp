/* Leetcode - 83. Remove Duplicates from Sorted List (C++ language) - Easy */

#include <iostream>
#include <vector>

using namespace std;

void deleteDuplicates(vector <int> &headVar);
void printVector(vector <int> vectorVar);

void reset ();
void green ();
void yellow ();
void red ();

int main()
{
    yellow();

    cout << "Leetcode - 83. Remove Duplicates from Sorted List (C++ language) - ";

    green();

    cout << "Easy" << endl;

    vector <vector <int>>head {{1,1,2},{1,1,2,3,3}};

    for (int test = 0; test < head.size(); test++)
    {
        green();

        cout << "Test " << test + 1 << ": ";

        reset();

        deleteDuplicates(head[test]);
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

void deleteDuplicates(vector <int> &headVar)
{
    for (int i = 0; i < headVar.size(); i++)
    {
        for (int j = 0; j < headVar.size(); j++)
        {
            if (i != j && headVar[i] == headVar[j])
            {
                headVar.erase(headVar.begin() + i);
            }
        }
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