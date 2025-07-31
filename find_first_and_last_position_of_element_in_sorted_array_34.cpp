/* Leetcode - 34. Find First and Last Position of Element in Sorted Array (C++ language) - Medium */

#include <iostream>
#include <vector>

using namespace std;

vector<int> searchRange(vector<int> &nums, int target);
void printVector(const vector <int> vectorVar);

void reset ();
void green ();
void yellow ();
void red ();

int main()
{
    yellow();

    cout << "Leetcode - 34. Find First and Last Position of Element in Sorted Array (C++ language) - Medium" << endl;

    vector <vector <int>> nums {{5, 7, 7, 8, 8, 10}, {5, 7, 7, 8, 8, 10}, {}};
    vector <int> target {8,6,0};

    for (int test = 0; test < nums.size(); test++)
    {
        vector<int> result {searchRange(nums.at(test), target.at(test))};

        green();

        cout << "Test " << test + 1 << ": ";

        reset();

        printVector(result);

        green();

        cout << "Passed" << endl;
    }

    reset();
    
    return 0;
}

vector<int> searchRange(vector<int> &nums, int target)
{
    vector<int> output{-1, -1}; 

    for (int i = 0; i < nums.size(); i++)
    {
        if (nums.at(i) == target)
        {
            output[0] = i; 
            break; 
        }
    }

    for (int i = nums.size() - 1; i >= 0; i--)
    {
        if (nums.at(i) == target)
        {
            output[1] = i; 
            break; 
        }
    }

    return output;
}

void printVector(const vector <int> vectorVar)
{
    for (int i = 0; i < vectorVar.size(); i++)
    {
        cout << ((i == 0 ) ? "[" : "") << vectorVar.at(i) << ((i < vectorVar.size() - 1) ? ", " : "] | ");
    }
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
