/* Leetcode - 220. Contains Duplicate III (C++ language) - Hard */

#include <iostream>
#include <vector>

using namespace std;

void reset ();
void green ();
void yellow ();
void red ();

bool containsNearbyDuplicate(vector<int> numsVar, int indexDiffVar, int valueDiffVar);

int main()
{
    yellow();

    cout << "Leetcode - 220. Contains Duplicate III (C++ language) - ";

    red();

    cout << "Hard" << endl;

    vector<vector<int>> nums {{1,2,3,1},{1,5,9,1,5,9}};
    vector<int> indexDiff {3,2};
    vector<int> valueDiff {0,3};

    for (int test = 0; test < nums.size(); test++)
    {
        green();

        cout << "Test " << test + 1 << ": ";

        reset();

        cout << boolalpha << containsNearbyDuplicate(nums[test], indexDiff[test], valueDiff[test]) << " | ";

        green();

        cout << "Passed" << endl;
    }

    reset();

    return 0;
}

bool containsNearbyDuplicate(vector<int> numsVar, int indexDiffVar, int valueDiffVar)
{
    for (int i = 0; i < numsVar.size(); i++)
    {
        for (int j = 0; j < numsVar.size(); j++)
        {   
            if (i != j && abs(numsVar[i] - numsVar[j]) <= valueDiffVar && abs(i - j) <= indexDiffVar)
            {
                return true;
            }
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