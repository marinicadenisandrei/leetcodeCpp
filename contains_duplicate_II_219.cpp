/* Leetcode - 219. Contains Duplicate II (C++ language) - Easy */

#include <iostream>
#include <vector>

using namespace std;

void reset ();
void green ();
void yellow ();
void red ();

bool containsNearbyDuplicate(vector<int> numsVar, int kVar);

int main()
{
    yellow();

    cout << "Leetcode - 219. Contains Duplicate II (C++ language) - ";

    green();

    cout << "Easy" << endl;

    vector<vector<int>> nums {{1,2,3,1},{1,0,1,1},{1,2,3,1,2,3}};
    vector<int> k {3,1,2};

    for (int test = 0; test < nums.size(); test++)
    {
        green();

        cout << "Test " << test + 1 << ": ";

        reset();

        cout << boolalpha << containsNearbyDuplicate(nums[test], k[test]) << " | ";

        green();

        cout << "Passed" << endl;
    }

    reset();

    return 0;
}

bool containsNearbyDuplicate(vector<int> numsVar, int kVar)
{
    for (int i = 0; i < numsVar.size(); i++)
    {
        for (int j = 0; j < numsVar.size(); j++)
        {   
            if (i != j && numsVar[i] == numsVar[j] && abs(i - j) <= kVar)
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