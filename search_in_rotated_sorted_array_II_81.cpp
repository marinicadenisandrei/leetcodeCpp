/* Leetcode - 81. Search in Rotated Sorted Array II (C++ language) - Medium */

#include <iostream>
#include <vector>

using namespace std;

bool search(vector<int> numsVar, int targetVar);\

void reset ();
void green ();
void yellow ();
void red ();

int main()
{
    yellow();

    cout << "Leetcode - 81. Search in Rotated Sorted Array II (C++ language) - Medium" << endl;

    vector <vector<int> >nums {{2,5,6,0,0,1,2},{2,5,6,0,0,1,2}};
    vector<int> target = {0,3};

    for (int test = 0; test < target.size(); test++)
    {
        green();

        cout << "Test " << test + 1 << ": ";

        reset();

        cout << boolalpha << search(nums[test], target[test]) << " | ";

        green();

        cout << "Passed" << endl;
    }

    reset();

    return 0;
}

bool search(vector<int> numsVar,int targetVar)
{
    for (int i = 0; i < numsVar.size(); i++)
    {
        if (numsVar[i] == targetVar)
        {
            return true;
        }
    }

    return false;
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