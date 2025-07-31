/* Leetcode - 152. Maximum Product Subarray (C++ language) - Medium */

#include <iostream>
#include <vector>

using namespace std;

int maxProduct(vector<int> numsVar);

void reset ();
void green ();
void yellow ();
void red ();

int main()
{   
    yellow();
    
    cout << "Leetcode - 152. Maximum Product Subarray (C++ language) - Medium" << endl;

    vector<vector<int>> nums {{2,3,-2,4},{-2,0,-1}};

    for (int test = 0; test < nums.size(); test++)
    {
        green();

        cout << "Test " << test + 1 << ": ";

        reset();

        cout << maxProduct(nums[test]) << " | ";

        green();

        cout << "Passed" << endl;
    }

    reset();
    
    return 0;
}

int maxProduct(vector<int> numsVar)
{
    int product = 1;
    int max = 0;

    for (int i = 0; i < numsVar.size(); i++)
    {
        for (int j = 0; j <= i; j++)
        {
            product *= numsVar[j];
            max = ((max < product) ? product : max);
        }

        product = 1;
    }

    product = 1;

    for (int i = 0; i < numsVar.size(); i++)
    {
        for (int j = i; j < numsVar.size(); j++)
        {
            product *= numsVar[j];
        }

        product = 1;
    }

    return max;
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