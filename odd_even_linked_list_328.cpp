/* Leetcode - 328. Odd Even Linked List (C++ language) - Medium */

#include <iostream>
#include <vector>

using namespace std;

void reset ();
void green ();
void yellow ();
void red ();

vector<int> oddEvenList(vector<int> headVar);
void printVect(vector<int> vect);

int main()
{
    yellow();

    cout << "Leetcode - 328. Odd Even Linked List (C++ language) - Medium" << endl;

    vector<vector<int>> head = {{1,2,3,4,5},{2,1,3,5,6,4,7}};
    
    for (int test = 0; test < head.size(); test++)
    {
        green();

        cout << "Test " << (test + 1) << ": ";

        reset();

        printVect(oddEvenList(head[test]));

        green();

        cout << "Passed" << endl;
    }

    reset();
    
    return 0;
}

void printVect(vector<int> vect)
{
    for (int i = 0; i < vect.size(); i++)
    {
        cout << ((i == 0) ? "[" : "") << vect[i] << ((i < vect.size() - 1) ? ", " : "] | ");
    }
}

vector<int> oddEvenList(vector<int> headVar)
{
    vector<int> result;

    for (int i = 0; i < headVar.size(); i += 2)
    {
        result.push_back(headVar[i]);
    }
    
    for (int i = 1; i < headVar.size() - 1; i += 2)
    {
        result.push_back(headVar[i]);
    }

    return result;
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