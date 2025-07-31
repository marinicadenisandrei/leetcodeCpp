/* Leetcode - 164. Maximum Gap (C++ language) - Medium */

#include <iostream>
#include <vector>

using namespace std;

int maximumGap(vector<int> numsVar);

void reset ();
void green ();
void yellow ();
void red ();

int main()
{
    yellow();

    cout << "Leetcode - 164. Maximum Gap (C++ language) - Medium" << endl;

    vector<vector<int>> nums {{3,6,9,1},{10}};

    for (int test = 0; test < nums.size(); test++)
    {
        green();

        cout << "Test " << test + 1 << ": ";

        reset();

        cout << maximumGap(nums[test]) << " | ";

        green();

        cout << "Passed" << endl;
    }

    reset();
}

int maximumGap(vector<int> numsVar)
{
    auto l = [] (vector<int> numsVar) {
        int max = 0;

        for (int i = 0; i < numsVar.size() - 1; i++)
        {
            if (numsVar[i] < numsVar[i + 1])
            {
                int result = abs(numsVar[i] - numsVar[i + 1]);
                max = ((result > max) ? result : max);
            }
        }
        
        return max;
    };

    return l(numsVar);
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