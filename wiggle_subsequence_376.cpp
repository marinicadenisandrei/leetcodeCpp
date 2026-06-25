/* Leetcode - 376. Wiggle Subsequence (C++ language) - Medium */

#include <iostream>
#include <vector>

using namespace std;

void reset ();
void green ();
void yellow ();
void red ();

int wiggleMaxLength(vector<int> numsVar);

int main()
{
    yellow();

    cout << "Leetcode - 376. Wiggle Subsequence (C++ language) - Medium\n";

    vector<vector<int>> nums = {{1,7,4,9,2,5},{1,17,5,10,13,15,10,5,16,8},{1,2,3,4,5,6,7,8,9}};
    
    for (int test = 0; test < nums.size(); test++)
    {
        green();

        cout << "Test " << (test + 1) << ": ";

        reset();

        cout << wiggleMaxLength(nums[test]) << " | ";

        green();

        cout << "Passed" << endl;
    }

    reset();

    return 0;
}

int wiggleMaxLength(vector<int> numsVar)
{
    vector<int> diffs = {};

    for (int i = 0; i < numsVar.size() - 1; i++)
    {
        diffs.push_back(numsVar[i] - numsVar[i + 1]);
    }
    
    int index1 = 0;
    int index2 = 1;
    int counter = 0;

    for (int i = 0; i < diffs.size() - 1; i++)
    {
        if (diffs[i] * diffs[i + 1] < 0)
        {
            counter++;
        }        
    }
    

    return counter + 2;
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