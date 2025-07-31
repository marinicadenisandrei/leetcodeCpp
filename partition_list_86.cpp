/* Leetcode - 86. Partition List (C++ language) - Medium */

#include <iostream>
#include <vector>

using namespace std;

void partition(vector <int> &headVar, int xVar);
void sortVectorLimit(vector <int> &vectorVar, int limit);
void printVector(vector <int> vectorVar);

void reset ();
void green ();
void yellow ();
void red ();

int main()
{
    yellow();

    cout << "Leetcode - 86. Partition List (C++ language) - Medium" << endl;

    vector <vector <int>> head {{1,4,3,2,5,2},{2,1}};
    vector <int> x {3,2};

    for (int test = 0; test < x.size(); test++)
    {
        green();

        cout << "Test " << test + 1 << ": ";

        reset();

        partition(head[test], x[test]);
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

void sortVectorLimit(vector <int> &vectorVar, int limit)
{
    bool flag = true;

    while (flag)
    {
        int counter {0};
        flag = false;

        for (int i = 0; i < limit - 1 - counter; i++)
        {
            if (vectorVar[i] > vectorVar[i + 1])
            {
                int temp {vectorVar[i]};
                vectorVar[i] = vectorVar[i + 1];
                vectorVar[i + 1] = temp;

                flag = true;
            }
        }

        counter++;
    }
}

void partition(vector <int> &headVar, int xVar)
{
    bool flag {true};
    int xIndex {0};

    while (flag)
    {
        int counter = 0;
        flag = false;

        for (int i = 0; i < headVar.size(); i++)
        {
            if (headVar[i] == xVar)
            {
                xIndex = i;
            }
        }

        for (int i = xIndex; i < headVar.size() - 1 - counter; i++)
        {
            if (headVar[i] > headVar[i + 1])
            {
                int temp {headVar[i]};
                headVar[i] = headVar[i + 1];
                headVar[i + 1] = temp;
                
                flag = true;
            }
        }

        counter++;
    }

    sortVectorLimit(headVar, xIndex);
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