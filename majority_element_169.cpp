/* Leetcode - 169. Majority Element (C++ lanhuage) - Easy */

#include <iostream>
#include <vector>

using namespace std;

int majorityElement(vector<int> numsVar);

void reset ();
void green ();
void yellow ();
void red ();

int main()
{
    yellow();

    cout << "Leetcode - 169. Majority Element (C++ lanhuage) - ";

    green();

    cout << "Easy" << endl;

    vector<vector<int>> nums {{3,2,3},{2,2,1,1,1,2,2}};

    for (int test = 0; test < nums.size(); test++)
    {
        green();
        
        cout << "Test " << test + 1 << ": ";

        reset();

        cout << majorityElement(nums[test]) << " | ";

        green();

        cout << "Passed" << endl;
    }

    reset();
}

int majorityElement(vector<int> numsVar)
{
    int maxVar = 0;
    int number = 0;

    for (int i = 0; i < numsVar.size(); i++)
    {
        int counter = 0;

        for (int j = 0; j < numsVar.size(); j++)
        {
            if (i != j && numsVar[i] == numsVar[j])
            {
                counter++;   
            }
        }

        if (maxVar < counter)
        {
            maxVar = counter;
            number = numsVar[i];
        }
    }

    return number;
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
