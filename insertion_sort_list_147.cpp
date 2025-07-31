/* Leetcode - 147. Insertion Sort List (C++ language) - Medium */

#include <iostream>
#include <vector>

using namespace std;

vector<int> insertionSortList(vector<int> headVar);
void printVector(vector<int> vectorVar);

void reset ();
void green ();
void yellow ();
void red ();

int main()
{
    yellow();

    cout << "Leetcode - 147. Insertion Sort List (C++ language) - Medium" << endl;

    vector<vector<int>> head {{4,2,1,3},{-1,5,3,4,0}};

    for (int test = 0; test < head.size(); test++)
    {   
        green();

        cout << "Test " << test + 1 << ": "; 

        reset();

        head[test] = insertionSortList(head[test]);
        printVector(head[test]);

        green();

        cout << "Passed" << endl;
    }

    reset();
}

void printVector(vector<int> vectorVar)
{
    for (int i = 0; i < vectorVar.size(); i++)
    {
        cout << ((i == 0) ? "[" : "") << vectorVar[i] << ((i < vectorVar.size() - 1) ? ", " : "] | ");
    }
}

vector<int> insertionSortList(vector<int> headVar)
{
    for (int i = 1; i < headVar.size(); i++)
    {
        bool flag = false;

        for (int j = i; j >= 0; j--)
        {
            if (headVar[j] > headVar[i] && (headVar[j] < headVar[i - 1] || j == 0))
            {
                auto position = headVar.begin() + j;
                headVar.insert(position, headVar[i]);
                headVar.erase(headVar.begin() + i + 1);
                flag = true;

                break;
            }
        }
    }

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