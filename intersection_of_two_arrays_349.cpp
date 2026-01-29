/* Leetcode - 349. Intersection of Two Arrays (C++ language) - Easy */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void reset ();
void green ();
void yellow ();
void red ();

vector<int> intersection(vector<int> nums1Var, vector<int> nums2Var);
void printVect(vector<int> vect);

int main()
{
    yellow();

    cout << "Leetcode - 349. Intersection of Two Arrays (C++ language) - ";

    green();

    cout << "Easy" << endl;

    vector<vector<int>> nums1 = {{1,2,2,1},{4,9,5}};
    vector<vector<int>> nums2 = {{2,2},{9,4,9,8,4}};

    for (int test = 0; test < nums1.size(); test++)
    {
        green();

        cout << "Test " << test + 1 << ": ";

        reset();

        printVect(intersection(nums1[test], nums2[test]));
        
        green();

        cout << "Passed" << endl;
    }

    reset();

    return 0;
}

void printVect(vector<int> vect)
{
    if (vect.size() == 0)
    {
        cout << "[] | ";
        return;
    }

    for (int i = 0; i < vect.size(); i++)
    {
        cout << ((i == 0) ? "[" : "") << vect[i] << ((i < vect.size() - 1) ? ", " : "] | ");   
    }
}

vector<int> intersection(vector<int> nums1Var, vector<int> nums2Var)
{
    vector<int> big;
    vector<int> small;
    vector<int> result = {};

    if (nums1Var.size() > nums2Var.size())
    {
        big = nums1Var;
        small = nums2Var;
    }
    else
    {
        big = nums2Var;
        small = nums1Var;
    }
    
    int it1 = 0;
    int it2 = 0;

    while (it1 < (int)big.size() && it2 < (int)small.size())
    {
        if (big[it1] == small[it2])
        {
            result.push_back(big[it1]);
            it1++;
            it2++;
        }
        else
        {
            it1++;
        }
    }

    std::sort(result.begin(), result.end());
    result.erase(std::unique(result.begin(), result.end()), result.end());

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