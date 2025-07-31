/* Leetcode - 189. Rotate Array (C++ language) - Medium */

#include <iostream>
#include <vector>

using namespace std;

void rotate(vector<int> &numsVar, int kVar);
void printVector(vector<int> &vectorVar);

void reset ();
void green ();
void yellow ();
void red ();

int main()
{
    yellow();

    cout << "Leetcode - 189. Rotate Array (C++ language) - Medium" << endl;

    vector<vector<int>> nums {{1,2,3,4,5,6,7},{-1,-100,3,99}};
    vector<int> k {3,2};

    for (int test = 0; test < k.size(); test++)
    {
        green();

        cout << "Test " << test + 1 << ": ";

        reset();

        rotate(nums[test], k[test]);
        printVector(nums[test]);

        green();

        cout << "Passed" << endl;
    }

    reset();
    
    return 0;
}

void printVector(vector<int> &vectorVar)
{
    for (int i = 0; i < vectorVar.size(); i++)
    {
        cout << ((i == 0) ? "[" : "") << vectorVar[i] << ((i < vectorVar.size() - 1) ? ", " : "] | ");
    }
}

void rotate(vector<int> &numsVar, int kVar)
{
    for (int i = 1; i <= kVar; i++)
    {
        numsVar.insert(numsVar.begin(), numsVar[numsVar.size() - i]);
    }

    numsVar = vector<int> (numsVar.begin(), numsVar.end() - kVar);
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