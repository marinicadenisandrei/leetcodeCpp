/* Leetcode - 312. Burst Balloons (C++ language) - Hard */

#include <iostream>
#include <vector>

using namespace std;

void reset ();
void green ();
void yellow ();
void red ();

int burstBalloons(vector<int> numsVar);

int main()
{
    yellow();

    cout << "Leetcode - 312. Burst Balloons (C++ language) - ";

    red();

    cout << "Hard" << endl;

    vector<vector<int>> nums = {{3, 1, 5, 8}, {1, 5}};
    
    for (int test = 0; test < nums.size(); test++)
    {
        green();

        cout << "Test " << test + 1 << ": ";

        reset();

        cout << burstBalloons(nums[test]) << " | ";

        green();

        cout << "Passed" << endl;
    }

    reset();
    
    return 0;
}

int burstBalloons(vector<int> numsVar)
{
    int sum = 0;

    while (numsVar.size() > 0)
    {
        if (numsVar.size() >= 3)
        {
            sum += numsVar[0] * numsVar[1] * numsVar[2];
            numsVar.erase(numsVar.begin() + 1); 
        }
        else if(numsVar.size() == 2)
        {
            sum += numsVar[0] * numsVar[1];
            numsVar.erase(numsVar.begin()); 
        }
        else if (numsVar.size() == 1)
        {
            sum += numsVar[0];
            numsVar.erase(numsVar.begin());
        }
    }

    return sum;
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