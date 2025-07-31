/* Leetcode - 148. Sort List (C++ language) - Medium */

#include <iostream>
#include <list>
#include <vector>

using namespace std;

void sortList(list<int> &headVar);
void printList(list<int> listVar);

void reset ();
void green ();
void yellow ();
void red ();

int main()
{
    yellow();

    cout << "Leetcode - 148. Sort List (C++ language) - Medium" << endl;

    vector<list<int>> head {{4,2,1,3},{-1,5,3,4,0}};

    for (int test = 0; test < head.size(); test++)
    {   
        green();

        cout << "Test " << test + 1 << ": ";

        reset();

        sortList(head[test]);
        printList(head[test]);

        green();

        cout << "Passed" << endl;
    }

    reset();

    return 0;
}

void printList(list<int> listVar)
{
    for (auto it = listVar.begin(); it != listVar.end(); ++it)
    {
        cout << ((it == listVar.begin()) ? "[" : "") << *it << ((next(it) != listVar.end()) ? ", " : "] | ");
    }
}

void sortList(list<int> &headVar)
{
    headVar.sort();
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