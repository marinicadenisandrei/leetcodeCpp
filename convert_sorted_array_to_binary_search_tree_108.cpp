/* Leetcode - 108. Convert Sorted Array to Binary Search Tree (C++ language) - Easy */

#include <iostream>
#include <vector>

using namespace std;

vector<int> sortedArrayToBST(vector<int> numsVar);
void printArray(vector<int> vectorVar);

void reset ();
void green ();
void yellow ();
void red ();

int main()
{
    yellow();

    cout << "Leetcode - 108. Convert Sorted Array to Binary Search Tree (C++ language) -";

    green();

    cout << "Easy" << endl;

    vector<vector<int>> nums {{-10,-3,0,5,9},{1,3}};

    for (int test = 0; test < nums.size(); test++)
    {
        green();

        cout << "Test " << test + 1 << ": ";

        reset();

        vector<int> result = sortedArrayToBST(nums[test]);
        printArray(result);

        green();

        cout << "Passed" << endl;
    }

    reset();

    return 0;
}

void printArray(vector<int> vectorVar)
{
    for (int i = 0; i < vectorVar.size(); i++)
    {
        cout << ((i == 0) ? "[" : "") << vectorVar[i] << ((i < vectorVar.size() - 1) ? ", " : "]");
    }

    cout << " | ";
}

vector<int> sortedArrayToBST(vector<int> numsVar)
{
    vector<int> root {};
    int len = numsVar.size();
    int middle = len / 2;
    root.push_back(numsVar[middle]);

    for (int i = 0; i < middle; i++)
    {
        root.push_back(numsVar[middle - 1 - i]);

        if (middle - 2 - i < 0)
        {
            root.push_back(0);
        }
        
        root.push_back(numsVar[len - 1 - i]);
    }
    
    if (numsVar.size() % 2 == 0)
    {
        root.erase(root.begin());
    }
    
    return root;
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