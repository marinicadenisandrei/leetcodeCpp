/* Leetcode - 283. Move Zeroes (C++ language) - Easy */

#include <iostream>
#include <vector>

using namespace std;

void reset ();
void green ();
void yellow ();
void red ();

void moveZeroes(vector<int> &numsVar);
void printVector(vector<int> vect);

int main()
{
    yellow();
    
    cout << "Leetcode - 283. Move Zeroes (C++ language) - ";

    green();

    cout << "Easy" << endl;

    vector<vector<int>> nums = {{0,1,0,3,12},{0}};
    
    for (int test = 0; test < nums.size(); test++)
    {
        green();

        cout << "Test " << test + 1 << ": ";
        
        reset();

        moveZeroes(nums[test]);
        printVector(nums[test]);

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

void moveZeroes(vector<int> &numsVar)
{
    int zeroes = 0;

    for (int i = 0; i < numsVar.size(); i++)
    {
        if (numsVar[i] == 0)
        {
            numsVar.erase(numsVar.begin() + i);
            i--;
            zeroes++;
        }
    }

    while (zeroes > 0)
    {
        numsVar.push_back(0);
        zeroes--;
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