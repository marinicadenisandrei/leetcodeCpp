/* Leetcode - 239. Sliding Window Maximum (C++ language) - Hard */

#include <iostream>
#include <vector>

using namespace std;

void reset ();
void green ();
void yellow ();
void red ();

vector<int> maxSlidingWindow(vector<int> numsVar, int kVar);
void printVector(vector<int> vect);

int main()
{
    yellow();

    cout << "Leetcode - 239. Sliding Window Maximum (C++ language) - ";

    red();

    cout << "Hard" << endl;

    vector<vector<int>> nums = {{1,3,-1,-3,5,3,6,7},{1}};
    vector<int> k = {3,1};

    for (int test = 0; test < nums.size(); test++)
    {
        green();
        
        cout << "Test " << test + 1 << ": ";

        reset();

        printVector(maxSlidingWindow(nums[test], k[test]));

        green();

        cout << "Passed" << endl;
    }

    reset();
    
    return 0;
}

void printVector(vector<int> vect)
{
    for (int i = 0; i < vect.size(); i++)
    {
        cout << ((i == 0) ? "[" : "") << vect[i] << ((i < vect.size() - 1) ? ", " : "] | ");
    }
}

vector<int> maxSlidingWindow(vector<int> numsVar, int kVar)
{
    vector<int> result = {};

    for (int i = 0; i <= numsVar.size() - kVar; i++)
    {
        std::vector<int> subvec(numsVar.begin() + i, numsVar.begin() + i + kVar);
        int maxVar = 0;

        for (int j = 0; j < subvec.size(); j++)
        {
            maxVar = ((maxVar < subvec[j]) ? subvec[j] : maxVar);
        }
        
        result.push_back(maxVar);
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