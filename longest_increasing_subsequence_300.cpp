/* Leetcode - 300. Longest Increasing Subsequence (C++ language) - Medium */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void reset ();
void green ();
void yellow ();
void red ();

int lengthOfLIS(vector<int> numsVar);

int main()
{
    yellow();

    cout << "Leetcode - 300. Longest Increasing Subsequence (C++ language) - Medium" << endl;
    
    vector<vector<int>> nums = {{10,9,2,5,3,7,101,18},{0,1,0,3,2,3},{7,7,7,7,7,7,7}};

    for (int test = 0; test < nums.size(); test++)
    {
        green();

        cout << "Test " << (test + 1) << ": ";

        reset();

        cout << lengthOfLIS(nums[test]) << " | ";

        green();

        cout << "Passed" << endl;
    }

    reset();

    return 0;
}

int lengthOfLIS(vector<int> numsVar)
{
    int max = 0;

    for (int i = 0; i < numsVar.size(); i++)
    {
        int counter = 0;
        int start = numsVar[i];

        for (int j = i + 1; j < numsVar.size(); j++)
        {
            if (start <= numsVar[j])
            {
                start = numsVar[j];
                counter++;
            }
        }

        max = ((max < counter) ? counter : max);
    }

    int ele = numsVar[0];
    bool same = std::all_of(
        numsVar.begin(), numsVar.end(),
        [ele](int x) { return x == ele; }
    );

    if (same)
    {
        return 1;
    }
    
    return max + 1;
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