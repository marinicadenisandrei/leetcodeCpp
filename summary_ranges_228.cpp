/* Leetcode - 228. Summary Ranges (C++ language) - Easy */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

void reset ();
void green ();
void yellow ();
void red ();

vector<string> SummaryRanges(vector<int> numsVar);
void printVector(vector<string> vect);

int main()
{   
    yellow();

    cout << "Leetcode - 228. Summary Ranges (C++ language) - ";

    green();

    cout << "Easy" << endl;

    vector<vector<int>> nums {{0,1,2,4,5,7},{0,2,3,4,6,8,9}};
    
    for (int test = 0; test < nums.size(); test++)
    {
        green();

        cout << "Test " << test + 1 << ": ";

        reset();

        printVector(SummaryRanges(nums[test]));

        green();

        cout << "Passed" << endl;
    }

    reset();

    return 0;
}

void printVector(vector<string> vect)
{
    for (int i = 0; i < vect.size(); i++)
    {
        cout << ((i == 0) ? "[" : "") << vect[i] << ((i < vect.size() - 1) ? ", " : "] | ");
    }
}

vector<string> SummaryRanges(vector<int> numsVar)
{
    int start = numsVar[0];
    vector<string> rangesResult = {};

    for (int i = 0; i < numsVar.size() - 1; i++)
    {
        if (numsVar[i + 1] - numsVar[i] > 1)
        {
            string result = to_string(start) + "->" + to_string(numsVar[i]);
            rangesResult.push_back(result);

            start = numsVar[i + 1];   
        }   
    }

    string result = to_string(start) + "->" + to_string(numsVar[numsVar.size() - 1]);
    rangesResult.push_back(result);

    return rangesResult;
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