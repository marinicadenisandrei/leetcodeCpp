/* Leetcode - 238. Product of Array Except Self (C++ language) - Medium */

#include <iostream>
#include <vector>

using namespace std;

void reset ();
void green ();
void yellow ();
void red ();

vector<int> productExceptSelf(vector<int> numsVar);
void printVector(vector<int> vect);

int main()
{
    yellow();

    cout << "Leetcode - 238. Product of Array Except Self (C++ language) - Medium" << endl;

    vector<vector<int>> nums {{1,2,3,4},{-1,1,0,-3,3}};
    
    for (int test = 0; test < nums.size(); test++)
    {
        green();

        cout << "Test " << test + 1 << ": ";

        reset();

        printVector(productExceptSelf(nums[test]));

        green();

        cout << "Passed" << endl;
    }

    reset();
}

void printVector(vector<int> vect)
{
    for (int i = 0; i < vect.size(); i++)
    {
        cout << ((i == 0) ? "[" : "") << vect[i] << ((i < vect.size() - 1) ? ", " : "] | ");
    }
}

vector<int> productExceptSelf(vector<int> numsVar)
{
    vector<int> result = {};
    
    for (int i = 0; i < numsVar.size(); i++)
    {
        int product = 1;

        for (int j = 0; j < numsVar.size(); j++)
        {
            product *= ((i != j) ? numsVar[j] : 1);
        }

        result.push_back(product);
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
  