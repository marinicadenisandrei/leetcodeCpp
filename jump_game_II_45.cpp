/* Leetcode - 45. Jump Game II (C++ language) - Medium */

#include <iostream>
#include <vector>

using namespace std;

int jump(vector <int> numsVar);
int minimumBetweenTwoNumbers(int num1, int num2);

void reset ();
void green ();
void yellow ();
void red ();

int main()
{
    yellow();

    cout << "Leetcode - 45. Jump Game II (C++ language) - Medium" << endl;

    vector <vector <int>> nums {{2,3,1,1,4}, {2,3,0,1,4}};

    for (int test = 0; test < nums.size(); test++)
    {
        green();

        cout << "Test " << test + 1 << ": ";

        reset();

        int result = jump(nums[test]);
        cout << result << " | ";

        green();

        cout << "Passed" << endl;
    }

    reset();

    return 0;
}

int minimumBetweenTwoNumbers(int num1, int num2)
{
    if (num1 > num2 && num2 != -1) return num2;

    if (num1 < num2 && num1 != -1) return num1;
    
    if (num1 == -1)
    {
        return num2;
    }
    else
    {
        return num1;
    }
}

int jump(vector <int> numsVar)
{
    vector <int> jumps {};

    for (int i = 0; i < 2; i++)
    {
        int noJumps {0};

        for (int j = i; j < numsVar.size(); j += numsVar[j])
        {
            noJumps += 1;    

            if (numsVar[j] == numsVar[numsVar.size() - 1])
            {
                jumps.push_back(noJumps);
                break;
            }

            if (numsVar[j] == 0 && j < numsVar.size() - 1)
            {
                jumps.push_back(-1);
                break;
            }
        }
    }

    return minimumBetweenTwoNumbers(jumps[0], jumps[1]);
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