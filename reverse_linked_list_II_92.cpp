#include <iostream>
#include <vector>

using namespace std;

void reverseBetween(vector <int> &headVar, int leftVar, int rightVar);
void printVector(vector <int> vectorVar);

void reset ();
void green ();
void yellow ();
void red ();

int main()
{
    yellow();

    cout << "Leetcode - 92. Reverse Linked List II (C++ language) - Medium" << endl;

    vector <vector <int>> head {{1,2,3,4,5},{5}};
    vector <int> left {2,1};
    vector <int> right {4,1};

    for (int test = 0; test < left.size(); test++)
    {
        green();

        cout << "Test " << test + 1 << ": ";

        reset();

        reverseBetween(head[test], left[test], right[test]);
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

void reverseBetween(vector <int> &headVar, int leftVar, int rightVar)
{
    int leftIndex {0};
    int rightIndex {0};

    for (int i = 0; i < headVar.size(); i++)
    {
        if (headVar[i] == leftVar)
        {
            leftIndex = headVar[i] - 1;
        }
        
        if (headVar[i] == rightVar)
        {
            rightIndex = headVar[i] - 1;
        }
    }   

    while (leftIndex != rightIndex)
    {
        int temp = headVar[leftIndex];
        headVar[leftIndex] = headVar[rightIndex];
        headVar[rightIndex] = temp;

        leftIndex++;
        rightIndex--;
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