/* Leetcode - 80. Remove Duplicates from Sorted Array II (C++ language) - Medium */

#include <iostream>
#include <vector>

using namespace std;

void removeDuplicates(vector <int> &numsVar);
void printVector(vector <int> vectorVar);

void reset ();
void green ();
void yellow ();
void red ();

int main()
{
    yellow();

    cout << "Leetcode - 80. Remove Duplicates from Sorted Array II (C++ language) - Medium" << endl;

    vector <vector <int>> nums {{1,1,1,2,2,3},{0,0,1,1,1,1,2,3,3}};

    for (int test = 0; test < nums.size(); test++)
    {
        green();

        cout << "Test " << test + 1 << ": ";

        reset();

        removeDuplicates(nums[test]);
        printVector(nums[test]);

        green();

        cout << "Passed" << endl;
    }

    reset();
    
    return 0;
}

void removeDuplicates(vector <int> &numsVar)
{
    for (int i = 0; i < numsVar.size(); i++)
    {
        int counter {0};

        for (int j = 0; j < numsVar.size(); j++)
        {
            if (numsVar[i] == numsVar[j])
            {
                counter++;
            }
        }

        if (counter > 2)
        {
            numsVar.erase(numsVar.begin() + i);
        }
    }
}

void printVector(vector <int> vectorVar)
{
    for (int i = 0; i < vectorVar.size(); i++)
    {
        cout << ((i == 0) ? "[" : "") << vectorVar[i] << ((i < vectorVar.size() - 1) ? ", " : "]");
    }

    cout << " | ";
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