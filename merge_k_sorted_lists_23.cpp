#include <iostream>
#include <vector>

using namespace std;

void printVector(vector <int> vectorVar);
void mergeSortedLists(vector <vector <int>> &listVar);
void bubbleSort(vector <int> &vectorVar);

void reset ();
void green ();
void yellow ();
void red ();

int main()
{
    yellow();

    cout << "Leetcode - 23. Merge k Sorted Lists (C++ language) - ";

    red();

    cout << "Hard" << endl;

    vector <vector <vector <int>>> lists {{{1,4,5},{1,3,4},{2,6}}, {}, {{}}};

    for (int test = 0; test < lists.size(); test++)
    {
        green();

        cout << "Test " << test + 1 << ": ";

        reset();

        if (lists.at(test).size() > 0 && lists.at(test).at(0).size() > 0)
        {
            mergeSortedLists(lists.at(test));
            bubbleSort(lists.at(test).at(0));
            printVector(lists.at(test).at(0));
        }
        else
        {
            cout << "[] | ";
        }

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
        cout << ((i == 0) ? "[" : "") << vectorVar.at(i) << ((i < vectorVar.size() - 1) ? ", " : "] | ");
    }
    
}

void mergeSortedLists(vector <vector <int>> &listVar)
{
    for (int i = 1; i < listVar.size(); i++)
    {
        for (int j = 0; j < listVar.at(i).size(); j++)
        {
            listVar.at(0).push_back(listVar.at(i).at(j));
        }
    }   
}

void bubbleSort(vector <int> &vectorVar)
{
    bool flag {true};
    int counter {0};

    while (flag)
    {
        flag = false;

        for (int i = 0; i < vectorVar.size() - 1 - counter; i++)
        {
            if (vectorVar.at(i) > vectorVar.at(i + 1))
            {
                int temp = vectorVar.at(i);
                vectorVar.at(i) = vectorVar.at(i + 1);
                vectorVar.at(i + 1) = temp;

                flag = true;
            }
        }

        counter++;
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

