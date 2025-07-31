/* Leetcode - 237. Delete Node in a Linked List (C++ language) - Medium */

#include <iostream>
#include <vector>

using namespace std;

void reset ();
void green ();
void yellow ();
void red ();

vector<int> deleteNode(vector<int> headVar, int nodeVar);
void printVector(vector<int> vect);

int main()
{
    yellow();

    cout << "Leetcode - 237. Delete Node in a Linked List (C++ language) - Medium" << endl;

    vector<vector<int>> head = {{4,5,1,9},{4,5,1,9}};
    vector<int> node = {5,1};
    
    for (int test = 0; test < head.size(); test++)
    {
        green();

        cout << "Test " << test + 1 << ": ";

        reset();

        printVector(deleteNode(head[test], node[test]));

        green();

        cout << "Passed" << endl;
    }
    
    reset();
}

void printVector(vector<int> vect)
{
    for (int i = 0; i < vect.size(); i++)
    {
        cout << ((i == 0) ? "[" : "") << vect[i] << ((i < vect.size() - 1) ? ", " : "] | ");
    }
}

vector<int> deleteNode(vector<int> headVar, int nodeVar)
{
    int index = 0;

    for (int i = 0; i < headVar.size(); i++)
    {
        if (headVar[i] == nodeVar)
        {
            index = i;
            break;
        }
    }
    
    headVar.erase(headVar.begin() + index);

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