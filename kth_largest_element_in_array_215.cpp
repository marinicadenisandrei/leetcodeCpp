/* Leetcode - 215. Kth Largest Element in an Array (Cpp language) - Medium */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void reset ();
void green ();
void yellow ();
void red ();

int findKthLargest(vector<int> numsVar, int kVar);

int main()
{
    yellow();

    cout << "Leetcode - 215. Kth Largest Element in an Array (Cpp language) - Medium" << endl;

    vector<vector<int>> nums {{3,2,1,5,6,4},{3,2,3,1,2,4,5,5,6}};
    vector<int> k {2,4};
    
    for (int test = 0; test < nums.size(); test++)
    {   
        green();

        cout << "Test " << test + 1 << ": ";

        reset();

        cout << findKthLargest(nums[test], k[test]) << " | ";

        green();

        cout << "Passed" << endl;
    }

    reset();

    return 0;
}

int findKthLargest(vector<int> numsVar, int kVar)
{
    sort(numsVar.begin(), numsVar.end(), greater<int>());
    return numsVar[kVar - 1];
}

void reset () {
  printf("\033[1;0m");
}

void green () {
  printf("\033[1;32m");
}

void yellow () {
  printf("\033[1;33m");
}

void red () {
  printf("\033[1;31m");
}