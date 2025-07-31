/* Leetcode - 143. Reorder List (C++ language) - Medium */

#include <iostream>
#include <vector>

using namespace std;

vector<int> reorderList(vector<int> headVar);
void printVector(vector<int> vectorVar);

void reset ();
void green ();
void yellow ();
void red ();

int main()
{
    yellow();

    cout << "Leetcode - 143. Reorder List (C++ language) - Medium" << endl;

    vector<vector<int>> head {{1,2,3,4},{1,2,3,4,5}};

    for (int test = 0; test < head.size(); test++)
    {
        green();

        cout << "Test " << test + 1 << ": ";

        reset();

        vector<int> result {reorderList(head[test])};
        printVector(result);

        green();

        cout << "Passed" << endl;
    }

    reset();

    return 0;
}

void printVector(vector<int> vectorVar)
{
    for (int i = 0; i < vectorVar.size(); i++)
    {
        cout << ((i == 0) ? "[" : "") << vectorVar[i] << ((i < vectorVar.size() - 1) ? ", " : "] | ");
    }
}

vector<int> reorderList(vector<int> headVar)
{
    auto l = [&] (vector<int> headVar) mutable {
        vector<int> result {};

        for (int i = 0; i < headVar.size() / 2; i++)
        {
            result.push_back(headVar[i]);
            result.push_back(headVar[headVar.size() - 1 - i]);
        }

        if (headVar.size() % 2 != 0)
        {
            result.push_back((headVar.size() / 2) + 1);
        }

        return result;
    };

    return l(headVar);
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