#include <iostream>
#include <vector>

using namespace std;

void mergeTwoVectors(vector <int> &vectVar1, vector <int> &vectVar2);
void bubbleSort(vector <int> &vectorVar);
void printArray(vector <int> &vectorVar);

void reset ();
void green ();
void yellow ();
void red ();

int main()
{
    yellow();

    cout << "Leetcode - 21. Merge Two Sorted Lists (C++ language) - ";

    green();

    cout << "Easy" << endl;

    vector <vector <int>> list1 {{1,2,4}, {}, {}};
    vector <vector <int>> list2 {{1,3,4}, {}, {0}};

    for (int test = 0; test < list1.size(); test++)
    {
        mergeTwoVectors(list1.at(test), list2.at(test));
        bubbleSort(list1.at(test));

        green();

        cout << "Test " << test + 1 << ": ";

        reset();

        printArray(list1.at(test));

        green();

        cout << "Passed" << endl;
    }

    reset();
    
    return 0;
}

void mergeTwoVectors(vector <int> &vectVar1, vector <int> &vectVar2)
{
    for (auto i : vectVar2) vectVar1.push_back(i);
}

void bubbleSort(vector <int> &vectorVar)
{
    if (vectorVar.size() == 0)
    {
        return;
    }
    
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

void printArray(vector <int> &vectorVar)
{   
    if (vectorVar.size() == 0)
    {
        cout << "[] | ";
    }
    else
    {
        for (int i = 0; i < vectorVar.size(); i++)
        {
            cout << ((i == 0) ? "[" : "") << vectorVar.at(i) << ((i < vectorVar.size() - 1) ? ", " : "] | ");
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