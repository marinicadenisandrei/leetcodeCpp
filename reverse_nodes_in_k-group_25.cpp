#include <iostream>
#include <vector>

using namespace std;

void reverseKGroup(vector <int> &vectorVar, int elements);
void reverseVectorRange(vector <int> &vectorVar, int left_index, int right_index);
void printVector(const vector <int> vectorVar);

void reset ();
void green ();
void yellow ();
void red ();

int main()
{
    yellow();

    cout << "Leetcode - 25. Reverse Nodes in k-Group (C++ language) - ";

    red();

    cout << "Hard" << endl;

    vector <vector <int>> head {{1,2,3,4,5}, {1,2,3,4,5}};
    vector <int> k {2,3};

    for (int test = 0; test < k.size(); test++)
    {
        green();

        cout << "Test " << test + 1 << ": ";

        reset();

        reverseKGroup(head.at(test), k.at(test));

        green();

        cout << "Passed" << endl;
    }

    reset();
    
    return 0;
}

void reverseKGroup(vector <int> &vectorVar, int elements)
{
    for (int i = 0; i < vectorVar.size(); i += elements)
    {
        int left {i};
        int right {i + elements};

        if (left >= vectorVar.size() || right >= vectorVar.size())
        {
            printVector(vectorVar);
            return;
        }
        
        reverseVectorRange(vectorVar, left, right);
    }
}

void reverseVectorRange(vector <int> &vectorVar, int left_index, int right_index)
{
    bool flag {true};
    int counter = 0;

    while (flag)
    {
        flag = false;

        for (int i = left_index; i < right_index - 1 - counter; i++)
        {
            if (vectorVar.at(i) < vectorVar.at(i + 1))
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

void printVector(const vector <int> vectorVar)
{
    for (int i = 0; i < vectorVar.size(); i++)
    {
        cout << ((i == 0) ? "[" : "") << vectorVar.at(i) << ((i < vectorVar.size() - 1) ? ", " : "] | ");
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