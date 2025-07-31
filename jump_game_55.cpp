/* Leetcode - 55. Jump Game (C++ language) - Medium */

#include <iostream>
#include <vector>

using namespace std;

bool canJump(vector <int> numsVar);

void reset ();
void green ();
void yellow ();
void red ();

int main()
{
    yellow();

    cout << "Leetcode - 55. Jump Game (C++ language) - Medium" << endl;

    vector <vector <int>> nums {{2,3,1,1,4}, {3,2,1,0,4}};

    for (int test = 0; test < nums.size(); test++)
    {
        green();

        cout << "Test " << test + 1 << ": ";

        reset();

        cout << boolalpha << canJump(nums[test]) << " | ";

        green();

        cout << "Passed" << endl;   
    }

    reset();
}

bool canJump(vector <int> numsVar)
{
    int endNumber {numsVar.back()};
    numsVar.pop_back();


    for (int i = 0; i < 2; i++)
    {
        int indexStart {numsVar[i]};

        while (indexStart < numsVar.size())
        {
            if (numsVar[indexStart] == 0)
            {
                break;
            }
            
            indexStart += numsVar[indexStart];
        }
        
        if (indexStart == endNumber)
        {
            return true;
        }
    }
    
    return false;
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