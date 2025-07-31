/* Leetcode - 260. Single Number III (C++ language) - Medium */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void reset ();
void green ();
void yellow ();
void red ();

vector<int> singleNumber(vector<int> numsVar);
void displayVect(vector<int> vect);

int main()
{
    yellow();

    cout << "Leetcode - 260. Single Number III (C++ language) - Medium" << endl;

    vector<vector<int>> nums {{1,2,1,3,2,5},{-1,0},{0,1}};

    for (int test = 0; test < nums.size(); test++)
    {
        green();

        cout << "Test " << test + 1 << ": ";

        reset();

        displayVect(singleNumber(nums[test]));

        green();

        cout << "Passed" << endl;
    }
    
    reset();

    return 0;
}

void displayVect(vector<int> vect)
{
    for (int i = 0; i < vect.size(); i++)
    {
        cout << ((i == 0) ? "[" : "") << vect[i] << ((i < vect.size() - 1) ? ", " : "] | ");
    }
}

vector<int> singleNumber(vector<int> numsVar)
{
    vector<int> result = {};
    vector<int> noDuplicates = {};

    for (int i = 0; i < numsVar.size(); i++)
    {
        if (!(find(noDuplicates.begin(), noDuplicates.end(), numsVar[i]) != noDuplicates.end()))
        {
            noDuplicates.push_back(numsVar[i]);
        }
    }
    
    for (int i = 0; i < noDuplicates.size(); i++)
    {
        int occ = count(numsVar.begin(), numsVar.end(), noDuplicates[i]);

        if (occ == 1)
        {
            result.push_back(noDuplicates[i]);
        }
    }
    
    return result;
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