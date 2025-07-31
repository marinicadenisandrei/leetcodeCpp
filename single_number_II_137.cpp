/* Leetcode - 137. Single Number II (C++ language) - Medium */

#include <iostream>
#include <vector>

using namespace std;

int singleNumber(vector<int> numsVar);

void reset ();
void green ();
void yellow ();
void red ();

int main()
{
    yellow();

    cout << "Leetcode - 137. Single Number II (C++ language) - Medium" << endl;

    vector<vector<int>> nums {{2,2,3,2},{0,1,0,1,0,1,99}};

    for (int test = 0; test < nums.size(); test++)
    {
        green();

        cout << "Test " << test + 1 << ": ";

        reset();

        cout << singleNumber(nums[test]) << " | ";

        green();

        cout << "Passed" << endl;
    }

    reset();
}

int singleNumber(vector<int> numsVar)
{
    auto l = [] (vector<int> numsVar) {
        for (int i = 0; i < numsVar.size(); i++)
        {
            int count = 0;

            for (int j = 0; j < numsVar.size(); j++)
            {
                if (i != j && numsVar[i] == numsVar[j])
                {
                    count++;
                }
            }

            if (count == 0)
            {
                return numsVar[i];
            }
        }

        return -1;
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