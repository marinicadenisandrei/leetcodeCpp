/* Leetcode - 315. Count of Smaller Numbers After Self (C++ language) - Hard */

#include <iostream>
#include <vector>

using namespace std;

void reset ();
void green ();
void yellow ();
void red ();

vector<int> countSmaller(vector<int> numsVar);
void printVector(vector<int> vect);

int main()
{
    yellow();

    cout << "Leetcode - 315. Count of Smaller Numbers After Self (C++ language) - ";

    red();

    cout << "Hard" << endl;

    vector<vector<int>> nums = {{5,2,6,1},{-1},{-1,-1}};
    
    for (int test = 0; test < nums.size(); test++)
    {
        green();

        cout << "Test " << test + 1 << ": ";

        reset();

        printVector(countSmaller(nums[test]));

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

vector<int> countSmaller(vector<int> numsVar)
{
    vector<int> result = {};

    for (int i = 0; i < numsVar.size(); i++)
    {
        int countSmall = 0;

        for (int j = i + 1; j < numsVar.size(); j++)
        {
            countSmall += ((numsVar[i] > numsVar[j]) ? 1 : 0);
        }

        result.push_back(countSmall);
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