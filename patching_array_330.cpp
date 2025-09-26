/* Leetcode - 330. Patching Array (C++ language) - Hard */

#include <iostream>
#include <vector>

using namespace std;

void reset ();
void green ();
void yellow ();
void red ();

int minPatches(vector<int> numsVar, int nVar);

int main()
{
    yellow();

    cout << "Leetcode - 330. Patching Array (C++ language) - ";

    red();

    cout << "Hard" << endl;

    vector<vector<int>> nums = {{1,3},{1,5,10},{1,2,2}};
    vector<int> n = {6,20,5};

    for (int test = 0; test < nums.size(); test++)
    {
        green();

        cout << "Test " << test + 1 << ": ";

        reset();

        cout << minPatches(nums[test], n[test]) << " | ";

        green();

        cout << "Passed" << endl;
    }

    reset();

    return 0;
}

int minPatches(vector<int> numsVar, int nVar)
{
    long long miss = 1;
    int patches = 0;
    int i = 0;

    while (miss <= nVar)
    {
        if (i < numsVar.size() && numsVar[i] <= miss)
        {
            miss += numsVar[i];
            i++;
        }
        else
        {
            patches++;
            miss += miss;
        }
    }

    return patches;
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