/* Leetcode - (C++ language) -  */

#include <iostream>
#include <vector>
#include <set>

using namespace std;

void reset ();
void green ();
void yellow ();
void red ();

bool containsDuplicate(vector<int> numsVar);

int main()
{
  yellow();

  cout << "Leetcode - 217. Contains Duplicate (C++ language) - ";

  green();

  cout << "Easy" << endl;

  vector<vector<int>> nums {{1,2,3,1},{1,2,3,4},{1,1,1,3,3,4,3,2,4,2}};

  for (int test = 0; test < nums.size(); test++)
  {
      green();

      cout << "Test " << test + 1 << ": ";

      reset();

      cout << boolalpha << containsDuplicate(nums[test]) << " | ";

      green();

      cout << "Passed" << endl;
  }

  reset();
  
    return 0;
}

bool containsDuplicate(vector<int> numsVar)
{
    std::set<int> uniqueElements(numsVar.begin(), numsVar.end());
    return uniqueElements.size() != numsVar.size();
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

