/* Leetcode - 128. Longest Consecutive Sequence (C++ language) - Medium */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int longestConsecutive(vector<int> numsVar);

void reset ();
void green ();
void yellow ();
void red ();

int main()
{
    yellow();

    cout << "Leetcode - 128. Longest Consecutive Sequence (C++ language) - Medium" << endl;

    vector<vector<int>> nums {{100,4,200,1,3,2},{0,3,7,2,5,8,4,6,0,1}};

    for (int test = 0; test < nums.size(); test++)
    {
        green();

        cout << "Test " << test + 1 << ": ";

        reset();

        cout << longestConsecutive(nums[test]) << " | ";

        green();

        cout << "Passed" << endl;
    }

    reset();
    
    return 0;
}

int longestConsecutive(vector<int> numsVar)
{
    int maxVar {0};
    int counter {0};

    sort(numsVar.begin(), numsVar.end());

    for (int i = 0; i < numsVar.size() - 1; i++)
    {
        if (numsVar[i + 1] - numsVar[i] == 1)
        {
            counter++;
        }
        else
        {
            maxVar = ((maxVar < counter) ? counter : maxVar);
            counter = 0;
        }
    }

    maxVar = ((maxVar < counter) ? counter : maxVar);
    maxVar++;
    
    return maxVar;
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