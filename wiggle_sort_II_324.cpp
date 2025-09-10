/* Leetcode - 324. Wiggle Sort II (C++ language) - Medium */

#include <iostream>
#include <vector>

using namespace std;

void reset ();
void green ();
void yellow ();
void red ();

vector<int> wiggleSort(vector<int> numsVar);
void printVector(vector<int>vect);

int main()
{
    yellow();

    cout << "Leetcode - 324. Wiggle Sort II (C++ language) - Medium" << endl;

    vector<vector<int>> nums = {{1,5,1,1,6,4},{1,3,2,2,3,1}};
    
    for (int test = 0; test < nums.size(); test++)
    {
        green();

        cout << "Test " << (test + 1) << ": ";

        reset();

        printVector(wiggleSort(nums[test]));

        green();

        cout << "Passed" << endl;
    }

    reset();
    
    return 0;
}

void printVector(vector<int>vect)
{
    for (int i = 0; i < vect.size(); i++)
    {
        cout << ((i == 0) ? "[" : "") << vect[i] << ((i < vect.size() - 1) ? ", " : "] | ");
    }
}

vector<int> wiggleSort(vector<int> numsVar)
{
    vector<int> result = {};

    bool flag = true;
    int c = 0;

    while (flag)
    {
        flag = false;

        for (int i = 0; i < numsVar.size() - 1 - c; i++)
        {
            if (numsVar[i] > numsVar[i + 1])
            {
                int temp = numsVar[i];
                numsVar[i] = numsVar[i + 1];
                numsVar[i + 1] = temp;

                flag = true;
            }
        }

        c++;
    }

    for (int i = 0; i < numsVar.size() / 2; i++)
    {
        result.push_back(numsVar[i]);
        result.push_back(numsVar[numsVar.size() - 1 - i]);
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